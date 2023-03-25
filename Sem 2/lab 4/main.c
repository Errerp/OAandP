#include "func.h"

int main() {
    int len = 0;
    Shapes* arr = malloc(sizeof(Shapes));
    menu(&arr, &len);

    return 0;
}
