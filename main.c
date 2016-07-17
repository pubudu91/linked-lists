//
// Created by pubudu on 7/16/16.
//
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

int main() {
    Node *head = NULL;
    Insert(10, &head);
    Insert(20, &head);
    Insert(30, &head);
    Insert(40, &head);
    Insert(50, &head);

    print_list(head);
    printf("\n");

    Delete(30, &head);
    Delete(50, &head);

    print_list(head);
    printf("\n");

    Insert(120, &head);
    Insert(120, &head);
    Insert(120, &head);
    Insert(130, &head);
    Insert(140, &head);
    Insert(150, &head);

    print_list(head);
    printf("\n");

    printf("%d\n", Member(30, head));
    printf("%d\n", Member(40, head));
    printf("%d\n", Member(130, head));
    printf("%d\n", Member(120, head));
    printf("%d\n", Member(160, head));
    return 0;
}

int Insert(int value, Node **head_pp) {
    Node *current_p = *head_pp;
    Node *prev_p = NULL;
    Node *temp_p;

    while (current_p != NULL && current_p->value < value) {
        prev_p = current_p;
        current_p = current_p->next;
    }

    if (current_p == NULL || current_p->value >= value) {
        temp_p = malloc(sizeof(Node));
        temp_p->value = value;
        temp_p->next = NULL;

        if (prev_p == NULL)
            *head_pp = temp_p;
        else
            prev_p->next = temp_p;

        return 1;
    }
    else
        return 0;
}

int Delete(int value, Node **head_pp) {
    Node *current_p = *head_pp;
    Node *prev_p = NULL;

    while (current_p != NULL && current_p->value < value) {
        prev_p = current_p;
        current_p = current_p->next;
    }

    if (current_p != NULL && current_p->value == value) {
        if (prev_p == NULL) {
            *head_pp = current_p->next;
            free(current_p);
        }
        else {
            prev_p->next = current_p->next;
            free(current_p);
        }

        return 1;
    }
    else
        return 0;
}

int Member(int value, Node* head_p) {
    Node* current_p = head_p;

    while(current_p != NULL && current_p->value < value)
        current_p = current_p->next;

    if(current_p != NULL && current_p->value == value)
        return 1;
    else
        return 0;
}

void print_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}
