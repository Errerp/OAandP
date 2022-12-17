#include "library.h"

int poisk(int len, char* s0, char* s) {
	for (int i = 0; i < len; i++) {
		if (s0[i] != s[i])
			return 0;
	}
	return 1;
}
void print(char* str) {
	for (int i = 0; str[i] != '\0'; i++)
		printf("%c", str[i]);
}
char* rememory(char* str, int size, int sizenew) {
	char* str1 = (char*)malloc(sizenew);
	for (int i = 0; (i < size && i < sizenew); i++)
		*(str1 + i) = *(str + i);
	*(str1 + sizenew) = '\0';
	return str1;
}
int letter(char* line, int i) {
	if ((*(line + i) >= 'a' && *(line + i) <= 'z') || (*(line + i) >= 'A' && *(line + i) <= 'Z'))
		return 1;
	return 0;
}
void del(char* line, int i, int step) {
	for (int j = i; *(line + j + step - 1) != '\0'; j++) {
		*(line + j) = *(line + j + step);
	}
}
void first_task(char** line, char** line2) {
	int k, len = 1;
	printf("Введите k: ");
	while (scanf_s("%d", &k) != 1 || getchar() != '\n') {
		printf("Ошибка. Попробуйте снова: \n");
		rewind(stdin);
	}
	printf("Введите строку: \n");
	*line = (char*)calloc(len, sizeof(char));
	for (int i = 0; ; i++) {
		*(*line + i) = getchar();
		if (*(*line + i) == '\n') {
			len = i;
			*(*line + i) = '\0';
			break;
		}
		else {
			len = i + 1;
			*line = rememory(*line, len, (len + 1) * sizeof(char));
		}
	}
	int end = 0, start = 0;
	for (int i = len; i >= 0; i--) {
		if (!letter(*line, i) && letter(*line, i - 1))
			end = i - 1;
		if (letter(*line, i) && !letter(*line, i - 1)) {
			start = i;
			if (end - start + 1 < k) {
				del(*line, start, end - start + 1);
				len = len - end + start - 1;
			}
			end = 0, start = 0;
		}
	}
	*line = rememory(*line, len, len * (sizeof(char)));
	for (int i = 0; line[0][i] != '\0'; i++)
		printf("%c", line[0][i]);
}
void second_task(char** line1, char** line2) {
	int len = 1, len2 = 1, count = 0;
	printf("Введите строку: \n");
	*line1 = (char*)calloc(len, sizeof(char));
	for (int i = 0; ; i++) {
		*(*line1 + i) = getchar();
		if (*(*line1 + i) == '\n') {
			len = i;
			*(*line1 + i) = '\0';
			break;
		}
		else {
			len = i + 1;
			*line1 = rememory(*line1, len, (len + 1) * sizeof(char));
		}
	}
	printf("Введите 2 строку: \n");
	*line2 = (char*)calloc(len2, sizeof(char));
	for (int i = 0; ; i++) {
		*(*line2 + i) = getchar();
		if (*(*line2 + i) == '\n') {
			len2 = i;
			*(*line2 + i) = '\0';
			break;
		}
		else {
			len2 = i + 1;
			*line2 = rememory(*line2, len2, (len2 + 1) * sizeof(char));
		}
	}
	for (int i = 0; i < len - len2 + 1; i++) {
		if (poisk(len2, *line2, *line1 + i)) {
			count++;
		}
	}
	printf("Кол-во вхождений второй строки в первую: %d", count);
}