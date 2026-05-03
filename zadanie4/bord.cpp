#include "golosov.h"

pair<string, int> bordWin(const vector<string>& candidates, const vector<vector<string>>& ballots) {
    map<string, int> score;
    int maxPoints = candidates.size() - 1;
    for (const vector<string>& ballot : ballots) {
        int points = maxPoints;
        for (const string& candidate : ballot) {
            score[candidate] += points;
            --points;
        }
    }
    pair<string, int> result = {candidates[0], score[candidates[0]]};
    for (const string& candidate : candidates) {
        if (score[candidate] > result.second) {
            result = {candidate, score[candidate]};
        }
    }
    return result;
}
