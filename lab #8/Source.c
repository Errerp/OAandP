#include "func.h"

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	if (argc == 1) {
		printf("Ошибка.Нет аргумента");
		return 0;
	}
	quick_sort(argv, 1, argc - 1, &count_chet_words);
	printf("Сортировка строк Хоаром:\n");
	type(argc, argv);
	return 0;
}
