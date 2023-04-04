#include <stdlib.h>
#include <stdio.h>

enum bool{
    false, true
};
struct FILO {
    int data;
    struct FILO *next;
};

int input(int min, int max);
struct FILO *push(struct FILO* , int num);
void print_stack(struct FILO* );
struct FILO *find_max(struct FILO *);
int find_sum(struct FILO *);
int check_ask(struct FILO *, int a);
int check_desc(struct FILO *, int a);
int cnt_FILO(struct FILO *);
struct FILO *move_to_n(struct FILO *, int n);
struct FILO *merge_FILO(struct FILO *, struct FILO *, struct FILO *);
void task1();
void task2();
