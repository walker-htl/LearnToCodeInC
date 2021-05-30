#include "myMath.h"
#include "testMyMath.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define DEG_40 0.698131701

int runTests() {
    int errorCounter = 0;

    double t1 = mySin(DEG_40, 0);
    double t2 = myCos(DEG_40, 0);
    double t3 = myTan(DEG_40, 0);

    double epsT1 = fabs(t1 - sin(DEG_40));
    double epsT2 = fabs(t2 - cos(DEG_40));
    double epsT3 = fabs(t3 - tan(DEG_40));

    if (epsT1 > EPSILON ) {
        errorCounter++;
        printf("mySin(%f) = %f, but expected is %f\n", DEG_40, t1, sin(DEG_40));
    }
    if (epsT2 > EPSILON ) {
        errorCounter++;
        printf("myCos(%f) = %f, but expected is %f\n", DEG_40, t2, cos(DEG_40));
    }

    if (epsT3 > EPSILON ) {
        errorCounter++;
        printf("myTan(%f) = %f, but expected is %f\n", DEG_40, t3, tan(DEG_40));
    }

    return errorCounter;
}