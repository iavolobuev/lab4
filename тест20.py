# 4 лабораторная , 3 задача

import numpy as np


def seidel(A, b, tolerance, max_iterations=1000):
    n = len(b)
    x = np.zeros_like(b, dtype=np.double)
    x_new = np.zeros_like(x)

    for iteration in range(max_iterations):
        for i in range(n):
            s1 = np.dot(A[i, :i], x_new[:i])
            s2 = np.dot(A[i, i + 1:], x[i + 1:])
            x_new[i] = (b[i] - s1 - s2) / A[i, i]

        # Проверка на сходимость
        if np.allclose(x, x_new, atol=tolerance, rtol=0.):
            break

        x = x_new.copy()

    return x


# Коэффициенты матрицы
A = np.array([
    [26, -9, -8, 8],
    [9, -21, -2, 8],
    [-3, 2, -18, 8],
    [1, -6, -1, 11]
])

# Правая часть
b = np.array([20, -164, 140, -81])

# Задаем точность
tolerance = 0.01

# Решение системы методом Зейделя
solution = seidel(A, b, tolerance)

print("Решение системы методом Зейделя:")
print(solution)

# Проверка решения
check_solution = np.dot(A, solution) - b
print("Проверка решения (должно быть близко к нулю):")
print(check_solution)
