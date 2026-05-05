#include "func.h"

int main() {
    double epsilon {1e-4};
    vector<double> negativeRoots = solveRoot("ОТРИЦАТЕЛЬНЫЙ КОРЕНЬ", -2.0, -1.5, -2.0, false, epsilon);
    vector<double> positiveRoots = solveRoot("ПОЛОЖИТЕЛЬНЫЙ КОРЕНЬ", 1.5, 2.0, 2.0, true, epsilon);
    cout << "\n корни по методу Ньютона:" << endl;
    cout << "x1 = " << negativeRoots[1] << endl;
    cout << "x2 = " << positiveRoots[1] << endl;
    return 0;
}
