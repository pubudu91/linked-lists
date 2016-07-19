#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include "node.h"
#include "ops.h"

int linkedListMutex(Byte *opsList_, int n_threads_, int m_, int n_num_);

void serialLinkedList(Byte *opsList_, int m_, int n_);

int main() {
//    Node *head = NULL;
//    int n = 1000;
//    Insert(10, &head);
//    Insert(30, &head);
//    Insert(50, &head);
//    Insert(60, &head);
//    Insert(20, &head);
//
//    print_list(head);
//    printf("\n");
//
//    deleteLinkedList(head);
//
//    print_list(head);
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
//    printf("%d\n", Member(30, &head));
//    printf("%d\n", Member(40, &head));
//    printf("%d\n", Member(50, &head));
//    printf("%d\n", Member(60, &head));
//    printf("%d\n", Member(160, &head));
//    populateLinkedList(20, &head); // Populate the linked list with random numbers
//    print_list(head);
//    typedef struct args {
//        Node **head_pp;
//        int value;
//    } Args;
    int m = 10;
    int n = 20;
    int n_threads = 1;
    Ops ops;
    ops_init(&ops, m, 0.8, 0.1, 0.1); // Workout the number of operations of each type
    Byte *opsList = malloc(sizeof(Byte) * m);

    buildOpsList(opsList, &ops, m); // Build a randomly ordered list of operations to be carried out

//    for (int i = 0; i < m; ++i) {
//        printf("%d\n", opsList[i]);
//    }
//    linkedListMutex(opsList, n_threads, m, 20);
    serialLinkedList(opsList, m, n);
    return 0;
}

void runThreads(Node **head_pp, int n_threads, int n_ops, Byte *opsList, int m) {
    int n_ops_remaining = n_ops;
    int blockSize = m / n_threads; // Calculate the number of operations to give per thread
    pthread_t *threads = malloc(sizeof(pthread_t) * n_threads);

    for (int i = 0; i < n_threads; ++i) {
//        threads[i] = pthread_create(&threads[i], NULL, &runInsertOps )

    }
}

//void runOperations(Node **head_pp, Byte *opsList, int n_threads, int m, int i, int blockSize) {
//    for (int j = i; j < i + blockSize || (j == n_threads - 1 && j < m); ++j) {
//        switch (opsList[j]) {
//            case 1:
//                Insert(rand() % VALUE_LIMIT, &head_pp);
//                break;
//            case 2:
//                Delete(rand() % VALUE_LIMIT, &head_pp);
//                break;
//            case 3:
//                Member(rand() % VALUE_LIMIT, &head_pp);
//                break;
//        }
//    }
//}

void runInsertOps(Node **head_pp, int n_ops) {
}