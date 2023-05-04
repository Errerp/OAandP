#include "func.h"

int input(int min, int max) {
    int x;
    while (scanf_s("%d", &x) != 1 || x < min || x > max || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    return x;
}

void add_tree_element(struct Tree **root, int data) {
    if (!(*root)) {
        struct Tree *NewNode = calloc(1, sizeof(struct Tree));
        NewNode->data = data;
        NewNode->left = NULL;
        NewNode->right = NULL;
        *root = NewNode;
        return;
    }
    if (data > (*root)->data) {
        add_tree_element(&((*root)->right), data);
    } else {
        add_tree_element(&((*root)->left), data);
    }
}

void delete_tree_element(struct Tree *root) {
    if (root->right != NULL) {
        delete_tree_element(root->right);
    }
    if (root->left != NULL) {
        delete_tree_element(root->left);
    }
    free(root);
}

void find_max_independent_set(struct Tree *root) {

}

void print_tree(struct Tree *root, int spaces) {
    int loop; // loop counter
    while (root != NULL) {
        print_tree(root->right, spaces + 4);
        for (loop = 1; loop <= spaces; loop++) {
            printf(" ");
        }
        printf("%d\n", root->data);
        print_tree(root->left, spaces + 4);
        root = NULL;
    }

}
