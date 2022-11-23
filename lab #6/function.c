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
void poloz(int* arr, int n, int* p);
void merge(int* arr, int n, int* t1);
void badmerge(int* arr, int n);
void bubble(int* arr, int n, int* t2);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                                                                                                                                    
int* memory(int n, int m);
void* libertad(int n, int** matr);
void print_matr(int** matr, int n, int m);
void input_matr(int** matr, int n, int m);
void rand_matr(int** matr, int n, int m);
// сортировка методом выбора
