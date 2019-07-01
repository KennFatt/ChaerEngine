#ifndef CE_STATEMANAGER_H
#define CE_STATEMANAGER_H

/**
 * State's callback.
 */
typedef unsigned int (*i_callback_t)();
typedef unsigned int (*fl_callback_t)(float);

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
int ce_statemanager_init(ce_StateManager *stage_mgr, int capacity);
int ce_statemanager_scale(ce_StateManager *stage_mgr);
int ce_statemanager_destroy(ce_StateManager *stage_mgr);
int ce_statemanager_update(ce_StateManager *stage_mgr, float dt);
int ce_statemanager_draw(ce_StateManager *stage_mgr, float dt);
ce_State *ce_statemanager_get_state(ce_StateManager *stage_mgr);

#endif