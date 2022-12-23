#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "locale.h"

void input_n(int* n);
int choose_input(int* arr, int n, int* mass);
void* memory_arr(int n);
void* rememory_arr(int* arr, int n);
void* memory_mass(int n);
void* rememory_mass(int* mass, int n);
void* libertad_arr(int* arr, int* mass);
void print_arr(int* arr, int n);
void input_arr(int* arr, int n, int* mass);
void rand_arr(int* arr, int n, int* mass);
void poloz(int* mass, int n, int* p);
void zamena(int* mass, int* arr, int n);
void merge(int* mass, int n, int* t1);
void bad_merge(int* mass, int n, int* t2);
void bubble(int* mass, int n, int* t3);
////////////////////////////////////////////    
int choose_inp(int* matr, int n, int m);
int* memory(int n, int m);
void* libertad(int n, int** matr);
void print_matr(int** matr, int n, int m);
void input_matr(int** matr, int n, int m);
void rand_matr(int** matr, int n, int m);
void vybor(int** matr, int n, int m);