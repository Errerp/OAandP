#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// печать массива
void printarr(int* arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%5d ", *(arr + col * i + j));
        }
        printf("\n");
    }
}
// ввод элементов матрицы
void inputarr(int* arr, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            while (scanf_s("%d", arr + col * i + j) != 1 || *(arr + i * col + j) % 1 != 0) {
                printf("Error. Try again: ");
            }
        }
    }
}
// ввод элементов матрицы рандомом
void randarr(int* arr, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            *(arr + i * col + j) = rand() % 200 - 100;
        }
    }
}
// работа в матрице
void workarr(int* arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i + j < row) {
                printf("%5d ", *(arr + col * i + j));
            }
        }
        printf("\n");
    }
}
