#include <stdio.h>
#include "unittest.h"

int main(int argc, char **argv)
{
    int app_st = 0;
    char *build_id = argc == 2 ? argv[1] : "NaN";

    // run the unit test.
    unsigned int test_res = ce_ut_simulate();
    if (test_res > 0) {
        app_st = (int) test_res;
    }

    printf("[#%s] Program closed with app_st -> %d\n", build_id, app_st);
    return app_st;
}