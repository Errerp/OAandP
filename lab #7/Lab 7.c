#include "library.h"

int main() {
	setlocale(LC_ALL, "Russian");
	int v = 0;
	while(v != 2) {
		int choice;
		void (*fun) (char**, char**);
		char* line1, line2;
		printf("Выберите задание:\n1) Дана строка. Удалить все слова меньшие k букв\n2) Даны строки S и S0. Найти количество вхождений строки S0 в строку S.\n");
		while (scanf_s("%d", &choice) != 1 || (choice != 1 && choice != 2) || getchar() != '\n') {
			printf("Ошибка. Попробуйте снова: ");
			rewind(stdin);
		}
		if (choice == 1) {
			fun = first_task;
		}
		else {
			fun = second_task;
		}
		fun(&line1, &line2);
		printf("\n\nХотите выбрать другое задание?\n1) Да.\n2) Нет.\n\n");
		while (scanf_s("%d", &v) != 1 || (v != 1 && v != 2) || getchar() != '\n') {
			printf("Ошибка. Попробуйте снова: ");
			rewind(stdin);
		}
	}
	return 0;
}