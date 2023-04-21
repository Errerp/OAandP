#include "func.h"

struct FIFO {
    int data;
    struct FIFO *next;
};

int input(int min, int max);

void input_FIFO(struct FIFO **head, struct FIFO **tail);

void free_FIFO(struct FIFO **head);

struct FIFO *push(struct FIFO *tail, int x);

struct FIFO *pop(struct FIFO *head);

void print_FIFO(struct FIFO *head);

void print_first_negative(struct FIFO *head);

int count_FIFO(struct FIFO *head);

int equality(struct FIFO *head1, struct FIFO *head2);

void task1();

void task3();