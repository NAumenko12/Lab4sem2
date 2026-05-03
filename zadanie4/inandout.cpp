#include "golosov.h"

vector<string> readCandidates(int n) {
    vector<string> candidates(n);
    cout << "Введите имена кандидатов:" << endl;
    for (string& candidate : candidates){
        cin >> candidate;
    }
    return candidates;
}

vector<vector<string>> readBallots(int n, int k) {
    vector<vector<string>> ballots;
    cout << "Введите количество избирателей и ранжирование:" << endl;
    vector<vector<string>> variants(k, vector<string>(n));
    for (vector<string>& variant : variants) {
        int count {};
        cin >> count;
        for (string& candidate : variant) {
            cin >> candidate;
        }
        vector<vector<string>> sameBallots(count, variant);
        for (const vector<string>& ballot : sameBallots) {
            ballots.push_back(ballot);
        }
    }
    return ballots;
}

void printResult(const pair<string, int>& bord, const string& kondorse) {
    cout << "По Борду: " << bord.first << " (" << bord.second << " очков)" << endl;
    cout << "По Кондорсе: " << kondorse << endl;
}
