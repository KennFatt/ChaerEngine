#include <stdio.h>
#include "unittest.h"
#include "src/statemanager.h"

unsigned int ce_unittest_run()
{
    CE_STAGEMANAGER stagemgr;
    CE_STAGEMANAGER *stagemgr_ptr = &stagemgr;

    ce_stagemanager_init(stagemgr_ptr, 1);
    printf("CE_STAGEMANAGER ptr: (%p)\n CE_STAGEMANAGER capacity: (%d)\n  CE_STAGEMANAGER ts_index: (%d)\n", stagemgr_ptr, stagemgr_ptr->capacity, stagemgr_ptr->ts_index);

    ce_stagemanager_scale(stagemgr_ptr);
    printf("CE_STAGEMANAGER ptr: (%p)\n CE_STAGEMANAGER capacity: (%d)\n  CE_STAGEMANAGER ts_index: (%d)\n", stagemgr_ptr, stagemgr_ptr->capacity, stagemgr_ptr->ts_index);

    ce_stagemanager_scale(stagemgr_ptr);
    printf("CE_STAGEMANAGER ptr: (%p)\n CE_STAGEMANAGER capacity: (%d)\n  CE_STAGEMANAGER ts_index: (%d)\n", stagemgr_ptr, stagemgr_ptr->capacity, stagemgr_ptr->ts_index);
    return 0;
}