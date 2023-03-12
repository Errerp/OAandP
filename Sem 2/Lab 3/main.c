#include "func.h"

int main() {
    int t = 1, choose;
    while(t != 2){
        printf("\n1.Find and output the remainder of the division of an integer by 2 without performing division and without using the operation of taking the remainder of the division.");
        printf("\n2.Find shapes with an area less than the specified one. Delete shapes with the specified name.");
        printf("\nChoose task: ");
        choose = input(1, 2);
        switch (choose) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
        }
        printf("\n\nChoose another task?\n1.Yes\n2.No\n");
        t = input(1,2);
    }
    return 0;
}