#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "locale.h"

//работа с памятью массива
void* memoryarr(int n)
{
    int* arr = (int*)malloc(n * sizeof(int));
}
void* rememoryarr(int* arr, int n)
{
    arr = (int*)realloc(arr, n * sizeof(int*));
}
void* libertadarr(int* arr) {
    free(arr);
}
// печать массива
void printarr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
}
// ввод элементов массива
void inputarr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        while (scanf_s("%d", &*(arr + i)) != 1 || *(arr + i) % 1 != 0 || *(arr + i) < 1 || getchar() != '\n') {
            printf("Ошибка. Попробуйте снова: ");
            rewind(stdin);
        }
    }
}
// ввод элементов массива рандомом
void randarr(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
            *(arr + i) = rand() % 2000 - 1000;
    }
}
// выбор положительных
void poloz(int* arr, int n, int*p) {
    int i, j,count = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            for (j = i; j < n; j++) {
                arr[j] = arr[j + 1];
            }
            n--;
            i--;
            count++;
        }
    }
    *p = count;
}
// сортировка методом слияния
void merge(int* arr, int n, int* t1){
    int mid = n / 2; // находим середину сортируемой последовательности
    if (n % 2 == 1)
        mid++;
    int h = 1; // шаг
    clock_t fTimeStart, fTimeStop;
    fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
    int* c = (int*)malloc(n * sizeof(int));// выделяем память под формируемую последовательность
    int step;
    while (h < n){
        step = h;
        int i = 0;   // индекс первого пути
        int j = mid; // индекс второго пути
        int k = 0;   // индекс элемента в результирующей последовательности
        while (step <= mid){
            while ((i < step) && (j < n) && (j < (mid + step))){ 
                // пока не дошли до конца пути заполняем следующий элемент формируемой последовательности меньшим из двух просматриваемых
                if (arr[i] < arr[j])
                {
                    c[k] = arr[i];
                    i++; k++;
                }
                else {
                    c[k] = arr[j];
                    j++; k++;
                }
            }
            while (i < step){ // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                c[k] = arr[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j < n)){  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                c[k] = arr[j];
                j++; k++;
            }
            step = step + h; // переходим к следующему этапу
        }
        h = h * 2;
        // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
        for (i = 0; i < n; i++)
            arr[i] = c[i];
    }
    free(c);
    fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
    *t1 = fTimeStop - fTimeStart;
}
void badmerge(int* arr, int n) {
    int mid = n / 2; // находим середину сортируемой последовательности
    if (n % 2 == 1)
        mid++;
    int h = 1; // шаг
    int* c = (int*)malloc(n * sizeof(int));// выделяем память под формируемую последовательность
    int step;
    while (h < n) {
        step = h;
        int i = 0;   // индекс первого пути
        int j = mid; // индекс второго пути
        int k = 0;   // индекс элемента в результирующей последовательности
        while (step <= mid) {
            while ((i < step) && (j < n) && (j < (mid + step))) {
                // пока не дошли до конца пути заполняем следующий элемент формируемой последовательности меньшим из двух просматриваемых
                if (arr[i] > arr[j])
                {
                    c[k] = arr[i];
                    i++; k++;
                }
                else {
                    c[k] = arr[j];
                    j++; k++;
                }
            }
            while (i < step) { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                c[k] = arr[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j < n)) {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                c[k] = arr[j];
                j++; k++;
            }
            step = step + h; // переходим к следующему этапу
        }
        h = h * 2;
        // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
        for (i = 0; i < n; i++)
            arr[i] = c[i];
    }
    free(c);
}
// сортировка пузырьком
void bubble(int* arr, int n,int *t2) {
    int i, j,a;
    clock_t fTimeStart, fTimeStop;
    fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
    for (i = 0; i < n - 1; i++) { // выбор верхней границы массива
        for (j = n - 1; j > i; j--) // просмотр массива ”снизу” ”вверх”
        {
            if (arr[j - 1] > arr[j]) // условие замены выполнено
            {
                a = arr[j - 1]; // замена j-1 и j элементов
                arr[j - 1] = arr[j];
                arr[j] = a;
            }
        }
    }
    fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
    *t2 = fTimeStop - fTimeStart;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// печать матрицы
void printmat(int* arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d ", *(arr + i * n + j));
        }
        printf("\n");
    }
}
// ввод элементов матрицы
void inputmat(int* arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            while (scanf_s("%d", arr + i * n + j) != 1 || *(arr + i * n + j) % 1 != 0 || getchar() != '\n') {
                printf("Ошибка. Попробуйте снова: ");
                rewind(stdin);
            }
        }
    }
}
// ввод элементов матрицы рандомом
void randmat(int* arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            *(arr + i * n + j) = rand() % 200 - 100;
        }
    }
}
// сортировка методом выбора
