#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct number;
union code;
struct shapes;
int input(int min, int max);
void input_shape(struct shapes* shape, int size);
void output_shape(struct shapes* shape, int size);
void find_sqr_shape(struct shapes* shape, int size, int sqr);
void delete_shape_with_name(struct shapes** shape_ptr, int* size_ptr, char* name);
void task1();
void task2();
