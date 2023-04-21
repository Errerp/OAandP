#include "queue.h"

void input_FIFO(struct FIFO **head, struct FIFO **tail) {
    printf("\nInput max size of queue: ");
    int size = input(1, INT_MAX);

    int i = 0, t = 0;
    while (1) {
        printf("\nInput element of queue: ");
        int num = input(INT_MIN, INT_MAX);

        *tail = push(*tail, num);
        if (*head == NULL)
            *head = *tail;
        i++;

        if (i < size) {
            printf("\nAdd another element to the queue?\n1.Yes\n2.No\n");
            t = input(1, 2);
        }

        if (t == 2 || i == size)
            break;
    }
}

void free_FIFO(struct FIFO **head) {
    while (*head != NULL) {
        *head = pop(*head);
    }
    free(*head);
}

struct FIFO *push(struct FIFO *tail, int x) {
    struct FIFO *n;
    n = (struct FIFO *) malloc(sizeof(struct FIFO));
    n->next = NULL;
    n->data = x;
    if (tail == NULL) {
        tail = n;
    } else {
        tail->next = n;
        tail = n;
    }
    return tail;
}

struct FIFO *pop(struct FIFO *head) {
    struct FIFO *temp = head;
    if (head != NULL) {
        head = head->next;
        free(temp);
        return head;
    } else
        return NULL;
}

void print_FIFO(struct FIFO *head) {
    struct FIFO *p = head;
    int i = 0;
    while (p != NULL) {
        if (i != 0)
            printf("--> ");
        printf("%d ", p->data);
        p = p->next;
        i++;
    }
}

void print_first_negative(struct FIFO *head) {
    struct FIFO *p = head;
    int i = 0;
    while (p != NULL) {
        if (i != 0)
            printf("--> ");

        printf("%d ", p->data);

        if (p->data < 0) {
            p = p->next;
            int count = count_FIFO(p);
            printf("\n\nSize the remaining queue =  %d", count);
            break;
        }

        p = p->next;
        i++;
    }
}

int count_FIFO(struct FIFO *head) {
    struct FIFO *p = head;
    int count = 0;

    while (p != NULL) {
        count++;
        p = p->next;
    }

    return count;
}

int equality(struct FIFO *head1, struct FIFO *head2) {
    if(count_FIFO(head1) != count_FIFO(head2))
        return 0;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data)
            return 0;
        head1 = head1->next;
        head2 = head2->next;
    }
    return 1;
}

void task1() {
    struct FIFO *head = NULL;
    struct FIFO *tail = NULL;

    printf("\nInput max size of queue: ");
    int size = input(1, INT_MAX);

    int i = 0, t = 0;
    while (1) {
        printf("\nInput element of queue: ");
        int num = input(INT_MIN, INT_MAX);

        tail = push(tail, num);
        if (head == NULL)
            head = tail;
        i++;

        if (i < size) {
            printf("\nAdd another element to the queue?\n1.Yes\n2.No\n");
            t = input(1, 2);
        }

        if (t == 2 || i == size)
            break;
    }

    printf("\n\nQueue: ");
    print_FIFO(head);

    int count = count_FIFO(head);
    printf("\n\nSize of queue = %d", count);

    printf("\n\nOutput queue items up to the first negative (inclusive): ");
    print_first_negative(head);

    free_FIFO(&head);
}

void task3() {
    struct FIFO *head1 = NULL;
    struct FIFO *tail1 = NULL;
    input_FIFO(&head1, &tail1);

    struct FIFO *head2 = NULL;
    struct FIFO *tail2 = NULL;

    input_FIFO(&head2, &tail2);

    printf("\n\nFirst queue: ");
    print_FIFO(head1);

    printf("\n\nSecond queue: ");
    print_FIFO(head2);

    if (equality(head1, head2)) {
        printf("\n\nEqual");
    } else {
        printf("\n\nNot equal");
    }

    free_FIFO(&head1);
    free_FIFO(&head2);
}