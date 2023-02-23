#include "func.h"

int input(int min, int max){
    int x;
    while (scanf_s("%d", &x) != 1 || x < min || x > max || x % 1 != 0 || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    return x;
}

void fill_file(char* filename, int n){
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        printf("Input %d element: ", i + 1);
        arr[i] = input(INT_MIN, INT_MAX);
    }
    FILE* f;
    fopen_s(&f, filename, "wb+");
    fwrite(arr, sizeof(int), n, f);
    fflush(f);
    fclose(f);
}

void read_file(char* filename, int n){
    FILE* f;
    fopen_s(&f, filename, "r+b");
    int num;
    for (int i = 0; i < n; ++i) {
        fread(&num, sizeof(int), 1,f);
        printf("%d ", num);
    }
    fclose(f);
}

void bubble_sort(char* filename){
    FILE* f;
    fpos_t pos;
    int num,tmp;
    fopen_s(&f, filename, "rb+");

    int size = sizeof(int);

    fseek(f, 0, SEEK_END);
    pos = ftell(f);
    int len = pos / size;
    rewind(f);

    for(int i = 0; i < len; i++){
        for (int j = 0; j <= len - 2; ++j) {
            fseek(f, j * size, SEEK_SET);
            fread(&num, size,1,f);
            fread(&tmp, size,1,f);
            if(num < tmp){
                fseek(f, j * size, SEEK_SET);
                fwrite(&tmp, size,1,f);
                fwrite(&num, size,1,f);
            }
        }
    }
    fclose(f);
}

void task1(char* filename, int n){
    printf("\nFile state: ");
    read_file(filename, n);
}

void task2(char* filename, int n){
    printf("\nFile state: ");
    read_file(filename, n);
    FILE* f;
    fopen_s(&f, filename, "r+b");
    int num, tmp, count = 0;
    for (int i = 1; i < n; ++i) {
        int sum = 0;
        fseek(f, i * sizeof(int), SEEK_SET);
        fread(&num, sizeof(int), 1,f);
        for (int j = 0; j < i; ++j) {
            fseek(f, j * sizeof(int), SEEK_SET);
            fread(&tmp, sizeof(int), 1,f);
            sum += tmp;
        }
        if(num > sum){
            count++;
        }
    }
    printf("\n%d elements are greater than the sum of all the previous ones.", count);
    fclose(f);
}

void task3(char* filename, int n, char* fn, int m){
    printf("\nFirst file state: ");
    read_file(filename, n);

    printf("\n\nSecond file state: ");
    read_file(fn, m);

    printf("\n\nFirst file sort: ");
    bubble_sort(filename);
    read_file(filename, n);

    printf("\n\nSecond file sort: ");
    bubble_sort(fn);
    read_file(fn, m);
}

void task4(char* filename, int n, char* fn, int m){
    printf("\nFirst file state: ");
    bubble_sort(filename);
    read_file(filename, n);
    printf("\n\nSecond file state: ");
    bubble_sort(fn);
    read_file(fn, m);

    FILE *first, *second, *end;
    fopen_s(&first, filename, "rb+");
    fopen_s(&second, fn, "rb+");
    fopen_s(&end, "end.bin", "wb+");

    int num;
    for (int i = 0; i < n; ++i) {
        fseek(first, i * sizeof(int), SEEK_SET);
        fread(&num, sizeof(int),1,first);
        fseek(end, i * sizeof(int), SEEK_SET);
        fwrite(&num, sizeof(int),1,end);
    }

    printf("\n\nFinally file sort: ");
    read_file("end.bin", n);
}