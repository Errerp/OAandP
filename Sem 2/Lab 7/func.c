#include "func.h"

int input(int min, int max) {
    int x;
    while (scanf_s("%d", &x) != 1 || x < min || x > max || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    return x;
}

void add_tree_element(struct Tree **TreeRoot, int value) {
    if (!(*TreeRoot)) {
        struct Tree *NewNode = calloc(1, sizeof(struct Tree));
        NewNode->value = value;
        NewNode->Left = NULL;
        NewNode->Right = NULL;
        *TreeRoot = NewNode;
        return;
    }
    if (value > (*TreeRoot)->value) {
        add_tree_element(&((*TreeRoot)->Right), value);
    } else {
        add_tree_element(&((*TreeRoot)->Left), value);
    }
}

void delete_tree_element(struct Tree *TreeRoot) {
    if (TreeRoot->Right != NULL) {
        delete_tree_element(TreeRoot->Right);
    }
    if (TreeRoot->Left != NULL) {
        delete_tree_element(TreeRoot->Left);
    }
    free(TreeRoot);
}

void find_max_independent_set(struct Tree *TreeRoot){

}

void print_tree(struct Tree *treePtr, int spaces) {
    int loop;
    while (treePtr != NULL) {
        print_tree(treePtr->Right, spaces + 4);
        for (loop = 1; loop <= spaces; loop++) {
            printf(" ");
        }
        printf("%d\n", treePtr->value);
        print_tree(treePtr->Left, spaces + 4);
        treePtr = NULL;
    }
}
