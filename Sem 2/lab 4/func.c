#include "func.h"

void input(int *n, int min, int max) {
    while (!scanf("%d", n) || *n > max || *n < min || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
}

void input_string(char **str) {
    char c;
    int size = 1;
    *str = calloc(1, 1);
    while ((c = getchar()) != '\n') {
        (*str) = realloc(*str, size * sizeof(char));
        (*str)[size - 1] = c;
        size++;
    }
    (*str) = realloc(*str, size * sizeof(char));
    (*str)[size - 1] = '\0';

};

void print_shape(const Shapes shape) {
    printf("|%-20s |%-10d |%-10.2lf |%-10s|\n", shape.name, shape.square, shape.area, shape.shapeColor.color);
}

void add_shape(Shapes **arr, int *len, int square, char *name, Color shapeColor, double area) {
    Shapes newShapes = {square, name, shapeColor, area};
    (*arr) = realloc((*arr), ((*len) + 1) * sizeof(Shapes));
    (*arr)[(*len)] = newShapes;
    (*len)++;
}

void input_shape(Shapes **arr, int *len) {
    int choice = 0;
    char *name;
    Color shapeColor;
    int square;
    double area;
    int i = 0;

    while (1) {
        if(i != 0){
            printf("\n1.Enter one more shapes.\n2.Stop\n");
            input(&choice, 1, 2);
            if (choice == 2) {
                return;
            }
        }
        i++;

        printf("\nEnter name of shapes:");
        input_string(&name);

        printf("\nEnter square of shape:");
        input(&square, 1, INT_MAX);

        printf("\nEnter area for shape:");
        while(scanf_s("%lf", &area) != 1 || area < 1){
            printf("Error. Try again: ");
            rewind(stdin);
        }
        printf("\nEnter color of shapes:");
        scanf_s("%s", shapeColor.color);

        add_shape(arr, len, square, name, shapeColor, area);
    }
}

void print_all_shape(Shapes *arr, int len) {
    if(len != 0){
        printf("\n----------------------------------------------------------");
        printf("\n|%-20s |%-10s |%-10s |%-10s|\n", "Name", "Square", "Area", "Color");
        for (int i = 0; i < len; i++) {
            print_shape(arr[i]);
        }
        printf("----------------------------------------------------------\n");
    }
    else
        printf("The structure of the shapes is empty\n");
    getchar();
}

void remove_shape(Shapes **arr, int *len, const char *color) {
    int count = 0;
    for (int i = (*len) - 1; i >= 0; i--) {
        if (!strcmp((*arr)[i].shapeColor.color, color)) {
            count++;
            free((*arr)[i].name);
            for (int j = i; j < (*len) - 1; j++) {
                (*arr)[j] = (*arr)[j + 1];
            }
            (*len)--;
            *arr = realloc(*arr, (*len) * sizeof(Shapes));
        }
    }
    if(count == 0)
        printf("\nNo one shape with color: %s\n", color);
    else
        printf("\nSuccessfully deleted!\n");
    getchar();
}

ShapesArray find_shape_with_max_area(Shapes *shapeArray, int numSeries) {
    double maxArea = shapeArray[0].area;
    for (int i = 1; i < numSeries; i++) {
        if (shapeArray[i].area > maxArea) {
            maxArea = shapeArray[i].area;
        }
    }

    // Count how many Shapes structures have the max area
    int count = 0;
    for (int i = 0; i < numSeries; i++) {
        if (shapeArray[i].area == maxArea) {
            count++;
        }
    }

    Shapes *maxAreaArray = (Shapes *) malloc(count * sizeof(Shapes));

    // Copy the Shapes structures with the max area to the new array
    int j = 0;
    for (int i = 0; i < numSeries; i++) {
        if (shapeArray[i].area == maxArea) {
            maxAreaArray[j] = shapeArray[i];
            j++;
        }
    }
    ShapesArray result = {maxAreaArray, count};
    return result;
}

void task1(Shapes *arr, int len) {
    ShapesArray newArray = find_shape_with_max_area(arr, len);
    print_all_shape(newArray.arr, newArray.len);
}

void task2(Shapes **arr, int *len) {
    char* str = malloc(1);
    printf("\nEnter release color to delete:");
    input_string(&str);
    remove_shape(arr, len, str);
}

void menu(Shapes **arr, int *len) {
    int choice;
    while (1) {
        printf("\n------------------------------\n");
        printf("1.Add new shapes\n2.Print all shapes");
        printf("\n3.Show shapes with max area\n4.Remove shapes with special color\n5.Exit");
        printf("\n------------------------------\n\n");
        input(&choice, 1, 5);
        switch (choice) {
            case 1:
                input_shape(arr, len);
                break;
            case 2:
                print_all_shape(*arr, *len);
                break;
            case 3:
                task1(*arr, *len);
                break;
            case 4:
                task2(arr, len);
                break;
            case 5:
                free(*arr);
                exit(0);
        }
    }
}
