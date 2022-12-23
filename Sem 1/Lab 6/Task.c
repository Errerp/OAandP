#include "function.h"

int main() {
    int p = 1;
    setlocale(LC_ALL, "Russian");
    while (p != 2) {
        srand(time(NULL));
        int choice;
        printf("Выберите задание: \n1) В одномерном массиве выполнить сортировку положительных элементов методом слияния.\n2) В матрице размером NxM выполнить сортировку столбцов по убыванию количества элементов встречающихся более одного раза методом выбора.\n");
        while (scanf_s("%d", &choice) != 1 || (choice != 1 && choice != 2) || getchar() != '\n') {
            printf("Ошибка. Попробуйте снова: ");
            rewind(stdin);
        }
        if(choice == 1) {
            int  n, * arr, t1, t2, t3, * mass;
            printf("Введите размер массива: ");
            input_n(&n);
            arr = memory_arr(n);
            mass = memory_mass(n);
            printf("Выберите способ ввода:\n1)С клавиатуры\n2)Случайные числа\n");
            choose_input(arr, n, mass);
            printf("\nНачальный массив:\n\n");
            print_arr(arr, n);
            printf("\n\nОтсортированный слиянием массив:\n\n");
            merge(mass, n, &t1);
            mass = rememory_mass(mass, n);
            zamena(mass, arr, n);
            arr = rememory_arr(arr, n);
            print_arr(arr, n);
            bad_merge(mass, n, &t2);
            mass = rememory_mass(mass, n);
            zamena(mass, arr, n);
            printf("\n\nХудшая сортировка слиянием:\n\n");
            print_arr(arr, n);
            bubble(mass, n, &t3);
            zamena(mass, arr, n);
            mass = rememory_mass(mass, n);
            printf("\n\nОтсортированный пузырьком массив:\n\n");
            print_arr(arr, n);
            printf("\n\nВремя сортировки массива слиянием = %i(мс)\n", t1);
            printf("\nВремя худшей сортировки массива слиянием = %i(мс)\n", t2);
            printf("\nВремя сортировки массива пузырьком = %i(мс)\n", t3);
            libertad_arr(arr, mass);
        }
        else {
            int  m, n, ** matr;
            printf("Введите количество строк: ");
            input_n(&n);
            printf("Введите количество колонок: ");
            input_n(&m);
            matr = memory(n, m);
            printf("Выберите способ ввода:\n1)С клавиатуры\n2)Случайные числа\n");
            choose_inp(matr, n, m);
            printf("\nНачальная матрица:\n\n");
            print_matr(matr, n, m);
            vybor(matr, n, m);
            printf("\nОтсортированная матрица:\n\n");
            print_matr(matr, n, m);
            libertad(n, matr);
        }
        printf("\n\nХотите выбрать другое задание?\n1) Да\n2) Нет\n");
        while (scanf_s("%d", &p) != 1 || (p != 1 && p != 2) || getchar() != '\n') {
            printf("Ошибка. Попробуйте снова: ");
            rewind(stdin);
        }
    }
    return 0;
}
