#include <stdio.h>
#include <math.h>
int main()
{
    double x, t, result;
    printf("\n¬ведите число 1 ");
    scanf_s("%lf", &x);
    printf("\n¬ведите число 2 ");
    scanf_s("%lf", &t);
    printf("\nVashe srednee ariphmeticheskoe: ");
    result = round((x + t) / 2 * 1000) / 1000;
    printf("%.3lf", result);
    result = round(sqrt(x * t) * 1000) / 1000;
    printf("\nVashe srednee geometricheskoe: ");
    printf("%.3lf", result);
}
