#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false, true
} bool;

struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
};

int input(int min, int max);

void add_tree_element(struct Tree **root, int data);

void delete_tree_element(struct Tree *root);

void spiral(struct Tree *root);

bool print_level_left(struct Tree *root, int level);

bool print_level_right(struct Tree *root, int level);

void print_tree(struct Tree *root, int spaces);
