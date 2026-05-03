#include "fibonachi.h"

int calculateNextValue(int first, int second, char operation, int m) {
    int value{};
    if (operation == '+') {
        value = first + second;
    } else if (operation == '-') {
        value = first - second;
    } else if (operation == '*') {
        value = first * second;
    } else if (operation == '^') {
        value = first ^ second;
    }
    value %= m;
    if (value < 0) {
        value += m;
    }
    return value;
}

vector<int> Fibonachi(int a, int b, char operation, int m, vector<int> sequence, int count) {
    vector<int> result(count);
    int n = max(a, b);
    for (int& val : result) {
        val = calculateNextValue(sequence[n - a], sequence[n - b], operation, m);
        sequence.push_back(val);
        ++n;
    }

    return result;
}

void printVector(const vector<int>& values) {
    for (int val : values) {
        cout << val << " ";
    }
}
