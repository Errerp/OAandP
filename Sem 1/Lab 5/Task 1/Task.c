/*
    Заполнить массив натуральными числами с клавиатуры.
    Удалить из массива все двузначные числа.
*/
#include "arrays.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int  n, count = 0;
    int* arr;
    printf("Введите размер массива: ");
        input_n(&n);
            arr = memory(n);
    printf("\nВведите элементы массива: \n");
        input_arr(arr, n);
    printf("\n\nНачальный массив:\n\n");
        print_arr(arr, n);
            work_arr(arr, n, &count);
    n -= count;
    arr = rememory(arr, n);
    printf("\n\nИтоговый массив:\n\n");
        print_arr(arr, n);
            libertad(arr);
    return 0;
}
