#include "queue.h"
#include "deck.h"

int main() {
    int t = 1, choose;
    while (t != 2) {
        printf("\n-----------------------------------------------------------------------------------");
        printf("\n1.Output queue items up to the first negative (inclusive).\nPrint the size of the remaining queue.");
        printf("\n-----------------------------------------------------------------------------------");
        printf("\n2.Print the elements of the deck on the right up to the first negative (inclusive).\nPrint the size of the remaining deck.");
        printf("\n-----------------------------------------------------------------------------------");
        printf("\n3.Check the equality of the two queues.");
        printf("\n-----------------------------------------------------------------------------------");
        printf("\nChoose task: ");
        choose = input(1, 3);
        switch (choose) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
        }
        printf("\n\nChoose another task?\n1.Yes\n2.No\n");
        t = input(1, 2);
    }
    return 0;
}
