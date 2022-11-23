#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "locale.h"

void* memoryarr(int n);
void* rememoryarr(int* arr, int n);
void* libertadarr(int* arr);
void printarr(int* arr, int n);
void inputarr(int* arr, int n);
void randarr(int* arr, int n);
void merge(int* arr, int n, int* t1);
void badmerge(int* arr, int n);
void bubble(int* arr, int n, int* t2);
////////////////////////////////////////////////                                                                                                                                  
void poloz(int* arr, int n, int* p);
void printmat(int* arr, int n, int m);
void inputmat(int* arr, int n, int m);
void randmat(int* arr, int n, int m);
// сортировка методом выбора
