4 лабораторная , 4 задача

#include <iostream>
#include <vector>

using namespace std;

// Функция для решения системы уравнений методом прогонки (Алгоритм Томаса)
vector<double> thomas_algorithm(vector<double>& a, vector<double>& b, vector<double>& c, vector<double>& d) {
    int n = d.size();
    vector<double> c_star(n, 0.0);
    vector<double> d_star(n, 0.0);
    vector<double> x(n, 0.0);

    // Прямой ход
    c_star[0] = c[0] / b[0];
    d_star[0] = d[0] / b[0];

    for (int i = 1; i < n; ++i) {
        double m = 1.0 / (b[i] - a[i] * c_star[i - 1]);
        c_star[i] = c[i] * m;
        d_star[i] = (d[i] - a[i] * d_star[i - 1]) * m;
    }

    // Обратный ход
    x[n - 1] = d_star[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        x[i] = d_star[i] - c_star[i] * x[i + 1];
    }

    return x;
}

int main() {
    vector<double> a = {0, -9, 1, -7, 6};  // Поддиагональ
    vector<double> b = {-14, 15, -11, 12, -7};  // Главная диагональ
    vector<double> c = {-6, -1, 1, 3, 0};  // Наддиагональ
    vector<double> d = {-78, -73, -38, 77, 91};  // Правая часть

    vector<double> solution = thomas_algorithm(a, b, c, d);

    cout << "Решение системы методом прогонки:" << endl;
    for (double x : solution) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
