#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculateNextValue(int first, int second, char operation, int m);
vector<int> Fibonachi(int a, int b, char operation, int m, vector<int> sequence, int count);
void printVector(const vector<int>& values);
