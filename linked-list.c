#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "ops.h"

Node *head;
Byte *opsList;
int m;

void serialLinkedList(Byte *opsList_, int m_, int n_) {
    m = m_;
    opsList = opsList_;

    head = NULL;
    populateLinkedList(n_, &head);

    int val;
    for (int i = 0; i < m; ++i) {
        switch (opsList_[i]) {
            case INSERT_OP:
                val = rand() % VALUE_LIMIT;
                Insert(val, &head);
                break;
            case DELETE_OP:
                val = rand() % VALUE_LIMIT;
                Delete(val, &head);
                break;
            case MEMBER_OP:
                val = rand() % VALUE_LIMIT;
                Member(val, &head);
                break;
        }
    }

    print_list(head);
    deleteLinkedList(head);
}

int Insert(int value, Node **head_pp) {
    Node *current_p = *head_pp;
    Node *prev_p = NULL;
    Node *temp_p;

    // Iterate to the end of the list or until an equivalent value is found in the list
    while (current_p != NULL && current_p->value < value) {
        prev_p = current_p;
        current_p = current_p->next;
    }

    // Insert the new value at the end of the list
    if (current_p == NULL || current_p->value > value) {
        temp_p = malloc(sizeof(Node));
        temp_p->value = value;
        temp_p->next = current_p;

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

int Member(int value, Node **head_p) {
    Node *current_p = *head_p;

    while (current_p != NULL && current_p->value < value)
        current_p = current_p->next;

    if (current_p == NULL || current_p->value > value)
        return 0;
    else
        return 1;
}

void print_list(Node *head) {
    Node *current = head;
    int count = 0;

    while (current != NULL) {
        printf("%d: %d\n", ++count, current->value);
        current = current->next;
    }
}
