#include "calcularr.h"

int main() {
    int n{};
    cout << "Введите n >= 10: ";
    cin >> n;
    if (n < 10) {
        cout << "n должно быть не меньше 10.\n";
        return 1;
    }
    // 1 пункт
    vector<int> arr = randomOfOneToFifth(n);
    cout << "Пункт 1 массив инициализирован случайными числами 100-150\n";
    printArr(arr);
    // 2 пункт
    int secondMax{}, sumBetween{};
    secondEllandSumEll(arr, secondMax, sumBetween);
    cout << "\nВторой максимум: " << secondMax << endl;
    cout << "Сумма элементов между min и вторым max: " << sumBetween << endl;
    // 3 пункт
    vector<int> arr1, arr2, arr3;
    thirdArrOfOneTwo(n, arr1, arr2, arr3);
    cout << "1 массив (arr1):\n";
    printArr(arr1);
    cout << "2 массив (arr2):\n";
    printArr(arr2);
    cout << "3 массив (arr3, сумма/разность):\n";
    printArr(arr3);
    // 4 пункт
    cout << "\nПункт 4. Частота элементов первого массива:\n";
    uniqEllemets(arr);
    // 5 пункт
    int startYear{}, endYear{};
    cout << "Введите начальный год: ";
    cin >> startYear;
    cout << "Введите конечный год: ";
    cin >> endYear;
    vector<int> vesocYears = countVecosYear(startYear, endYear);
    if (!vesocYears.empty()) {
        cout << "Високосные годы: ";
        for (int val : vesocYears) {
            cout << val << " ";
        }
        cout << endl;
    } else {
        cout << "Нет високосных годов в указанном диапазоне." << endl;
    }
    return 0;
}
