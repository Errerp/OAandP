#include "func.h"

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
        printf("Enter name for shape %d: ", i + 1);
        char name[50];
        scanf_s("%s", &name);
        shape[i].name = malloc(strlen(name) + 1);
        strcpy(shape[i].name, name);

        printf("Enter square for shape %d: ", i + 1);
        shape[i].square = input(1,INT_MAX);

        printf("Enter area for shape %d: ", i + 1);
        while(scanf_s("%lf", &shape[i].SecStruct.area) != 1 || shape[i].SecStruct.area < 1){
            printf("Error. Try again: ");
            rewind(stdin);
        }
        
        printf("Enter color of shape %d: ", i + 1);
        scanf_s("%s", &shape[i].SecStruct.color);
    }
}

void output_shape(struct shapes* shape, int size) {
    printf("%-20s %-10s %-10s %-15s\n", "Name", "Square", "Area", "Color");
    for (int i = 0; i < size; i++) {
        printf("%-20s %-10d %-10.2lf %-15s\n", shape[i].name, shape[i].square, shape[i].SecStruct.area, shape[i].SecStruct.color);
    }
}

void find_sqr_shape(struct shapes* shape, int size, int sqr) {
    printf("Figures of a smaller square %d:\n", sqr);
    for (int i = 0; i < size; ++i) {
        if (shape[i].square < sqr) printf("%s\n", shape[i].name);
    }
}

void delete_shape_with_name(struct shapes** shape_ptr, int* size_ptr, char* name) {
    struct shapes* shape = *shape_ptr;
    int size = *size_ptr;
    int i, j;
    for (i = 0; i < size; i++) {
        if (strcmp(shape[i].name, name) == 0) {
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
}
void task1(){

}

void task2(){
    int size, sqr;
    char name[50];
    printf("Enter number of shapes: ");
    size = input(1, INT_MAX);
    struct shapes* shape = malloc(size * sizeof(struct shapes));
    input_shape(shape, size);
    output_shape(shape, size);
    printf("Input amount square: ");
    sqr = input(1, INT_MAX);
    find_sqr_shape(shape, size, sqr);
    printf("Input name of shape: ");
    scanf_s("%s", &name);
    delete_shape_with_name(&shape, &size, name);
    output_shape(shape, size);
}