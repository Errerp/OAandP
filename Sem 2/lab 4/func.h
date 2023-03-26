#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef union {
    char color[10];
} Color;

typedef struct {
    int square;
    char *name;
    Color shapeColor;
    double area;
} Shapes;


typedef struct {
    Shapes *arr;
    int len;
} ShapesArray;

void input(int *n, int min, int max);
void input_string(char **str);
void print_shape(const Shapes shape);
void add_shape(Shapes **arr, int *len, int square, char *name, Color shapeColor, double area);
void input_shape(Shapes **arr, int *len);
void print_all_shape(Shapes *arr, int len);
void remove_shape(Shapes **arr, int *len, const char *date);
ShapesArray find_shape_with_max_area(Shapes *shapeArray, int numSeries);
void task1(Shapes *arr, int len);
void task2(Shapes **arr, int *len);
void menu(Shapes **arr, int *len);
