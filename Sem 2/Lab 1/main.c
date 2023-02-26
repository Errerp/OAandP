#include "func.h"

int main(int argc, char **argv) {
    if(argv[1] == NULL){
        printf("\nFilename not found\n");
        return 0;
    }

    int n, m, t = 0;

    if(argv[2] != NULL){
        printf("\nFirst file:\n");
    }
    printf("Input numbers of elements: ");
    n = input(1, INT_MAX);
    printf("Fill file: \n");
    fill_file(argv[1], n);
    if(argv[2] != NULL){
        printf("\nSecond file:\nInput numbers of elements: ");
        m = input(1, INT_MAX);
        printf("Fill file: \n");
        fill_file(argv[2], m);
    }

    while(t != 2) {
        int choose;
        printf("\nAvailable tasks:\n1.Using the keyboard, fill the file with integers.");
        printf("\n2.Calculate how many elements are in the file that are greater than the sum of all the previous ones.");
        if (argv[2] != NULL) {
            printf("\n3.Perform descending sorting for two binary files.\n");
            printf("4.From two binary files filled in descending order, form a third filled in descending order.\n");
            printf("Choose task: ");
            choose = input(1, 4);
        } else {
            printf("\nChoose task: ");
            choose = input(1, 2);
        }

        if (choose == 1) {
            task1(argv[1], n);
        } else if (choose == 2) {
            task2(argv[1], n);
        } else {
            if (choose == 3) {
                task3(argv[1], n, argv[2], m);
            } else {
                task4(argv[1], n, argv[2], m);
            }
        }
        printf("\n\nChoose another task?\n1.Yes\n2.No\n");
        t = input(1,2);
    }
    return 0;
}
