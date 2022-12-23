#include <stdio.h>
#include <math.h>
#include "locale.h"

int main()
{
	int x = 1;
	while (x != 2) {
		setlocale(LC_ALL, "Russian");
		int choice;
		printf("Выберите задание:\n1) Ввести радиус круга. Найти длину окружности и площадь круга, ограниченного этой окружностью. Результат вывести с точностью до двух знаков после запятой.\n2) Даны три числа a, b, c. Значение наибольшего из них присвойте переменной d.\n3) Определить, какая из точек плоскости A(x1,y1), B(x2,y2),  C(x3,y3) ближе к началу координат.\n");
		printf("4) Дан список дисциплин, изучаемых в БГУИР и номер семестра, когда они изучаются. Составить программу, которая бы по номеру семестра выдавала бы список изучаемых дисциплин.\nИнформатика-2,1\nКультурология-3,4\nМатематика-4,3\nИн.язык-4,1,2,3\n");
		while (scanf_s("%d", &choice) != 1 || (choice != 1 && choice != 2 && choice != 3 && choice != 4) || getchar() != '\n') {
			printf("Ошибка. Попробуйте снова: ");
			rewind(stdin);
		}
		if (choice == 1) {
			float pi = 3.14;
			float rad = 0;
			printf("Введите радиус: ");
			scanf_s("%f", &rad);
			float length = 2 * pi * rad;
			float area = pi * rad * rad;
			printf("Длина окржности: %.2f \n", length);
			printf("Площадь круга: %.2f \n", area);
		}
		else if (choice == 2) {
			int a, b, c;
			printf("Введите 3 числа: ");
			scanf_s("%d%d%d", &a, &b, &c);
			int d = a;
			if (b > d)
			{
				d = b;
			}
			if (c > d)
			{
				d = c;
			}
			printf("Большее число: %d", d);
		}
		else if (choice == 3) {
			int x1, x2, x3, y1, y2, y3;
			printf("Введите координаты точки A: \n");
			scanf_s("%d%d", &x1, &y1);
			printf("Введите координаты точки B: \n");
			scanf_s("%d%d", &x2, &y2);
			printf("Введите координаты точки C: \n");
			scanf_s("%d%d", &x3, &y3);
			float A = sqrt(x1 * x1 + y1 * y1);
			float B = sqrt(x2 * x2 + y2 * y2);
			float C = sqrt(x3 * x3 + y3 * y3);
			if (A <= B && A <= C) {
				printf("Точка A(%d;%d) ближе к началу координат\n", x1, y1);
			}
			if (B <= A && B <= C) {
				printf("Точка B(%d;%d) ближе к началу координат\n", x2, y2);
			}
			if (C <= B && C <= A) {
				printf("Точка C(%d;%d) ближе к началу координат", x3, y3);
			}
		}
		else {

			int a;
			printf("Введите номер семестра: ");
			while (scanf_s("%d", &a) != 1 || (a != 1 && a != 2 && a != 3 && a != 4) || getchar() != '\n') {
				printf("Ошибка. Попробуйте снова: ");
				rewind(stdin);
			}
			printf("Список дисциплин в семестре:\n");
			switch (a)
			{
			case 1:
				printf("Информатика\n");
				printf("Ин.язык");
				break;
			case 2:
				printf("Информатика\n");
				printf("Ин.язык");
				break;
			case 3:
				printf("Математика\n");
				printf("Культурология\n");
				printf("Ин.язык");
				break;
			case 4:
				printf("Математика\n");
				printf("Культурология\n");
				printf("Ин.язык");
				break;
			}
		}
		printf("\n\nХотите выбрать другое задание?\n1) Да\n2) Нет\n");
		while (scanf_s("%d", &x) != 1 || (x != 1 && x != 2) || getchar() != '\n') {
			printf("Ошибка. Попробуйте снова: ");
			rewind(stdin);
		}
	}
	return 0;
}
