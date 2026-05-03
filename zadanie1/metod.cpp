#include "func.h"

double bisectionMethod(double a, double b, double epsilon) {
    printMethodHeader("Метод половинного деления", a, b);
    int n {};
    double middle = (a + b) / 2.0;
    bool isFinished {};
    vector<int> iterations(100, 1);
    for (int step : iterations) {
        if (!isFinished) {
            middle = (a + b) / 2.0;
            printMethodRow(n, a, b);
            bool isRootInLeftPart = f(a) * f(middle) < 0.0;
            if (isRootInLeftPart) {
                b = middle;
            } else {
                a = middle;
            }
            bool isIntervalSmall = fabs(b - a) <= epsilon;
            n += step;
            isFinished = isIntervalSmall;
        }
    }
    middle = (a + b) / 2.0;
    printRootResult(middle, n);
    return middle;
}

double newtonMethod(double x0, double epsilon) {
    printMethodHeader("Метод Ньютона", x0);
    int n {};
    double x = x0;
    double root = x0;
    bool isFinished {};
    vector<int> iterations(100, 1);
    for (int step : iterations) {
        if (!isFinished) {
            double nextX = x - f(x) / df(x);
            double diff = fabs(nextX - x);
            printMethodRow(n, x, nextX, diff);
            root = nextX;
            x = nextX;
            n += step;
            isFinished = diff <= epsilon;
        }
    }
    printRootResult(root, n);
    return root;
}

double simpleIterationMethod(double x0, double epsilon, bool isPositive) {
    printMethodHeader("Метод простых итераций", x0);
    int n {};
    double x = x0;
    double root = x0;
    bool isFinished {};
    vector<int> iterations(100, 1);
    for (int step : iterations) {
        if (!isFinished) {
            double nextX {};
            if (isPositive) {
                nextX = phiPositive(x);
            } else {
                nextX = phiNegative(x);
            }
            double diff = fabs(nextX - x);
            printMethodRow(n, x, nextX, diff);
            root = nextX;
            x = nextX;
            n += step;
            isFinished = diff <= epsilon;
        }
    }
    printRootResult(root, n);
    return root;
}

vector<double> solveRoot(const string& title, double a, double b, double x0, bool isPositive, double epsilon) {
    cout << "\n\n>>> " << title << " <<<" << endl;
    cout << "Интервал отделения корня: [" << a << ", " << b << "]" << endl;
    cout << "Проверка знаков: f(a) = " << f(a) << ", f(b) = " << f(b) << endl;
    cout << "Для Ньютона: f(x0) * f''(x0) = " << f(x0) * ddf(x0) << endl;
    vector<double> roots;
    roots.push_back(bisectionMethod(a, b, epsilon));
    roots.push_back(newtonMethod(x0, epsilon));
    roots.push_back(simpleIterationMethod(x0, epsilon, isPositive));
    return roots;
}

void printMethodHeader(const string& methodName, double a, double b) {
    cout << "\n=== " << methodName << " [" << a << ", " << b << "] ===" << endl;
    cout << left << setw(5) << "N" << setw(15) << "a_n"<< setw(15) << "b_n" << setw(15) << "b_n - a_n" << endl;
    cout << string(50, '-') << endl;
}

void printMethodHeader(const string& methodName, double x0) {
    cout << "\n=== " << methodName << " (x0 = " << x0 << ") ===" << endl;
    cout << left << setw(5) << "N" << setw(15) << "x_n" << setw(15) << "x_n+1" << setw(15) << "x_n+1 - x_n" << endl;
    cout << string(50, '-') << endl;
}

void printMethodRow(int n, double a, double b) {
    cout << left << setw(5) << n << setw(15) << fixed << setprecision(6) << a << setw(15) << b << setw(15) << fabs(b - a) << endl;
}

void printMethodRow(int n, double x, double nextX, double diff) {
    cout << left << setw(5) << n << setw(15) << fixed << setprecision(6) << x << setw(15) << nextX << setw(15) << diff << endl;
}

void printRootResult(double root, int n) {
    cout << string(50, '-') << endl;
    cout << "Корень найден: x = " << setprecision(10) << root << endl;
    cout << "f(x) = " << f(root) << endl;
    cout << "Итераций: " << n << endl;
}
