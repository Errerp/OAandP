#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// ������ �������
void printarr(int* arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%5d ", *(arr + col * i + j));
        }
        printf("\n");
    }
}
// ���� ��������� �������
void inputarr(int* arr, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            while (scanf_s("%d", arr + col * i + j) != 1 || *(arr + i * col + j) % 1 != 0) {
                printf("Error. Try again: ");
            }
        }
    }
}
// ���� ��������� ������� ��������
void randarr(int* arr, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            *(arr + i * col + j) = rand() % 200 - 100;
        }
    }
}
// ������ � �������
void workarr(int* arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j < i) {
                printf("");
            }
            else {
                printf("%5d ", *(arr + col * i + j));
            }
        }
        printf("\n");
    }
}