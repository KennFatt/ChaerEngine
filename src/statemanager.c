#include <stdlib.h>
#include "statemanager.h"

int ce_statemanager_init(ce_StateManager *sm, int capacity)
{
    sm->capacity = capacity;
    sm->stack = malloc(capacity * sizeof(ce_State*));
    sm->ts_index = -1;
    return 0;
}

int ce_statemanager_scale(ce_StateManager *sm)
{
    sm->capacity <<= 1;
    sm->stack = realloc(sm->stack, sm->capacity * sizeof(ce_State*));
    return 0;
}

ce_State *ce_statemanager_get_state(ce_StateManager *sm)
{
    return sm->stack[sm->ts_index];
}