#include <stdio.h>
#include <stdlib.h>

struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
};

int input(int min, int max);

void add_tree_element(struct Tree **root, int data);

void delete_tree_element(struct Tree *root);

void find_max_independent_set(struct Tree *root);

void print_tree(struct Tree *root, int spaces);
