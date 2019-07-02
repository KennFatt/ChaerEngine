#include <stdlib.h>
#include "statemanager.h"

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

int ce_statemanager_init(ce_StateManager *sm, int capacity)
{
    sm->capacity = capacity;
    sm->stack = malloc(capacity * sizeof(ce_State*));
    sm->ts_index = -1;
    return 0;
}

ce_State *ce_statemanager_get_state(ce_StateManager *sm)
{
    return sm->ts_index > -1 ? sm->stack[sm->ts_index] : NULL;
}

ce_State *ce_statemanager_get_state_by_id(ce_StateManager *sm, int index)
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

ce_State *ce_statemanager_add_state(ce_StateManager *sm, ce_State *st)
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