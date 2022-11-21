#include <stdlib.h>
#include <stdio.h>


void* memory(int n)
{
    int* arr = (int*)malloc(n * sizeof(int));
}
void* rememory(int* arr, int n)
{
    arr = (int*)realloc(arr, n * sizeof(int*));
    return arr;
}
// печать массива
void printarr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
            printf("%d ", *(arr + i) );
    }
}
// ввод элементов массива
void inputarr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        while (scanf_s("%d", &*(arr + i)) != 1 || *(arr + i) % 1 != 0 || *(arr + i) < 1 || getchar() != '\n') {
                printf("Error. Try again: ");
                rewind(stdin);
        }
    }
}

// работа в массиве
void workarr(int* arr, int n, int* count) {
    int i, j;
    int p = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] > 9 && arr[i] < 100) {
            for (j = i; j < n; j++) {
                arr[j] = arr[j + 1];
            }
            p++;
            i--;
        }
    }
    *count = p;
}
