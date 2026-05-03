#include "calcularr.h"

void secondEllandSumEll(const vector<int>& arr, int& secondMax, int& sumBetween) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    int minVal = sortedArr[0];
    secondMax = sortedArr[sortedArr.size() - 2];
    int minIdx = -1;
    int secondIdx = -1;
    int idx = 0;
    for (int val : arr) {
        if (minIdx == -1 && val == minVal) {
            minIdx = idx;
        }
        if (secondIdx == -1 && val == secondMax && idx != minIdx) {
            secondIdx = idx;
        }
        ++idx;
    }
    sumBetween = 0;
    int left  = min(minIdx, secondIdx);
    int right = max(minIdx, secondIdx);
    idx = 0;
    for (int val : arr) {
        if (idx > left && idx < right){
            sumBetween += val;
        } 
        ++idx;
    }
}
