#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "node.h"
#include "ops.h"

int thread_count;                    //thread count
pthread_mutex_t mutex;
Node *head;

//void *threadOperation(void *rank);   //thread function
void *threadOperation(void *);

Byte *opsList;
Ops *ops;
int n;
int m;


int linkedListMutex(Byte *opsList_, Ops *ops_, int n_, int m_) {
    pthread_t *thread_handles;

    opsList = opsList_;
    ops = ops_;
    n = n_;
    m = m_;

    thread_count = n;
    thread_handles = malloc(thread_count * sizeof(pthread_t));

    head = NULL;
    populateLinkedList(20, &head);

    int ret1, i;
    for (i = 0; i < thread_count; i++) {
        ret1 = pthread_create(&thread_handles[i], NULL, threadOperation, (void *) i);
        if (ret1) {
            fprintf(stderr, "Error - pthread_create() return code: %d\n", ret1);
            exit(EXIT_FAILURE);
        }

    }

    for (i = 0; i < thread_count; i++) {
        pthread_join(thread_handles[i], NULL);
    }

    free(thread_handles);
    print_list(head);
    return 0;

}

void *threadOperation(void *threadNum) {
    int blockSize = m / n;
    int i = (int) threadNum;
    printf("Inside thread #%d\n", i);

    int j;
    for (j = i * blockSize; j < i * blockSize + blockSize || (j == m - 1 && j < m); ++j) {
        switch (opsList[j]) {
            case INSERT_OP:
                pthread_mutex_lock(&mutex);
                Insert(rand() % VALUE_LIMIT, &head);
                pthread_mutex_unlock(&mutex);
                break;
            case DELETE_OP:
                pthread_mutex_lock(&mutex);
                Delete(rand() % VALUE_LIMIT, &head);
                pthread_mutex_unlock(&mutex);
                break;
            case MEMBER_OP:
                pthread_mutex_lock(&mutex);
                Member(rand() % VALUE_LIMIT, &head);
                pthread_mutex_unlock(&mutex);
                break;
        }
    }
    return NULL;
}
//int Insert(int value, Node_List **head_pp) {
//    Node_List *current_p = *head_pp;
//    Node_List *prev_p = NULL;
//    Node_List *temp_p;
//
//    // Iterate to the end of the list or until an equivalent value is found in the list
//    while (current_p != NULL && current_p->value != value) {
//        prev_p = current_p;
//        current_p = current_p->next;
//    }
//
//    // Insert the new value at the end of the list
//    if (current_p == NULL) {
//        temp_p = malloc(sizeof(Node));
//        temp_p->value = value;
//        temp_p->next = NULL;
//
//        if (prev_p == NULL)
//            *head_pp = temp_p;
//        else
//            prev_p->next = temp_p;
//
//        return 1;
//    }
//    else
//        return 0; // If the value to be inserted is already in the list, do not insert it
//}
//
//int Delete(int value, Node_List **head_pp) {
//    Node_List *current_p = *head_pp;
//    Node_List *prev_p = NULL;
//
//    while (current_p != NULL && current_p->value < value) {
//        prev_p = current_p;
//        current_p = current_p->next;
//    }
//
//    if (current_p != NULL && current_p->value == value) {
//        if (prev_p == NULL) {
//            *head_pp = current_p->next;
//            free(current_p);
//        }
//        else {
//            prev_p->next = current_p->next;
//            free(current_p);
//        }
//
//        return 1;
//    }
//    else
//        return 0;
//}
//
//int Member(int value, Node* head_p) {
//    Node_List* current_p = head_p;
//
//    while(current_p != NULL && current_p->value < value)
//        current_p = current_p->next;
//
//    if(current_p != NULL && current_p->value == value)
//        return 1;
//    else
//        return 0;
//}
//
//void print_list(Node *head) {
//    Node_List *current = head;
//    int count = 0;
//
//    while (current != NULL) {
//        printf("%d: %d\n", ++count, current->value);
//        current = current->next;
//    }
//}
//
//
//void mutexInsert (int value, Node_List **head_pp ) {
//
//}
