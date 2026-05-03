#include "calcularr.h"

vector<int> countVecosYear(int startYear, int endYear) {
    if (startYear > endYear) {
        swap(startYear, endYear);
    }
    int size = endYear - startYear + 1;
    vector<int> allYears(size);
    int year = startYear;
    for (int& val : allYears) {
        val = year++;
    }
    vector<int> vesoc;
    for (int val : allYears) {
        if ((val % 400 == 0) || (val % 4 == 0 && val % 100 != 0)) {
            vesoc.push_back(val);
        }
    }
    return vesoc;
}
