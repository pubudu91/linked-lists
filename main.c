#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include "node.h"
#include "ops.h"

#define VALUE_LIMIT (1 << 16) - 1

int main() {
    Node *head = NULL;
    int n = 1000;
//    Insert(10, &head);
//    Insert(20, &head);
//    Insert(30, &head);
//    Insert(15, &head);
//    Insert(25, &head);
//    Insert(50, &head);
//    Insert(60, &head);
//
//    print_list(head);
//    printf("\n");
//
//    Delete(25, &head);
//    printf("%d\n", Delete(10, &head));
//
//    print_list(head);
//    printf("\n");
//
//    Delete(30, &head);
//    Delete(50, &head);
//
//    print_list(head);
//    printf("\n");
//
//    Insert(120, &head);
//    Insert(120, &head);
//    Insert(120, &head);
//    Insert(130, &head);
//    Insert(140, &head);
//    Insert(150, &head);
//
//    print_list(head);
//    printf("\n");
//
//    printf("%d\n", Member(30, head));
//    printf("%d\n", Member(40, head));
//    printf("%d\n", Member(50, head));
//    printf("%d\n", Member(60, head));
//    printf("%d\n", Member(160, head));
    populateLinkedList(20, &head);
    print_list(head);
    int m = 100;
    Ops ops;
    ops_init(&ops, m, 0.8, 0.1, 0.1);
    Byte *opsList = malloc(sizeof(Byte) * m);

    buildOpsList(opsList, &ops, m);

    for (int i = 0; i < m; ++i) {
        printf("%d\n", opsList[i]);
    }

    return 0;
}

void populateLinkedList(int n, Node **head_pp) {
    time_t t;
    int result;

    srand((unsigned) time(&t));

    for (int i = 0; i < n; (result > 0) ? ++i : i)
        result = Insert(rand() % VALUE_LIMIT, head_pp);
}

void runInsertThreads(Node **head_pp, int n_threads, int n_ops) {
    int n_ops_remaining = n_ops;
    pthread_t *ptr = malloc(sizeof(pthread_t) * n_threads);

    for (int i = 0; i < n_threads; ++i) {
//        pthread_create(&ptr[i], NULL, &runInsertOps )
    }
}

void runInsertOps(Node **head_pp, int n_ops) {
}