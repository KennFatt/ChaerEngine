#include <stdio.h>
#include "unittest.h"
#include "src/statemanager.h"

unsigned int onInitCallback(ce_State *state)
{
    printf("[#%d] Initialized!\n", state->state_id);
    return 0;
}

unsigned int dummyOnInit(ce_State *state)
{
    printf("[#%d] Initialized!\n", state->state_id);
    return 0;
}

unsigned int ce_unittest_run()
{
    ce_StateManager mgr = {0};
    ce_StateManager *mgr_p = &mgr;
    ce_statemanager_init(mgr_p, 1);

    ce_State test_state = {0};
    ce_State *st_p = &test_state;
    st_p->on_init = onInitCallback;
    ce_statemanager_add_state(mgr_p, st_p);

    ce_State dummy_state = {0};
    ce_State *dm_p = &dummy_state;
    dm_p->on_init = dummyOnInit;
    ce_statemanager_add_state(mgr_p, dm_p);
    return 0;
}