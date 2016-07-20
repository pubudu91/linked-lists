#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <pthread.h>
#include "node.h"
#include "ops.h"

double linkedListMutex(Byte *opsList_, int n_threads_, int m_, int n_num_);

void serialLinkedList(Byte *opsList_, int m_, int n_);

double linkedListRWLock(Byte *opsList_, int n_threads_, int m_, int n_num_);

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
    time_t t;
    srand((unsigned) time(&t));
    int m = 10000;
    int n = 1000;
    int n_threads = 1;
    Ops ops;
    ops_init(&ops, m, 0.99, 0.005, 0.005); // Workout the number of operations of each type
    Byte *opsList = malloc(sizeof(Byte) * m);

    buildOpsList(opsList, &ops, m); // Build a randomly ordered list of operations to be carried out

//    printf("time: %.3f\n",linkedListMutex(opsList, n_threads, m, n));
//    serialLinkedList(opsList, m, n);
    printf("time: %f\n", linkedListRWLock(opsList, n_threads, m, n));
    return 0;
}

float std(float data[], int n) {
    float mean = 0.0, sum_deviation = 0.0;
    int i;
    for (i = 0; i < n; ++i) {
        mean += data[i];
    }
    mean = mean / n;
    for (i = 0; i < n; ++i)
        sum_deviation += (data[i] - mean) * (data[i] - mean);
    return sqrt(sum_deviation / n);
}
