#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "locale.h"

void input_size(int* n);
int* memory(int n, int m);
void* libertad(int n, int** matr);
int chooseinput(int* matr, int n, int m);
void print_matr(int** matr, int n, int m);
void input_matr(int** matr, int n, int m);
void rand_matr(int** matr, int n, int m);
void work_in_matr(int** matr, int n, int m);