#include "func.h"

int input(int min, int max) {
    int x;
    while (scanf_s("%d", &x) != 1 || x < min || x > max || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    return x;
}
struct FILO *push(struct FILO* head, int num){
    struct FILO *temp;
    temp = (struct FILO *)malloc(sizeof(struct FILO));
    temp->next = NULL;
    temp->data = num;
    if (head == NULL)
        head = temp;
    else
    {
        temp->next = head;
        head = temp;
    }

    return head;
}

void print_stack(struct FILO* head){
    struct FILO *temp = head;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct FILO *find_max(struct FILO *head){
    struct FILO *temp = head, *m = head -> next;
    if(head != NULL){
        int max = head -> data;
        while(temp != NULL){
            if(temp -> data > max){
                max = temp -> data;
                m = temp -> next;
            }
            temp = temp -> next;
        }
        return m;
    }
}
int find_sum(struct FILO *head){
    int sum = 0;
    struct FILO *temp = find_max(head);
    if(head != NULL){
        while(temp != NULL){
            sum += temp -> data;
            temp = temp -> next;
        }
        return sum;
    }
}

void task1(){
    int i = 0, size, t = 0;
    struct FILO *head = NULL;
    printf("\nInput max size: ");
    size = input(1, INT_MAX);
    while(t != 2){
        printf("\nInput number: ");
        int num = input(INT_MIN,INT_MAX);
        head = push(head, num);
        i++;
        if(i != size) {
            printf("\nAdd another element to the stack?\n1.Yes\n2.No\n");
            t = input(1, 2);
        } else {
            break;
        }

    }

    printf("\nStack: ");
    print_stack(head);

    int sum = find_sum(head);
    printf("Sum == %d", sum);
}

void task2(){

}
