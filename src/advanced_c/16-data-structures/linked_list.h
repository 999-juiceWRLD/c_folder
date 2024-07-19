#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// inserts char elements in alphabetical order.

typedef struct node {
    char data;
    struct node *nextPtr;
} node_t;

typedef node_t *ListNodePtr;

void insert_node(ListNodePtr *head, char value);
void insert_at_end(ListNodePtr *head, char value);
void insert_at_beginning(ListNodePtr *head, char val);
char delete_node(ListNodePtr *head, char value);
void delete_at_beginning(ListNodePtr *head);
int is_empty(ListNodePtr head);
void print_list(ListNodePtr current_ptr);

#endif // LINKED_LIST_H