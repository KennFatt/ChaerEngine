#ifndef CE_STATEMANAGER_H
#define CE_STATEMANAGER_H

/**
 * State's callback.
 */
typedef unsigned int (*i_callback)();
typedef unsigned int (*fl_callback)(float);

/**
 * State struct.
 */
typedef struct
{
    int onInit;
    int onDestroy;
    float onUpdate;
    float onDraw;
} State;

/**
 * StageManager struct.
 */
typedef struct
{
    State **stack;
    int capacity;
    int currentStack;
} StageManager;

#endif