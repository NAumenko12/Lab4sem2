#include "fibonachi.h"

int main() {
    int a{}, b{}, m{}, count{};
    char operation{};
    cout << "Введите a, b, операцию ";
    cin >> a >> b >> operation >> m;
    vector<int> startValues(max(a, b));
    cout << "Введите нач знач ";
    for (int& val : startValues) {
        cin >> val;
    }
    cout << "Введите кол ген чисел ";
    cin >> count;
    vector<int> result = Fibonachi(a, b, operation, m, startValues, count);
    printVector(result);
    return 0;
}
