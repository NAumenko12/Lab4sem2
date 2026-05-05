#include "golosov.h"

int main() {
    int n {};
    int k {};
    cout << "Введите количество кандидатов: ";
    cin >> n;
    cout << "Введите количество вариантов ранжирования: ";
    cin >> k;
    vector<string> candidates = readCandidates(n);
    vector<vector<string>> ballots = readBallots(n, k);
    pair<string, int> bord = bordWin(candidates, ballots);
    string kondorse = kondorWin(candidates, ballots);
    printResult(bord, kondorse);
    return 0;
}
