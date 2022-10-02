#include <stdio.h>

int main()
{
    int num, sec;
    int x = 0;

    for (int a = 0; a < 10; a++)
        for (int b = 0; b < 10; b++)
            for (int c = 0; c < 10; c++)
            {
                num = 1000 + a * 100 + b * 10 + c;
                sec = a * 1000 + b * 100 + c * 10 + 1;
                if (3 * num == sec)
                {
                    printf("The desired number - %d", num);
                    x++;
                }
            }
    if (x == 0)
    {
        printf("There is no such number");
    }
    getch();
    return 0;
}