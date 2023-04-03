#include "func.h"

int main() {
    int t = 1, choose;
    while(t != 2){
        printf("\n1.Create a stack for integers. The maximum stack size is entered from the screen. Find the sum after the maximum element of the stack.");
        printf("\n2.Create two stacks for integers. The first stack is to organize the input in descending order, the second stack is to organize the input in ascending order. Without sorting and flipping the original stacks, form a third stack ordered in descending order.");
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