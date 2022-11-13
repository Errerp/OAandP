#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <locale.h>

// печать массива
void printarr(int* arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", *(arr + col * i + j));
        }
        printf("\n");
    }
}
// ввод элементов матрицы
void inputarr(int* arr, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            while (scanf_s("%d", arr + col * i + j) != 1 || *(arr + i * col + j) % 1 != 0) {
                printf("Ошибка. Пробуйте снова: ");
            }
        }
    }
}
// ввод элементов матрицы рандомом
void randarr(int* arr, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            *(arr + i * col + j) = rand() % 10;
        }
    }
}
// работа в матрице
void workarr(int* arr, int row, int col) {
    int sum, max = 0, cout = -1;
    for (int j = 0; j < col; j++) {
        int sum = 0;
        for (int i = 0; i < row; i++) {
            sum += *(arr + i * col + j);
        }
        if (sum > max) {
            max = sum;
            cout = j;
        }
    }
    if (cout >= 0) {
        for (int j = cout; j < col; j++) {
            for (int i = 0; i < row; i++) {
                *(arr + i * col + j) = *(arr + i * col + j + 1);
            }
        }
    }
}

