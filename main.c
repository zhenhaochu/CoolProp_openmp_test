#include <stdio.h>


#include "CoolProp_lib.h"


int main(int argc, char *argv[])
{
    int i;
    double H;
    CoolPropdllinit();
#pragma omp parallel for private(H)
    for(i = 0; i < 10; i++)
    {
        H = 0.0;
        H = PropsSIdll("H", "P", 1000000.0, "T", 500.0, "CO2");
        printf("i = %d H = %lf\n", i, H);
    }
    CloseCoolPropdll();
}
