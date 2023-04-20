#include <stdio.h>
#include <stdlib.h>

typedef struct LIFO {
    char info;
    struct FILO *next;
};

typedef struct FILO {
    double data;
    struct FILO *next;
};



void push_double(struct FILO **head, double data);
double pop_double(struct FILO **head);
int operator(char c);
void push_char(struct LIFO **head, char data);
char pop_char(struct LIFO **head);
int priority(char c);
double operate(double num1, double num2, char c);
double decision(char *exp);
int sign(char c);
int digit(char c);
double number(char c);
int find_error(char *exp);