#include "function.h"

void input_n(int* n) {
    int x;
    while (scanf_s("%d", &x) != 1 || x < 1 || getchar() != '\n') {
        printf("������. ���������� �����: ");
        rewind(stdin);
    }
    *n = x;
}
int choose_input(int* arr, int n, int* mass) {
    int x;
    while (scanf_s("%d", &x) != 1 || x > 2 || x < 1 || x % 1 != 0 || getchar() != '\n') {
        printf("������. ���������� �����: ");
        rewind(stdin);
    }
    switch (x)
    {
    case 1:
        printf("\n������� ������� �������: \n");
        input_arr(arr, n, mass);
        break;
    case 2:
        rand_arr(arr, n, mass);
        break;
    }
    return arr, mass;
}
//������ � ������� �������
void* memory_arr(int n)
{
    int* arr = (int*)malloc(n * sizeof(int));
}
void* rememory_arr(int* arr, int n)
{
    arr = (int*)realloc(arr, n * sizeof(int*));
}
void* memory_mass(int n)
{
    int* mass = (int*)malloc(n * sizeof(int));
}
void* rememory_mass(int* mass, int n)
{
    mass = (int*)realloc(mass, n * sizeof(int*));
}
void* libertad_arr(int* arr,int* mass) {
    free(arr);
    free(mass);
}
// ������ �������
void print_arr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
}
// ���� ��������� �������
void input_arr(int* arr, int n, int* mass) {
    for (int i = 0; i < n; i++) {
        while (scanf_s("%d", &*(arr + i)) != 1 || *(arr + i) % 1 != 0 || getchar() != '\n') {
            printf("������. ���������� �����: ");
            rewind(stdin);
        }
        *(mass + i) = *(arr + i);
    }
}
// ���� ��������� ������� ��������
void rand_arr(int* arr, int n, int* mass) {
    for (int i = 0; i < n; ++i) {
        *(arr + i) = rand() % 2000 - 1000;
        *(mass + i) = *(arr + i);
    }
}
void poloz(int* mass, int n, int* p) {
    int i, j, count = 0;
    for (i = 0; i < n; i++) {
        if (mass[i] < 0) {
            for (j = i; j < n; j++) {
                mass[j] = mass[j + 1];
            }
            n--;
            i--;
            count++;
        }
    }
    *p = count;
}
void zamena(int* mass, int* arr, int n) {
    for (int i = 0, z = 0; i < n; i++) {
        if (arr[i] > 0) {
            arr[i] = mass[z];
            z++;
        }
    }
}
// ���������� ������� �������
void merge(int* mass, int n, int* t1) {
    int p;
    poloz(mass, n, &p);
    n -= p;
    int mid = n / 2; // ������� �������� ����������� ������������������
    if (n % 2 == 1)
        mid++;
    int h = 1; // ���
    clock_t fTimeStart, fTimeStop;
    fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
    int* c = (int*)malloc(n * sizeof(int));// �������� ������ ��� ����������� ������������������
    int step;
    while (h < n) {
        step = h;
        int i = 0;   // ������ ������� ����
        int j = mid; // ������ ������� ����
        int k = 0;   // ������ �������� � �������������� ������������������
        while (step <= mid) {
            while ((i < step) && (j < n) && (j < (mid + step))) {
                // ���� �� ����� �� ����� ���� ��������� ��������� ������� ����������� ������������������ ������� �� ���� ���������������
                if (mass[i] < mass[j])
                {
                    c[k] = mass[i];
                    i++; k++;
                }
                else {
                    c[k] = mass[j];
                    j++; k++;
                }
            }
            while (i < step) { // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
                c[k] = mass[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j < n)) {  // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
                c[k] = mass[j];
                j++; k++;
            }
            step = step + h; // ��������� � ���������� �����
        }
        h = h * 2;
        // ��������� ������������� ������������������ (������������� �������) � �������� ������
        for (i = 0; i < n; i++)
            mass[i] = c[i];
    }
    free(c);
    fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
    *t1 = fTimeStop - fTimeStart;
    n += p;
}
void bad_merge(int* mass, int n, int* t3) {
    int p;
    poloz(mass, n, &p);
    n -= p;
    clock_t fTimeStart, fTimeStop;
    fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
    int mid = n / 2; // ������� �������� ����������� ������������������
    if (n % 2 == 1)
        mid++;
    int h = 1; // ���
    int* c = (int*)malloc(n * sizeof(int));// �������� ������ ��� ����������� ������������������
    int step;
    while (h < n) {
        step = h;
        int i = 0;   // ������ ������� ����
        int j = mid; // ������ ������� ����
        int k = 0;   // ������ �������� � �������������� ������������������
        while (step <= mid) {
            while ((i < step) && (j < n) && (j < (mid + step))) {
                // ���� �� ����� �� ����� ���� ��������� ��������� ������� ����������� ������������������ ������� �� ���� ���������������
                if (mass[i] > mass[j])
                {
                    c[k] = mass[i];
                    i++; k++;
                }
                else {
                    c[k] = mass[j];
                    j++; k++;
                }
            }
            while (i < step) { // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
                c[k] = mass[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j < n)) {  // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
                c[k] = mass[j];
                j++; k++;
            }
            step = step + h; // ��������� � ���������� �����
        }
        h = h * 2;
        // ��������� ������������� ������������������ (������������� �������) � �������� ������
        for (i = 0; i < n; i++)
            mass[i] = c[i];
    }
    free(c);
    fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
    *t3 = fTimeStop - fTimeStart;
    n += p;
}
// ���������� ���������
void bubble(int* mass, int n, int* t3) {
    int p;
    poloz(mass, n, &p);
    n -= p;
    int i, j, a;
    clock_t fTimeStart, fTimeStop;
    fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
    for (i = 0; i < n - 1; i++) { // ����� ������� ������� �������
        for (j = n - 1; j > i; j--) // �������� ������� ������ �������
        {
            if (mass[j - 1] > mass[j]) // ������� ������ ���������
            {
                a = mass[j - 1]; // ������ j-1 � j ���������
                mass[j - 1] = mass[j];
                mass[j] = a;
            }
        }
    }
    fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
    *t3 = fTimeStop - fTimeStart;
    n += p;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int choose_inp(int* matr, int n, int m) {
    int x;
    while (scanf_s("%d", &x) != 1 || x > 2 || x < 1 || x % 1 != 0 || getchar() != '\n') {
        printf("������. ���������� �����: ");
        rewind(stdin);
    }
    switch (x)
    {
    case 1:
        printf("\n������� ������� �������: \n");
        input_matr(matr, n, m);
        break;
    case 2:
        rand_matr(matr, n, m);
        break;
    }
    return matr;
}
int* memory(int n, int m)
{
    int** matr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        *(matr + i) = (int*)calloc(m, sizeof(int));
    return matr;
}
void* libertad(int n, int** matr) {
    for (int i = 0; i < n; i++)
        free(*(matr + i));
    free(matr);
}
// ������ �������
void print_matr(int** matr, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d", *(*(matr + i) + j));
        }
        printf("\n");
    }
}
// ���� ��������� ������� c ����������
void input_matr(int** matr, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("������� ������� [%d][%d]\n", i + 1, j + 1);
            while (scanf_s("%d", *(matr + i) + j) != 1) {
                printf("������. ���������� �����:\n");
                rewind(stdin);
            }
        }
    }
}
// ���� ��������� ������� ��������
void rand_matr(int** matr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            *(*(matr + i) + j) = rand() % 6;
        }
    }
}
// ���������� ������� ������
void vybor(int** matr, int n, int m) {
    int num, max, count, min = 100, maks = -100;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (*(*(matr + i) + j) > maks) {
                maks = *(*(matr + i) + j);
            }
            if (*(*(matr + i) + j) < min) {
                min = *(*(matr + i) + j);
            }
        }
    }
    for (int k = 0; k < m; k++) {
        num = k;
        max = 0;
        for (int j = k; j < m; j++) {
            count = 0;
            for (int z = min; z < maks; z++) {
                int temp = 0;
                for (int i = 0; i < m; i++) {
                    if (matr[i][j] == z) {
                        temp++;
                    }
                }
                if (temp > count) {
                    count = temp;
                }
            }
            if (count > max) {
                max = count;
                num = j;
            }
        }
        if (num != k) {
            for (int i = 0; i < n; i++) {
                int t = matr[i][k];
                matr[i][k] = matr[i][num];
                matr[i][num] = t;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        *(matr + i) = realloc(*(matr + i), m * sizeof(int));
    }
}