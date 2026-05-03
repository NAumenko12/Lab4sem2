#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

pair<string, int> bordWin(const vector<string>& candidates, const vector<vector<string>>& ballots);
string kondorWin(const vector<string>& candidates, const vector<vector<string>>& ballots);

vector<string> readCandidates(int n);
vector<vector<string>> readBallots(int n, int k);
void printResult(const pair<string, int>& bord, const string& kondorse);
