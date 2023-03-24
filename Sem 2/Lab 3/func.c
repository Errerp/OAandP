#include "func.h"

struct number{
    unsigned int x : 9;
};

union code{
    struct number point;
    struct {
        unsigned a0 : 1;
        unsigned a1 : 1;
        unsigned a2 : 1;
        unsigned a3 : 1;
        unsigned a4 : 1;
        unsigned a5 : 1;
        unsigned a6 : 1;
        unsigned a7 : 1;
        unsigned a8 : 1;
    } byte;
};

struct shapes {
    char* name;
    int square;
    struct {
        double area;
        char color[10];
    } SecStruct;
};

int input(int min, int max) {
    int x;
    while (scanf_s("%d", &x) != 1 || x < min || x > max || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    return x;
}

void input_shape(struct shapes* shape, int size) {
    for (int i = 0; i < size; i++) {
        printf("\nInput name for shape %d: ", i + 1);
        char name[50];
        scanf_s("%s", &name);
        shape[i].name = malloc(strlen(name) + 1);
        strcpy(shape[i].name, name);

        printf("\nInput square for shape %d: ", i + 1);
        shape[i].square = input(1,INT_MAX);

        printf("\nInput area for shape %d: ", i + 1);
        while(scanf_s("%lf", &shape[i].SecStruct.area) != 1 || shape[i].SecStruct.area < 1){
            printf("Error. Try again: ");
            rewind(stdin);
        }

        printf("\nInput color of shape %d: ", i + 1);
        scanf_s("%s", &shape[i].SecStruct.color);
    }
}
void output_shape(struct shapes* shape, int size) {
    printf("\n|%-20s |%-10s |%-10s |%-10s|\n", "Name", "Square", "Area", "Color");
    for (int i = 0; i < size; i++) {
        printf("|%-20s |%-10d |%-10.2lf |%-10s|\n", shape[i].name, shape[i].square, shape[i].SecStruct.area, shape[i].SecStruct.color);
    }
}

void find_sqr_shape(struct shapes* shape, int size, int sqr) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (shape[i].square < sqr){
            count++;
        }
    }
    if(count == 0){
        printf("\nNo one shape with an area less than the specified one: %d\n", sqr);

    }
    else {
        printf("\nFigures of a smaller square %d:\n\n", sqr);
        printf("\n|%-20s |%-10s |%-10s |%-10s|\n", "Name", "Square", "Area", "Color");
        for (int i = 0; i < size; ++i) {
            if (shape[i].square < sqr) {
                printf("|%-20s |%-10d |%-10.2lf |%-10s|\n", shape[i].name, shape[i].square, shape[i].SecStruct.area,
                       shape[i].SecStruct.color);
            }
        }
    }
}

void delete_shape_with_name(struct shapes** shape_ptr, int* size_ptr, char* name) {
    struct shapes* shape = *shape_ptr;
    int size = *size_ptr;
    int i, j, count = 0;
    for (i = 0; i < size; i++) {
        if (strcmp(shape[i].name, name) == 0) {
            count++;
            free(shape[i].name);
            for (j = i; j < size - 1; j++) {
                shape[j] = shape[j + 1];
            }
            size--;
            i--;
        }
    }
    *shape_ptr = realloc(shape, size * sizeof(struct shapes));
    *size_ptr = size;
    if(count == 0)
        printf("\nNo one shape with name: %s\n", name);
    else if(size == 0)
        printf("\nThere is not a single shape left\n");
    else
        output_shape(shape, size);
}

void task1(){
    printf("Input number (511 - max): ");
    int num = input(1,511);

    struct number center = { num };
    union code c;
    c.point = center;

    printf("\nStart binary code:\n\n256 \t 128 \t 64 \t 32 \t 16 \t 8 \t 4 \t 2 \t 1 \n");
    printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", c.byte.a8, c.byte.a7, c.byte.a6, c.byte.a5, c.byte.a4, c.byte.a3, c.byte.a2, c.byte.a1, c.byte.a0);

    c.byte.a0 = c.byte.a1;
    c.byte.a1 = c.byte.a2;
    c.byte.a2 = c.byte.a3;
    c.byte.a3 = c.byte.a4;
    c.byte.a4 = c.byte.a5;
    c.byte.a5 = c.byte.a6;
    c.byte.a6 = c.byte.a7;
    c.byte.a7 = c.byte.a8;
    c.byte.a8 = 0;

    num = c.byte.a0 * 1 + c.byte.a1 * 2 + c.byte.a2 * 4 + c.byte.a3 * 8 + c.byte.a4 * 16 + c.byte.a5 * 32 + c.byte.a6 * 64 + c.byte.a7 * 128;
    printf("\nRemainder binary code:\n\n256 \t 128 \t 64 \t 32 \t 16 \t 8 \t 4 \t 2 \t 1 \n");
    printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", c.byte.a8, c.byte.a7, c.byte.a6, c.byte.a5, c.byte.a4, c.byte.a3, c.byte.a2, c.byte.a1, c.byte.a0);
    printf("\n\nRemainder: %d\n", num);

    /*int ost = num >> 1;
    struct number sec = { ost };
    union code s;
    c.point = sec;

    printf("\nRemainder binary code:\n\n256 \t 128 \t 64 \t 32 \t 16 \t 8 \t 4 \t 2 \t 1 \n");
    printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", c.byte.a8, c.byte.a7, c.byte.a6, c.byte.a5, c.byte.a4, c.byte.a3, c.byte.a2, c.byte.a1, c.byte.a0);

    printf("\n\nStart number: %d\nRemainder: %d\n", num, ost);*/
}

void task2(){
    int size, sqr;
    char name[50];
    printf("\nInput number of shapes: ");
    size = input(1, INT_MAX);
    struct shapes* shape = malloc(size * sizeof(struct shapes));

    input_shape(shape, size);
    output_shape(shape, size);

    printf("\nInput amount square: ");
    sqr = input(1, INT_MAX);
    find_sqr_shape(shape, size, sqr);

    printf("\nPrint all the shapes again?\n1.Yes\n2.No\n ");
    int num = input(1,2);
    if(num = 1)
        output_shape(shape, size);

    printf("\nInput name of shape: ");
    scanf_s("%s", &name);
    delete_shape_with_name(&shape, &size, name);

    free(shape);
}
