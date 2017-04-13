#include <stdio.h>


#include "CoolProp.h"


int main(int argc, char *argv[])
{
    int i;
    double H;
#pragma omp parallel for private(H)
    for(i = 0; i < 10; i++)
    {
        H = 0.0;
        H = CoolProp::PropsSI("H", "P", 1000000.0, "T", 500.0, "CO2");
        printf("i = %d H = %lf\n", i, H);
    }
}
