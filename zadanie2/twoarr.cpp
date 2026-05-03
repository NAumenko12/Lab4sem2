#include "calcularr.h"

void thirdArrOfOneTwo(int n, vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    arr1.resize(n);
    arr2.resize(n);
    arr3.resize(n);
    fillRandom(arr1, -50, 50);
    fillRandom(arr2, -50, 50);
    int idx = 0;
    for (int& val : arr3) {
        if (idx % 2 == 0) {
            val = arr1[idx] + arr2[idx];
        } else {
            val = arr1[idx] - arr2[idx];
        }
        ++idx;
    }
}
