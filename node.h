#ifndef LINKED_LISTS_NODE_H
#define LINKED_LISTS_NODE_H
typedef struct node {
    int value;
    struct node *next;
} Node;

int Member(int value, Node **list_head);

int Insert(int value, Node **head_pp);

int Delete(int value, Node **head_pp);

void print_list(Node *head);

#endif //LINKED_LISTS_NODE_H
