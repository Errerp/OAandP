#include "func.h"

int main() {
    while (1) {
        struct Tree *root = NULL;
        int size = 0;
        while (1) {
            printf("Enter %d node value: ", size + 1);
            int n;
            scanf("%d", &n);
            add_tree_element(&root, n);
            size++;
            printf("\nAdd another element to the tree?\n1.Yes\n2.No\n");
            int t = input(1, 2);

            if (t == 2)
                break;
        }
        printf("\nPrinted Tree:\n");
        print_tree(root, 5);
        delete_tree_element(root);

        printf("You want repeat task?\n1.Yes\n2.No\n");
        int repeat = input(1, 2);

        if (repeat == 2)
            break;
    }
    return 0;
}
