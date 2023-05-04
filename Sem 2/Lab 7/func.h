#include <stdio.h>
#include <stdlib.h>

struct Tree {
    int value;
    struct Tree *Left;
    struct Tree *Right;
};

int input(int min, int max);

void add_tree_element(struct Tree **TreeRoot, int value);

void delete_tree_element(struct Tree *TreeRoot);

void find_max_independent_set(struct Tree *TreeRoot);

void print_tree(struct Tree *treePtr, int spaces);