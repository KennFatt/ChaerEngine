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
    int on_init;
    int on_destroy;
    float on_update;
    float on_draw;
} CE_State;

/**
 * StageManager struct.
 */
typedef struct
{
    CE_State **stack;
    int capacity;
    int top_stack;
} CE_StageManager;

#endif