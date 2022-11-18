#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// печать массива
void printarr(int* arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%5d ", *(arr + i * row + j));
        }
        printf("\n");
    }
}
// ввод элементов матрицы
void inputarr(int* arr, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            while (scanf_s("%d", &*(arr + i * row + j)) != 1 || *(arr + i * row + j) % 1 != 0 || getchar() != '\n') {
                printf("Error. Try again: ");
                rewind(stdin);
            }
        }
    }
}
// ввод элементов матрицы рандомом
void randarr(int* arr, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            *(arr + i * row + j) = rand() % 10;
        }
    }
}
// работа в матрице
int workarr(int* arr, int row, int col) {
    int i, j, sum, max = 0, num;
    for (j = 0; j < col; j++) {
        sum = 0;
        for (i = 0; i < row; i++) {
            sum += *(arr + i * col + j);
        }
        if (sum > max) {
            max = sum;
            num = j;
        }
    }
    arr = (int**)realloc(arr, (col) * sizeof(int*));
    arr[col - 1] = (int*)calloc(col, sizeof(int));
        for (j = num; j < col; j++) {
            for (i = 0; i < row; i++) {
                *(arr + i * col + j) = *(arr + i * col + j + 1);
            }
            arr = (int**)realloc(arr, (col - 1) * sizeof(int*));
        }
}
