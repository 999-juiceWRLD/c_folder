#include <stdio.h>
#include <stdlib.h>

typedef struct node_ {
    int data;
    struct node_ *link;
} Node;

Node *top = NULL;

void push(int data) {
    Node *temp = malloc(sizeof(Node));

    if (temp != NULL) {
        temp->data = data;
        temp->link = top;
        top = temp;
    }
}

int is_empty() {
    return top == NULL;
}

void pop() {
    Node *temp;
    if (top != NULL) {
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}

void display() {
    Node *temp;
    if (top != NULL) {
        temp = top;
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->link;
        }
    }
}

int main() {

    push(1);
    push(2);
    push(3);
    push(4);

    display();

    pop();
    pop();

    display();

    return 0;
}