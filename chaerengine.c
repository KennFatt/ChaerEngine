#include <stdio.h>
#include "src/statemanager.h"

int main(int argc, char **argv)
{
    int app_st = 0;
    char *build_id = argc > 1 ? argv[1] : "NaN";

    printf("[#%s] Program closed with app_st -> %d\n", build_id, app_st);
    return app_st;
}