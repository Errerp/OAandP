#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "locale.h"

void input_n(int* n) {
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
int main()
{
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
            int n, i, mass, large = 0, arr[100], C, proizv = 1, max = 0;
            printf("Введите размер массива: ");
            input_n(&n);
            printf("Выберите тип ввода\n1) Рандом\n2) Клавиатура\n");
            input_vybor(&mass);
            switch (mass){
            case 1:
                for (i = 0; i < n; i++) {
                    random(&arr[i]);
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 2:
                printf("Введите элементы массива:\n");
                for (i = 0; i < n; i++){
                    input_arr(&arr[i]);
                }
                break;
            }
            printf("Введите C: ");
            input_arr(&C);
            for (i = 0; i < n; i++){
                if (arr[i] > C){
                    large++;
                }
            }
            printf("Количество элементов массива, больших С: %d\n", large);
            for (i = 1; i < n; i++){
                if (arr[i] < 0){
                    arr[i] *= -1;
                }
                if (arr[i] > arr[max]){
                    max = i;
                }
            }
            for (i = max + 1; i < n; i++){
                proizv *= arr[i];
            }
            printf("Произведение элементов массива, расположенных после максимального по модулю элемента: %d", proizv);
		}
		else if (choice == 2) {
            int n, i, mass, k, j, arr[100];
            printf("Введите размер массива: ");
            input_n(&n);
            printf("Выберите тип ввода\n1) Рандом\n2) Клавиатура\n");
            input_vybor(&mass);
            switch (mass) {
            case 1:
                for (i = 0; i < n; i++) {
                    random(&arr[i]);
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 2:
                printf("Введите элементы массива:\n");
                for (i = 0; i < n; i++) {
                    input_arr(&arr[i]);
                }
                break;
            }
            printf("Введите k: ");
            input_n(&k);
            for (i = n - 1; i > 0; i--) {
                if ((i + 1) % k == 0) {
                    n++;
                    for (j = n; j > i; j--) {
                        arr[j] = arr[j - 1];
                    }
                    arr[i + 1] = 0;
                }
            }
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
		}
		else {
            int n, i, mass, j, num, arr[100];
            int CurrentCounter = 0, BiggestCounter = 0;
            printf("Введите размер массива: ");
            input_n(&n);
            printf("Выберите тип ввода\n1) Рандом\n2) Клавиатура\n");
            input_vybor(&mass);
            switch (mass) {
            case 1:
                for (i = 0; i < n; i++) {
                    random(&arr[i]);
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 2:
                printf("Введите элементы массива:\n");
                for (i = 0; i < n; i++) {
                    input_arr(&arr[i]);
                }
                break;
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = i; j < n; j++) {
                    if (arr[i] == arr[j]) {
                        CurrentCounter++;
                    }
                }
                if (CurrentCounter > BiggestCounter) {
                    BiggestCounter = CurrentCounter;
                    num = arr[i];
                }
                CurrentCounter = 0;
            }
            printf("Часто встречающееся число: %d\n", num);
		}
		printf("\n\nХотите выбрать другое задание?\n1) Да\n2) Нет\n");
		while (scanf_s("%d", &p) != 1 || (p != 1 && p != 2) || getchar() != '\n') {
			printf("Ошибка. Попробуйте снова: ");
			rewind(stdin);
		}
	}
	return 0;
}
