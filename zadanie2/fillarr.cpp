#include "calcularr.h"

void fillRandom(vector<int>& vec, int minVal, int maxVal) {
    static random_device rd;
    static ranlux24_base gen(rd());
    uniform_int_distribution<int> dist(minVal, maxVal);
    for (int& val : vec) {
        val = dist(gen);
    }
}
vector<int> randomOfOneToFifth(int n) {
    vector<int> arr(n);            
    fillRandom(arr, 100, 150);
    return arr;
}
void printArr(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}
