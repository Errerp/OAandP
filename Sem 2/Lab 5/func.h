#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct FILO {
    int data;
    struct FILO *next;
};

int input(int min, int max);
struct FILO *push(struct FILO* , int num);
void print_stack(struct FILO* );
struct FILO *find_max(struct FILO *);
int find_sum(struct FILO *);
void task1();
void task2();