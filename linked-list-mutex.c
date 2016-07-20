#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "node.h"
#include "ops.h"

int thread_count;                    //thread count
pthread_mutex_t mutex;
Node *head;
Byte *opsList;
int m;

void *threadOperationMutex(void *);   //thread function

double linkedListMutex(Byte *opsList_, int n_threads_, int m_, int n_num_) {
    pthread_t *thread_handles;
    double start_t, end_t, total_t;

    opsList = opsList_;
    m = m_;
    thread_count = n_threads_;

    thread_handles = malloc(thread_count * sizeof(pthread_t));

    head = NULL;
    populateLinkedList(n_num_, &head);

    start_t = clock();
    int ret1, i;
    for (i = 0; i < thread_count; i++) {
        ret1 = pthread_create(&thread_handles[i], NULL, threadOperationMutex, (void *) i);
        if (ret1) {
            fprintf(stderr, "Error - pthread_create() return code: %d\n", ret1);
            exit(EXIT_FAILURE);
        }

    }

    for (i = 0; i < thread_count; i++) {
        pthread_join(thread_handles[i], NULL);
    }

    end_t = clock();
    total_t = (double) (end_t - start_t) / CLOCKS_PER_SEC;

    free(thread_handles);
//    print_list(head);
    deleteLinkedList(head);
    return total_t;
}

void *threadOperationMutex(void *threadNum) {
    int blockSize = m / thread_count;
    int i = (int) threadNum;
//    printf("Inside thread #%d\n", i);

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
