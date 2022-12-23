#include <stdio.h>
#include <stdlib.h>
#include "locale.h"

void input_size(int* n) {
    int x;
    while (scanf_s("%d", &x) != 1 || x < 1 || getchar() != '\n') {
        printf("Ошибка. Попробуйте снова: ");
        rewind(stdin);
    }
    *n = x;
}
void input_vybor(int* n) {
    int x;
    while (scanf_s("%d", &x) != 1 || (x != 1 && x != 2) || getchar() != '\n') {
        printf("Ошибка. Попробуйте снова: ");
        rewind(stdin);
    }
    *n = x;
}
void input_arr(int* n) {
    int x;
    while (scanf_s("%d", &x) != 1 || getchar() != '\n') {
        printf("Ошибка. Попробуйте снова: ");
        rewind(stdin);
    }
    *n = x;
}
void random(int* n) {
    int x = rand() % 200 - 100;
    *n = x;
}
int main(){
    int p = 1;
    setlocale(LC_ALL, "Russian");
    while (p != 2) {
        srand(time(NULL));
        int choice;
        printf("Выберите задание: ");
        while (scanf_s("%d", &choice) != 1 || (choice != 1 && choice != 2 && choice != 3) || getchar() != '\n') {
            printf("Ошибка. Попробуйте снова: ");
            rewind(stdin);
        }
        if (choice == 1) {
            int i, j, arr[100][100], col, row, count = 0, num = 0, mass;
            printf("Введите кол-во строк: ");
            input_size(&row);
            printf("Введите кол-во столбцов: ");
            input_size(&col);
            printf("Выберите тип ввода\n1) Рандом\n2) Клавиатура\n");
            input_vybor(&mass);
            switch (mass) {
            case 1:
                for (i = 0; i < row; i++) {
                    for (j = 0; j < col; j++) {
                        random(&arr[i][j]);
                    }
                }
                break;
            case 2:
                printf("Введите элементы матрицы:\n");
                for (i = 0; i < row; i++) {
                    for (j = 0; j < col; j++) {
                        input_arr(&arr[i][j]);
                    }
                }
                break;
            }
            for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                    printf("%5d", arr[i][j]);
                }
                printf("\n");
            }
            for (j = 0; j < col; j++) {
                for (i = 0; i < row; i++) {
                    if (arr[i][j] == 0) {
                        count++;
                    }
                }
            }
            if (count == 0) {
                printf("Нет столбцов с нулями\n");
            }
            else {
                printf("Кол-во стобцов имеющих 0: %d \n", count);
            }
            for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                    if (arr[i][j] == arr[i][j + 1]) {
                        num = i + 1;
                    }
                }
            }
            if (num == 0) {
                printf("Нет строки с повторяющимися элементами\n");
            }
            else {
                printf("Номер строки: %d", num);
            }
        }
        else if (choice == 2) {
            int i, j, arr[100][100], col, row, count, num = -1, mass;
            printf("Введите кол-во строк: ");
            input_size(&row);
            printf("Введите кол-во столбцов: ");
            input_size(&col);
            printf("Выберите тип ввода\n1) Рандом\n2) Клавиатура\n");
            input_vybor(&mass);
            switch (mass) {
            case 1:
                for (i = 0; i < row; i++) {
                    for (j = 0; j < col; j++) {
                        random(&arr[i][j]);
                    }
                }
                break;
            case 2:
                printf("Введите элементы матрицы:\n");
                for (i = 0; i < row; i++) {
                    for (j = 0; j < col; j++) {
                        input_arr(&arr[i][j]);
                    }
                }
                break;
            }
            for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                    printf("%5d", arr[i][j]);
                }
                printf("\n");
            }
            for (j = 0; j < col; j++) {
                for (i = 0; i < row; i++) {
                    if (arr[i][j] == 0) {
                        num = i;
                        break;
                    }
                }
            }
            if (num == -1) {
                printf("Нет строки с нулём\n");
            }
            else {
                printf("Номер строки: %d \n", num + 1);
                count = arr[num][0];
                for (i = 0; i < row; i++) {
                    for (j = 0; j < col; j++) {
                        arr[i][j] -= count;
                        printf("%5d", arr[i][j]);
                    }
                    printf("\n");
                }
            }
        }
        else {
        int i, j, arr[100][100], n, min, k, mass;
        printf("Введите размер матрицы: ");
        input_size(&n);
        printf("Выберите тип ввода\n1) Рандом\n2) Клавиатура\n");
        input_vybor(&mass);
        switch (mass) {
        case 1:
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    random(&arr[i][j]);
                }
            }
            break;
        case 2:
            printf("Введите элементы матрицы:\n");
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    input_arr(&arr[i][j]);
                }
            }
            break;
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%5d", arr[i][j]);
            }
            printf("\n");
        }
        min = arr[n / 2][n / 2];
        for (int i = n / 2, k = 0; i < n; i++, k++) {
            for (int j = n / 2 - k; j <= n / 2 + k; j++)
                if (arr[i][j] < min && arr[i][j] % 2 == 0) {
                    min = arr[i][j];
                }
        }
        if (min % 2 == 0) {
            printf("\nМинимальный элемент в 3-ей области: %d", min);
        }
        else {
            printf("\nВ 3-ей области нет чётных элементов");
        }
        }
        printf("\n\nХотите выбрать другое задание?\n1) Да\n2) Нет\n");
        while (scanf_s("%d", &p) != 1 || (p != 1 && p != 2) || getchar() != '\n') {
            printf("Ошибка. Попробуйте снова: ");
            rewind(stdin);
        }
    }
    return 0;
}
