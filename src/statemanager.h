#ifndef CE_STATEMANAGER_H
#define CE_STATEMANAGER_H

/**
 * State's callback.
 */
typedef unsigned int (*i_callback_t)(void *);
typedef unsigned int (*fl_callback_t)(void *, float);

/**
 * State struct.
 */
typedef struct
{
    unsigned int state_id;
    i_callback_t on_init;
    i_callback_t on_destroy;
    fl_callback_t on_update;
    fl_callback_t on_draw;
} ce_State;

/**
 * StageManager struct.
 */
typedef struct
{
    ce_State **stack;
    int capacity;
    int ts_index;
} ce_StateManager;

/**
 * StageManager interface.
 */
int ce_statemanager_init(ce_StateManager *sm, int capacity);
int ce_statemanager_destroy(ce_StateManager *sm);
int ce_statemanager_update(ce_StateManager *sm, float dt);
int ce_statemanager_draw(ce_StateManager *sm, float dt);

ce_State *ce_statemanager_state_get(ce_StateManager *sm);
ce_State *ce_statemanager_state_get_by_id(ce_StateManager *sm, int index);
ce_State *ce_statemanager_state_add(ce_StateManager *sm, ce_State *st);
ce_State *ce_statemanager_state_pop(ce_StateManager *sm);

#endif