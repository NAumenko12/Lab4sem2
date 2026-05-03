#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> randomOfOneToFifth(int n);
void fillRandom(vector<int>& vec, int minVal, int maxVal);
void printArr(const vector<int>& arr);
void thirdArrOfOneTwo(int n, vector<int>& arr1, vector<int>& arr2, vector<int>& arr3);
void uniqEllemets(const vector<int>& arr);
vector<int> countVecosYear(int startYear, int endYear);
void secondEllandSumEll(const vector<int>& arr, int& secondMax, int& sumBetween);
