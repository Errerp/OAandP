#include "library.h"

int main() {
	setlocale(LC_ALL, "Russian");
	int v = 0;
	while(v != 2) {
		int choice;
		void (*fun) (char**, char**);
		char* line1, line2;
		printf("�������� �������:\n1) ���� ������. ������� ��� ����� ������� k ����\n2) ���� ������ S � S0. ����� ���������� ��������� ������ S0 � ������ S.\n");
		while (scanf_s("%d", &choice) != 1 || (choice != 1 && choice != 2) || getchar() != '\n') {
			printf("������. ���������� �����: ");
			rewind(stdin);
		}
		if (choice == 1) {
			fun = first_task;
		}
		else {
			fun = second_task;
		}
		fun(&line1, &line2);
		printf("\n\n������ ������� ������ �������?\n1) ��.\n2) ���.\n\n");
		while (scanf_s("%d", &v) != 1 || (v != 1 && v != 2) || getchar() != '\n') {
			printf("������. ���������� �����: ");
			rewind(stdin);
		}
	}
	return 0;
}