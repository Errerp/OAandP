#include <stdio.h>

int main()
{
	int a;
	printf("Enter the semester number - ");
	scanf_s("%d", &a);
	printf("This semester you are studying disciplines:\n");
	switch (a)
	{
	case 1:
		printf("Ñomputer science\n");
		printf("English");
		break;
	case 2:
		printf("Ñomputer science\n");
		printf("English");
		break;
	case 3:
		printf("Mathematics\n");
		printf("Cultural studies\n");
		printf("English");
		break;
	case 4:
		printf("Mathematics\n");
		printf("Cultural studies\n");
		printf("English");
		break;
	}
	getch();
	return 0;
}