#include "func.h"

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	if (argc == 1) {
		printf("������.��� ���������");
		return 0;
	}
	quickSort(argv, 0, argc - 1 - 1, &count_chet_words);
	printf("���������� ����� ������:\n");
	type(argc, argv);
	return 0;
}