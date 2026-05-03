#include "calcularr.h"

void uniqEllemets(const vector<int>& arr) {
    map<int, int> freq;
    for (int val : arr) {
        freq[val]++;
    }
    for (pair<int, int> p : freq) {
        cout << p.first << " встречается " << p.second << " раз(а)\n";
    }
}