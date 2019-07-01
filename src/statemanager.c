#include <stdlib.h>
#include "statemanager.h"

int ce_statemanager_init(ce_StateManager *stage_mgr, int capacity)
{
    stage_mgr->capacity = capacity;
    stage_mgr->stack = malloc(capacity * sizeof(ce_State*));
    stage_mgr->ts_index = -1;
    return 0;
}

int ce_statemanager_scale(ce_StateManager *stage_mgr)
{
    stage_mgr->capacity <<= 1;
    stage_mgr->stack = realloc(stage_mgr->stack, stage_mgr->capacity * sizeof(ce_State*));
    return 0;
}

ce_State *ce_statemanager_get_state(ce_StateManager *stage_mgr)
{
    return stage_mgr->stack[stage_mgr->ts_index];
}