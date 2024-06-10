# 4 лабораторная , 1 задача

import numpy as np

# Коэффициенты матрицы
A = np.array([
    [-1, -7, -3, -2],
    [-8, 1, -9, 0],
    [8, 2, -5, -3],
    [-5, 3, 5, -9]
])

# Правая часть
b = np.array([-12, -60, -91, -43])

# Решение системы с использованием матричного метода
x_matrix_method = np.linalg.solve(A, b)

# Метод Гаусса
def gauss(A, b):
    n = len(b)
    M = A.copy().astype(float)
    b = b.astype(float)
    # Прямой ход
    for k in range(n):
        for i in range(k+1, n):
            if M[i, k] != 0.0:
                lam = M[i, k] / M[k, k]
                M[i, k:n] = M[i, k:n] - lam * M[k, k:n]
                b[i] = b[i] - lam * b[k]

    # Обратный ход
    x = np.zeros(n)
    for k in range(n-1, -1, -1):
        x[k] = (b[k] - np.dot(M[k, k+1:], x[k+1:])) / M[k, k]
    return x

# Решение системы методом Гаусса
x_gauss_method = gauss(A, b)

# Проверка решений
check_matrix_method = A @ x_matrix_method - b
check_gauss_method = A @ x_gauss_method - b

print("Решение с использованием матричного метода:")
print(x_matrix_method)
print("Проверка решения (должно быть близко к нулю):")
print(check_matrix_method)

print("\nРешение с использованием метода Гаусса:")
print(x_gauss_method)
print("Проверка решения (должно быть близко к нулю):")
print(check_gauss_method)
