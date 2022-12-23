#include <stdio.h>
#include <math.h>
#include "locale.h"

int main()
{
	int p = 1;
	while (p != 2) {
		setlocale(LC_ALL, "Russian");
		int choice;
		printf("Выберите задание: ");
		while (scanf_s("%d", &choice) != 1 || (choice != 1 && choice != 2 && choice != 3 && choice != 4) || getchar() != '\n') {
			printf("Ошибка. Попробуйте снова: ");
			rewind(stdin);
		}
		if (choice == 1) {
			int num, sec;
			int count = 0;

			for (int a = 0; a < 10; a++)
				for (int b = 0; b < 10; b++)
					for (int c = 0; c < 10; c++)
					{
						num = 1000 + a * 100 + b * 10 + c;
						sec = a * 1000 + b * 100 + c * 10 + 1;
						if (3 * num == sec)
						{
							printf("\nИскомое число %d", num);
							count++;
						}
					}
			if (count == 0)
			{
				printf("\nТакого числа не существует");
			}
		}
		else if (choice == 2) {
			int x, y, z;
			printf("\nНомер машины: ");
			for (int i = 0; i < 10; i++)
				for (int k = 1; k < 10; k++)
				{
					if (i + k == 15)
					{

						x = k * 1000 + i * 100 + i * 10 + k;
						y = i * 1000 + i * 100 + k * 10 + k;
						z = i * 1000 + k * 100 + i * 10 + k;
						if (x % 7 == 0 && x % 11 == 0 && x % 2 == 0)
						{
							printf("%d", x);
						}
						if (y % 7 == 0 && y % 11 == 0 && y % 2 == 0)
						{
							printf("%d", y);
						}
						if (z % 7 == 0 && z % 11 == 0 && z % 2 == 0)
						{
							printf("%d", z);
						}



					}
				}
		}
		else{
			int count = 0;
			int fib = 1;
			int n;
			printf("\nВведите число: ");
			while (scanf_s("%d", &n) != 1 || getchar() != '\n') {
				printf("Ошибка. Попробуйте снова: ");
				rewind(stdin);
			}
			for (int i = 1; i <= n; i++)
			{
				if (i == count + fib)
				{
					count = fib;
					fib = i;
				}
			}
			if (n == fib || n == 0)
			{
				printf("True");
			}
			else
			{
				printf("False");
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
