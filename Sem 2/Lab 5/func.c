#include "func.h"

int input(int min, int max) {
    int x;
    while (scanf_s("%d", &x) != 1 || x < min || x > max || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    return x;
}

struct FILO *push(struct FILO *head, int num) {
    struct FILO *temp;
    temp = (struct FILO *) malloc(sizeof(struct FILO));
    temp->next = NULL;
    temp->data = num;
    if (head == NULL)
        head = temp;
    else {
        temp->next = head;
        head = temp;
    }

    return head;
}

void print_stack(struct FILO *head) {
    struct FILO *temp = head;

    while (temp != NULL) {
        printf(" %d |", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct FILO *find_max(struct FILO *head) {
    struct FILO *temp = head, *m = head->next;
    if (head != NULL) {
        int max = head->data;
        while (temp != NULL) {
            if (temp->data > max) {
                max = temp->data;
                m = temp->next;
            }
            temp = temp->next;
        }
        return m;
    }
}

int find_sum(struct FILO *head) {
    int sum = 0;
    struct FILO *temp = find_max(head);
    if (head != NULL) {
        while (temp != NULL) {
            sum += temp->data;
            temp = temp->next;
        }
        return sum;
    }
}

int check_ask(struct FILO *head, int a) {
    if (head->data <= a)
        return 1;
    else
        return 0;
}

int check_desc(struct FILO *head, int a) {
    if (head->data >= a)
        return 1;
    else
        return 0;
}


int cnt_FILO(struct FILO *head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }

    return count;
}

struct FILO *move_to_n(struct FILO *head, int n){
    while(head != NULL && n != 1){
        head = head->next;
        n--;
    }

    return head;
}

struct FILO *merge_FILO(struct FILO *h1, struct FILO *h2,struct FILO *h3){
    struct FILO *temp1 = h1;
    int size = cnt_FILO(h2);
    while (temp1 != NULL && size != 0){
        struct FILO *temp2 = move_to_n(h2, size);
        if(temp1->data >= temp2->data){
            h3 = push(h3, temp2->data);
            size--;
        }
        else{
            h3 = push(h3, temp1->data);
            temp1 = temp1->next;
        }
    }
    if(temp1 != NULL){
        while(temp1 != NULL){
            h3 = push(h3, temp1->data);
            temp1 = temp1->next;
        }
    }
    else if(size != 0){
        while(size != 0){
            struct FILO *temp2 = move_to_n(h2, size);
            h3 = push(h3, temp2->data);
            size--;
        }
    }
    return h3;
}

void task1() {
    int i = 0, size, t = 0;
    struct FILO *head = NULL;
    printf("\nInput max size: ");
    size = input(1, INT_MAX);
    while (t != 2) {
        printf("\nInput number: ");
        int num = input(INT_MIN, INT_MAX);
        head = push(head, num);
        i++;
        if (i != size) {
            printf("\nAdd another element to the stack?\n1.Yes\n2.No\n");
            t = input(1, 2);
        } else {
            break;
        }

    }

    printf("\nStack: |");
    print_stack(head);

    int sum = find_sum(head);
    printf("Sum after maximum == %d", sum);
    
    free(head);
}

void task2() {
    struct FILO *head1 = NULL;
    struct FILO *head2 = NULL;
    int num;

    printf("\n|Enter first stack|\nInput number: ");
    num = input(INT_MIN, INT_MAX);
    head1 = push(head1, num);
    while (true) {
        while(true) {
            printf("\nInput number: ");
            num = input(INT_MIN, INT_MAX);
            if(check_desc(head1, num) == 1){
                head1 = push(head1, num);
                break;
            }
            else
                printf("Error! Try again.");
        }
        printf("\nAdd another element to the stack?\n1.Yes\n2.No\n");
        int t = input(1, 2);
        if(t == 2)
            break;
    }

    printf("\n|Enter second stack|\nInput number: ");
    num = input(INT_MIN, INT_MAX);
    head2 = push(head2, num);
    while (true) {
        while(true) {
            printf("\nInput number: ");
            num = input(INT_MIN, INT_MAX);
            if(check_ask(head2, num) == 1){
                head2 = push(head2, num);
                break;
            }
            else
                printf("Error! Try again.");
        }
        printf("\nAdd another element to the stack?\n1.Yes\n2.No\n");
        int t = input(1, 2);
        if(t == 2)
            break;
    }

    struct FILO * head3;
    head3 = merge_FILO(head1,head2,head3);

    printf("\nFirst stack: |");
    print_stack(head1);
    printf("\nSecond stack: |");
    print_stack(head2);
    printf("\nThird descending stack: |");
    print_stack(head3);
    
    free(head1);
    free(head2);
    free(head3);
}
