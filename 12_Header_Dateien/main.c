#include <stdio.h>
#include "myMath.h"
#include "testMyMath.h"

int main() {
    // Let's run the tests for the myMath library!
    int failedTests = runTests();
    printf("We found %d failed tests in Mymath library\n\n", failedTests);

    // Just using some tests!
    printf("MySin(40°) = %f\n", mySin(40, 1));
    printf("MyCos(0rad) = %f\n", myCos(0, 0));
    printf("MyCos(0°) = %f\n", myCos(0, 1));

    return 0;
}
