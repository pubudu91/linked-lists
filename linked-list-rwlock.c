#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "node.h"
#include "ops.h"

int thread_count;                    //thread count
pthread_rwlock_t rwlock; // Initialize a rwlock with default attributes
Node *head;
Byte *opsList;
int m;

void *threadOperationRWLock(void *);   //thread function

double linkedListRWLock(Byte *opsList_, int n_threads_, int m_, int n_num_) {
    pthread_t *thread_handles;
    double start, end, total;

    opsList = opsList_;
    m = m_;
    thread_count = n_threads_;

    thread_handles = malloc(thread_count * sizeof(pthread_t));

    head = NULL;
    populateLinkedList(n_num_, &head);

    start = clock();
    pthread_rwlock_init(&rwlock, NULL);
    int ret1, i;
    for (i = 0; i < thread_count; i++) {
        ret1 = pthread_create(&thread_handles[i], NULL, threadOperationRWLock, (void *) i);

//        if (ret1) {
//            fprintf(stderr, "Error - pthread_create() return code: %d\n", ret1);
//            exit(EXIT_FAILURE);
//        }
    }

    for (i = 0; i < thread_count; i++)
        pthread_join(thread_handles[i], NULL);

    pthread_rwlock_destroy(&rwlock);
    end = clock();
    total = (double) (end - start) / CLOCKS_PER_SEC;

    free(thread_handles);
//    print_list(head);
    deleteLinkedList(head);
    return total;
}

void *threadOperationRWLock(void *threadNum) {
    int blockSize = m / thread_count;
    int i = (int) threadNum;
//    printf("Inside thread #%d\n", i);

    int j;
    for (j = i * blockSize; j < i * blockSize + blockSize || (j == m - 1 && j < m); ++j) {
        switch (opsList[j]) {
            case INSERT_OP:
                pthread_rwlock_wrlock(&rwlock);
                Insert(rand() % VALUE_LIMIT, &head);
                pthread_rwlock_unlock(&rwlock);
                break;
            case DELETE_OP:
                pthread_rwlock_wrlock(&rwlock);
                Delete(rand() % VALUE_LIMIT, &head);
                pthread_rwlock_unlock(&rwlock);
                break;
            case MEMBER_OP:
                pthread_rwlock_rdlock(&rwlock);
                Member(rand() % VALUE_LIMIT, &head);
                pthread_rwlock_unlock(&rwlock);
                break;
        }
    }
    return NULL;
}
