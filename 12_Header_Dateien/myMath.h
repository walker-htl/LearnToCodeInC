#ifndef INC_12_HEADER_DATEIEN_MYMATH_H
#define INC_12_HEADER_DATEIEN_MYMATH_H

#define PI 3.14159265359
#define EPSILON 0.0000001
#define DEG_TO_RAD(parameter) (parameter/180*PI)
#define RAD_TO_DEG(parameter) (parameter*PI/180)

double mySin(double argument, int type);
double myCos(double argument, int type);
double myTan(double argument, int type);

#endif //INC_12_HEADER_DATEIEN_MYMATH_H
