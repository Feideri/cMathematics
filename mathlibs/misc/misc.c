#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

float sqroot(float s){

    if(s <= 0){
        printf("Input cannot be zero or less!\n");
        return 0;
    }

    float tolerance = 0.00001;
    float ret = s;

    while((ret - s/ret) > tolerance){
        ret = 0.5*(ret + s/ret);
    }

    return ret;

}
