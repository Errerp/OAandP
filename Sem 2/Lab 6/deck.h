#include "func.h"

struct Deck {
    int data;
    struct Deck *next;
    struct Deck *prev;
};

void task2();

struct Deck *create_right(struct Deck *tail, int x);

struct Deck *create_left(struct Deck *tail, int x);

void print_Deck(struct Deck *head);

int count_Deck(struct Deck *head);

void print_prev_negative(struct Deck *tail);

struct Deck *pop_Deck(struct Deck *head);

void free_Deck(struct Deck **head);