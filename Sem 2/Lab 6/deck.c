#include "deck.h"

struct Deck *create_right(struct Deck *tail, int x) {
    struct Deck *n;
    n = (struct Deck *) malloc(sizeof(struct Deck));
    n->next = NULL;
    n->prev = NULL;
    n->data = x;
    if (tail == NULL) {
        tail = n;
    } else {
        n->prev = tail;
        tail->next = n;

        tail = n;
    }
    return tail;
}

struct Deck *create_left(struct Deck *head, int x) {
    struct Deck *n;
    n = (struct Deck *) malloc(sizeof(struct Deck));
    n->next = NULL;
    n->prev = NULL;
    n->data = x;
    if (head == NULL) {
        head = n;
    } else {
        n->next = head;
        head->prev = n;

        head = n;
    }
    return head;
}

void print_Deck(struct Deck *head) {
    struct Deck *p = head;
    int i = 0;
    while (p != NULL) {
        if (i != 0)
            printf("--> ");
        printf("%d ", p->data);
        p = p->next;
        i++;
    }
}

int count_Deck(struct Deck *tail) {
    struct Deck *p = tail;
    int count = 0;

    while (p != NULL) {
        count++;
        p = p->prev;
    }

    return count;
}

void print_prev_negative(struct Deck *tail) {
    struct Deck *p = tail;
    int i = 0;
    while (p != NULL) {
        if (i != 0)
            printf("<--");

        printf(" %d ", p->data);

        if (p->data < 0) {
            p = p->prev;
            int count = count_Deck(p);
            printf("\n\nSize the remaining deck =  %d", count);
            break;
        }

        p = p->prev;
        i++;
    }
}

struct Deck *pop_Deck(struct Deck *head) {
    struct Deck *temp = head;
    if (head != NULL) {
        head = head->next;
        free(temp);
        return head;
    } else
        return NULL;
}

void free_Deck(struct Deck **head) {
    while (*head != NULL) {
        *head = pop_Deck(*head);
    }
    free(*head);
}

void task2() {
    struct Deck *head = NULL;
    struct Deck *tail = NULL;

    printf("\nInput max size of queue: ");
    int size = input(1, INT_MAX);

    int i = 0, t = 0;
    while (1) {
        if (i == 0) {
            printf("\nInput element of queue: ");
            int num = input(INT_MIN, INT_MAX);

            tail = create_right(tail, num);
            if (head == NULL)
                head = tail;
        } else {
            printf("\nInput element of queue: ");
            int num = input(INT_MIN, INT_MAX);

            printf("\nAdd element left or right?\n1.Left\n2.Right\n");
            int choose = input(1, 2);
            if (choose == 1)
                head = create_left(head, num);
            else
                tail = create_right(tail, num);
        }

        i++;

        if (i < size) {
            printf("\nAdd another element to the deck?\n1.Yes\n2.No\n");
            t = input(1, 2);
        }

        if (t == 2 || i == size)
            break;
    }

    printf("\n\nQueue: ");
    print_Deck(head);

    printf("\n\nOutput the elements of the deck on the right up to the first negative (inclusive): ");
    print_prev_negative(tail);

    free_Deck(&head);
}