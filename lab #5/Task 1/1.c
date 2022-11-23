/*
    Заполнить массив натуральными числами с клавиатуры.
    Удалить из массива все двузначные числа.
*/
#include "arrays.h"

void inputn(int* n) {
    int x;
    while (scanf_s("%d", &x) != 1 || x > 100 || x < 1 || x % 1 != 0 || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    *n = x;
}

int main() {
    int  n, count = 0;
    int* arr;
    printf("Input the size array: ");
        inputn(&n);
            arr = memory(n);
    printf("\nInput array elements: \n");
        inputarr(arr, n);
    printf("\nSource array: \n");
        printarr(arr, n);
            workarr(arr, n, &count);
    n -= count;
    arr = rememory(arr, n);
    printf("\nThe resulting array: \n");
        printarr(arr, n);
            libertad(arr);
    return 0;
}