#include "func.h"

void push_double(struct FILO **head, double num) {
    struct FILO *temp;
    temp = (struct FILO *) malloc(sizeof(struct FILO));
    temp->next = NULL;
    temp->data = num;
    if (head == NULL)
        *head = temp;
    else {
        temp->next = *head;
        *head = temp;
    }
}

double pop_double(struct FILO **head) {
    struct FILO *temp = *head;
    if (head != NULL) {
        double num = (*head)->data;
        *head = (*head)->next;
        free(temp);
        return num;
    } else {
        printf("Stack is empty!");
        return 0;
    }
}

int operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

void push_char(struct LIFO **head, char str) {
    struct LIFO *temp;
    temp = (struct LIFO *) malloc(sizeof(struct LIFO));
    temp->next = NULL;
    temp->info = str;
    if (head == NULL)
        *head = temp;
    else {
        temp->next = *head;
        *head = temp;
    }
}

char pop_char(struct LIFO **head) {
    struct FILO *temp = *head;
    if (head != NULL) {
        char str = (*head)->info;
        *head = (*head)->next;
        free(temp);
        return str;
    } else {
        printf("Stack is empty!");
        return 'error';
    }
}

int priority(char c) {
    switch (c) {
        case '(':
            return 1;
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 2;
        default:
            return 0;
    }
}

double operate(double num1, double num2, char c) {
    switch (c) {
        case '+':
            return num2 + num1;
        case '-':
            return num2 - num1;
        case '*':
            return num2 * num1;
        case '/':
            return num2 / num1;
        default:
            return 0;
    }
}

double decision(char *exp) {
    struct LIFO *h = NULL;
    struct FILO *head = NULL;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (digit(exp[i])) {
            double num = 0;
            while (digit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            if (exp[i] == '.') {
                double j = 10;
                while (digit(exp[++i])) {
                    num = num + (exp[i] - '0') / j;
                    j *= 10;
                }
            }
            push_double(&head, num);
            i--;
        } else if (operator(exp[i])) {
            if (h == NULL || exp[i] == '(') {
                push_char(&h, exp[i]);
            } else if (exp[i] == ')') {
                char c;
                while ((c = pop_char(&h)) != '(') {
                    double num1 = pop_double(&head);
                    double num2 = pop_double(&head);
                    push_double(&head, operate(num1, num2, c));
                }
            } else if (priority(exp[i]) >= priority(h->info)) {
                push_char(&h, exp[i]);
            } else {
                char c;
                while (h != NULL && (c = pop_char(&h)) != '(') {
                    double num1 = pop_double(&head);
                    double num2 = pop_double(&head);
                    push_double(&head, operate(num1, num2, c));
                }
                if (c == '(') {
                    push_char(&h, c);
                }
                i--;
            }
        }
    }
    if (h != NULL) {
        while (h != NULL) {
            char c = pop_char(&h);
            double num1 = pop_double(&head);
            double num2 = pop_double(&head);
            push_double(&head, operate(num1, num2, c));
        }
    }

    return pop_double(&head);
}

int sign(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int digit(char c) {
    return (c == '1' || c == '2' || c == '3' || c == '4'|| c == '5'|| c == '6'|| c == '7'|| c == '8'|| c == '9'|| c == '0');
}

int find_error(char *exp) {
    int i = 0;
    int j = 0;
    if (exp[0] == '(') {
        j++;
    } else if (exp[0] == ')') {
        return i;
    }
    while (exp[i + 1] != '\0') {
        if (digit(exp[i]) && exp[i + 1] == '(') {
            return i + 1;
        }
        if (sign(exp[i]) && exp[i + 1] == ')') {
            return i + 1;
        }
        if (exp[i] == ')' && digit(exp[i + 1])) {
            return i + 1;
        }
        if (exp[i + 1] == '(') {
            j++;
        } else if (exp[i + 1] == ')') {
            j--;
        }
        if (j < 0) {
            return i;
        }
        if (sign(exp[i]) && sign(exp[i + 1])) {
            return i + 1;
        }
        if (exp[i] == '(' && exp[i + 1] == ')') {
            return i + 1;
        }
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')) {
            return i + 1;
        }
        i++;
    }
    return -1;
}