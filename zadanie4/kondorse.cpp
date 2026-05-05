#include "golosov.h"

bool firstHigher(const string& a, const string& b, const vector<string>& ranking) {
    bool isHigher {};
    bool isFound {};
    for (const string& candidate : ranking) {
        if (!isFound && candidate == a) {
            isHigher = true;
            isFound = true;
        }
        if (!isFound && candidate == b) {
            isHigher = false;
            isFound = true;
        }
    }
    return isHigher;
}

bool beatsInPair(const string& a, const string& b, const vector<vector<string>>& ballots) {
    int aVotes {};
    int bVotes {};
    for (const vector<string>& ballot : ballots) {
        if (firstHigher(a, b, ballot)) {
            ++aVotes;
        } else {
            ++bVotes;
        }
    }
    return aVotes > bVotes;
}

string kondorWin(const vector<string>& candidates, const vector<vector<string>>& ballots) {
    string result = "не определён";
    int needWins = candidates.size() - 1;
    for (const string& candidate : candidates) {
        int wins {};
        for (const string& opponent : candidates) {
            if (candidate != opponent && beatsInPair(candidate, opponent, ballots)) {
                ++wins;
            }
        }
        if (result == "не определён" && wins == needWins) {
            result = candidate;
        }
    }
    return result;
}
