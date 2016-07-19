#include "node.h"

#ifndef LINKED_LISTS_OPERATIONS_H
#define LINKED_LISTS_OPERATIONS_H
#define INSERT_OP 1
#define DELETE_OP 2
#define MEMBER_OP 3
#define VALUE_LIMIT (1 << 16)

typedef struct ops {
    int n_insert;
    int n_delete;
    int n_member;
} Ops;

typedef unsigned char Byte;

void ops_init(Ops *ops, int m, double p_ins, double p_del, double p_mem);

void buildOpsList(Byte *opsList, Ops *ops, int m);

void populateLinkedList(int n, Node **head_pp);

void deleteLinkedList(Node *head);

void setSeed();

#endif //LINKED_LISTS_OPERATIONS_H
