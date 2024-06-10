4 лабораторная , 2 задача

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функция для вычисления определителя матрицы 3x3
double determinant(vector<vector<double>> matrix) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

// Функция для решения системы линейных уравнений методом Крамера
vector<double> cramer(vector<vector<double>> A, vector<double> B) {
    double detA = determinant(A);
    vector<vector<double>> A1 = A, A2 = A, A3 = A;

    for (int i = 0; i < 3; ++i) {
        A1[i][0] = B[i];
        A2[i][1] = B[i];
        A3[i][2] = B[i];
    }

    double detA1 = determinant(A1);
    double detA2 = determinant(A2);
    double detA3 = determinant(A3);

    return {detA1 / detA, detA2 / detA, detA3 / detA};
}

// Функция для решения системы линейных уравнений методом Якоби
vector<double> jacobi(vector<vector<double>> A, vector<double> B, int iterations = 100, double tol = 1e-10) {
    int n = A.size();
    vector<double> x(n, 0.0), x_new(n, 0.0);

    for (int k = 0; k < iterations; ++k) {
        for (int i = 0; i < n; ++i) {
            double sum = B[i];
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    sum -= A[i][j] * x[j];
                }
            }
            x_new[i] = sum / A[i][i];
        }

        bool converged = true;
        for (int i = 0; i < n; ++i) {
            if (fabs(x_new[i] - x[i]) > tol) {
                converged = false;
                break;
            }
        }

        if (converged) {
            break;
        }

        x = x_new;
    }

    return x;
}

int main() {
    vector<vector<double>> A = {
        {5, -2, 1},
        {2, -1, 1},
        {18, -8, 4}
    };
    vector<double> B = {2, -1, 0};

    // Решение методом Крамера
    vector<double> solution_cramer = cramer(A, B);
    cout << "Решение методом Крамера:" << endl;
    for (double x : solution_cramer) {
        cout << x << " ";
    }
    cout << endl;

    // Решение методом Якоби
    vector<double> solution_jacobi = jacobi(A, B);
    cout << "Решение методом Якоби:" << endl;
    for (double x : solution_jacobi) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
