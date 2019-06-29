#include <stdlib.h>
#include "statemanager.h"

int ce_stagemanager_init(CE_STAGEMANAGER *stage_mgr, int capacity)
{
    stage_mgr->capacity = capacity;
    stage_mgr->stack = malloc(capacity * sizeof(CE_STATE*));
    stage_mgr->top_stack = -1;
    return 0;
}

int ce_stagemanager_scale(CE_STAGEMANAGER *stage_mgr)
{
    stage_mgr->capacity <<= 1;
    stage_mgr->stack = realloc(stage_mgr->stack, stage_mgr->capacity * sizeof(CE_STATE*));
    return 0;
}