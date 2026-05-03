#include "func.h"

double f(double x) {
    double result = 2.0 * x * x + cos(x) - 6.0;
    return result;
}

double df(double x) {
    double result = 4.0 * x - sin(x);
    return result;
}

double ddf(double x) {
    double result = 4.0 - cos(x);
    return result;
}

double phiPositive(double x) {
    double result = sqrt((6.0 - cos(x)) / 2.0);
    return result;
}

double phiNegative(double x) {
    double result = -sqrt((6.0 - cos(x)) / 2.0);
    return result;
}
