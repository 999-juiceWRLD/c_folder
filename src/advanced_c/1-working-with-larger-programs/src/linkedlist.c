#include <stdio.h>
#include "../include/linkedlist.h"
#include "../include/insert.h"

// gcc linkedlist.c insert.c -o ll
// ./ll

void display(struct Node *temp) {
    printf("The elements are:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int ch, data, pos;

    printf("Linked list:\n");
    while (1) {
        printf("1. Insert at Beginning\n");
        printf("2. Insert at N. position\n");
        printf("3. Insert at Ending\n");
        printf("4. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                b_insert(&head, data);
                break;

            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &pos);
                n_insert(&head, data, pos);
                break;

            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                e_insert(&head, data);
                break;
            
            case 4:
                display(head);
                break;
            
            case 0:
                return 0;
            
            default:
                printf("Wrong choice. Try again.\n");
        }
    }
}
