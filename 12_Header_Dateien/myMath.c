//
// Created by walter on 30.05.21.
//

#include <math.h>
#include "myMath.h"

double mySin(double argument, int type) {
    // argument is in radiant
    if (type == 0) {
        return sin(argument);
    }
    else {
        return sin(DEG_TO_RAD(argument));
    }
}

double myCos(double argument, int type) {
    // argument is in radiant
    if (type == 0) {
        // error to show wrong test results
        return cos(argument+0.1);
    }
    else {
        return cos(DEG_TO_RAD(argument));
    }
}

double myTan(double argument, int type) {
    // argument is in radiant
    if (type == 0) {
        return tan(argument);
    }
    else {
        return tan(DEG_TO_RAD(argument));
    }
}