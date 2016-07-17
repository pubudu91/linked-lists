//
// Created by pubudu on 7/17/16.
//
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

int Insert(int value, Node **head_pp) {
    Node *current_p = *head_pp;
    Node *prev_p = NULL;
    Node *temp_p;

    // Iterate to the end of the list or until an equivalent value is found in the list
    while (current_p != NULL && current_p->value != value) {
        prev_p = current_p;
        current_p = current_p->next;
    }

    // Insert the new value at the end of the list
    if (current_p == NULL) {
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
        return 0; // If the value to be inserted is already in the list, do not insert it
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
    int count = 0;

    while (current != NULL) {
        printf("%d: %d\n", ++count, current->value);
        current = current->next;
    }
}
