#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main() {

    ListNodePtr head = NULL;    // Initially there are no nodes
    int choice = 0;             // user's choice
    char item = '\0';           // char entered by the user
    
    printf("Enter your choice:\n"
    "1 to insert an element into the list in alphabetical order.\n"
    "2 to insert an element at the end of the list.\n"
    "3 to insert an element at the beginning of the list.\n"
    "4 to delete an element from the list.\n"
    "5 to delete an element from the beginning of the list.\n"
    "6 to end.\n");

    printf(":: ");
    scanf("%d", &choice);

    while (choice != 6) {
        switch (choice) {
        case 1:
            printf("Enter a character: ");
            scanf("%c\n", &item);
            insert_node(&head, item);
            print_list(head);
            break;
        
        case 2:
            printf("Enter a character: ");
            scanf("%c\n", &item);
            insert_at_end(&head, item);
            print_list(head);
            break;

        case 3:
            printf("Enter a character: ");
            scanf("%c\n", &item);
            insert_at_beginning(&head, item);
            print_list(head);
            break;

        case 4:
            if (!is_empty(head)) {
                printf("Enter character to be deleted: ");
                scanf("%c\n", &item);

                if (delete_node(&head, item)) {
                    printf("%c has been deleted.\n", item);
                    print_list(head);
                } else {
                    printf("%c is not found.\n", item);
                }
            } else {
                printf("List is empty.\n");   
            }
            break;

        case 5:
            if (!is_empty(head)) {
                delete_at_beginning(&head);
                printf("%c has been deleted.\n", item);
                print_list(head);
            } else {
                printf("List is empty.\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
            printf("Enter your choice:\n"
                "1 to insert an element into the list.\n"
                "2 to delete and element from the list.\n"
                "3 to end.\n"
            );
            break;
        }
        printf("? -> ");
        scanf("%d", &choice);
    }

    printf("\nEnd of run.\n");
    return 0;
}

void insert_at_beginning(ListNodePtr *head, char value) {
    ListNodePtr new_node = malloc(sizeof(node_t));
    new_node->data = value;
    new_node->nextPtr = *head;
    *head = new_node;
}

void insert_at_end(ListNodePtr *head, char value) {
    ListNodePtr current = *head;
    if (current != NULL) {
        while (current -> nextPtr != NULL) {
            current = current->nextPtr;
        }
        current->nextPtr = malloc(sizeof(node_t));
        current->nextPtr->data = value;
        current->nextPtr->nextPtr = NULL;
    } else {
        current = malloc(sizeof(node_t));
        current->data = value;
        current->nextPtr = NULL;
        *head = current;
    }
}

void insert_node(ListNodePtr *head, char value) {
    ListNodePtr newPtr;         // pointer to new node
    ListNodePtr previousPtr;    // pointer to previous node in list
    ListNodePtr currentPtr;     // pointer to current node in list

    newPtr = malloc(sizeof(node_t));    // create node

    if (newPtr != NULL) {
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        previousPtr = NULL;
        currentPtr = *head;

        while (currentPtr != NULL && value > currentPtr->data) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        if (previousPtr == NULL) {
            newPtr->nextPtr = *head;
            *head = newPtr;
        } else {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    } else {
        printf("%c is not inserted. No memory available.\n", value);
    }
}

void delete_at_beginning(ListNodePtr *head) {
    ListNodePtr tempPtr = NULL;
    if (head == NULL) {
        return;
    } else {
        tempPtr = *head;
        *head = (*head)->nextPtr;
        free(tempPtr);
    }
}

char delete_node(ListNodePtr *head, char value) {
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    ListNodePtr tempPtr;

    if (value == (*head)->data) {
        tempPtr = *head;
        *head = (*head)->nextPtr;
        free(tempPtr);
        return value;
    } else {
        previousPtr = *head;
        currentPtr = (*head)->nextPtr;

        while (currentPtr != NULL && currentPtr->data != value) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if (currentPtr != NULL) {
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }

        return '\0';
    }
}

void print_list(ListNodePtr currentPtr) {
    if (currentPtr == NULL) {
        printf("List is empty.\n");
    } else {
        printf("The list is:\n");
        while (currentPtr != NULL) {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}

int is_empty(ListNodePtr head) {
    return head == NULL;
}