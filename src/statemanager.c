#include <stdlib.h>
#include "statemanager.h"

// ---------------------------------------------------------------------------
unsigned int is_stack_full(ce_StateManager *sm)
{
    return sm->ts_index + 1 == sm->capacity;
}

unsigned int multiple_stack(ce_StateManager *sm)
{
    sm->capacity <<= 1;
    sm->stack = realloc(sm->stack, sm->capacity * sizeof(ce_State*));
    return 1;
}

unsigned int clean_state(ce_State *state)
{
    state->state_id = -1;
    state->on_init = NULL;
    state->on_update = NULL;
    state->on_draw = NULL;
    state->on_destroy = NULL;
    return 0;
}
// ---------------------------------------------------------------------------

int ce_statemanager_init(ce_StateManager *sm, int capacity)
{
    sm->capacity = capacity;
    sm->stack = malloc(capacity * sizeof(ce_State*));
    sm->ts_index = -1;
    return 0;
}

int ce_statemanager_destroy(ce_StateManager *sm)
{
    if (sm->ts_index > -1) {
        // Destroy all the states from the top.
        for (int i = sm->ts_index; i > -1; --i) {
            ce_State *state = sm->stack[i];
            if (state->on_destroy != NULL) {
                state->on_destroy(state);
            }

            clean_state(state);
        }
    }

    sm->ts_index = -1;
    sm->capacity = 0;
    free(sm->stack);
    return 0;
}

int ce_statemanager_update(ce_StateManager *sm, float dt)
{
    ce_State *top_state = ce_statemanager_state_get(sm);
    if (top_state->on_update != NULL) {
        top_state->on_update(top_state, dt);
        return 1;
    }

    return 0;
}

int ce_statemanager_draw(ce_StateManager *sm, float dt)
{
    ce_State *top_state = ce_statemanager_state_get(sm);
    if (top_state->on_draw != NULL) {
        top_state->on_draw(top_state, dt);
        return 1;
    }

    return 0;
}

ce_State *ce_statemanager_state_get(ce_StateManager *sm)
{
    return sm->ts_index > -1 ? sm->stack[sm->ts_index] : NULL;
}

ce_State *ce_statemanager_state_get_by_id(ce_StateManager *sm, int index)
{
    for (int i = 0; i < (sm->ts_index + 1); ++i)
    {
        ce_State *selected_state = sm->stack[i];
        if (selected_state->state_id == index) {
            return selected_state;
        }
    }
    return NULL;
}

ce_State *ce_statemanager_state_add(ce_StateManager *sm, ce_State *st)
{
    if (is_stack_full(sm)) {
        multiple_stack(sm);
    }

    sm->stack[++sm->ts_index] = st;
    st->state_id = sm->ts_index;
    if (st->on_init != NULL) {
        st->on_init(st);
    }
    return st;
}

ce_State *ce_statemanager_state_pop(ce_StateManager *sm)
{
    if (sm->ts_index == 0) {
        return NULL;
    }

    ce_State *state = ce_statemanager_state_get(sm);
    if (state != NULL) {
        if (state->on_destroy != NULL) {
            state->on_destroy(state);
        }

        clean_state(state);
        sm->stack[sm->ts_index] = NULL;
        return ce_statemanager_state_get_by_id(sm, --sm->ts_index);
    }
    return NULL; // this condition is never reached.
}