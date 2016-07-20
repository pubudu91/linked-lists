#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <pthread.h>
#include "node.h"
#include "ops.h"

double linkedListMutex(Byte *opsList_, int n_threads_, int m_, int n_num_);

double serialLinkedList(Byte *opsList_, int m_, int n_);

double linkedListRWLock(Byte *opsList_, int n_threads_, int m_, int n_num_);

float findAverage(float *time, int size);

int findSampleSize(float std, float average);

float std(float data[], int n);

void runDummyThreads(int thread_count);

void *dummyOp();

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
    int n_threads = 4;
    Ops ops;
    ops_init(&ops, m, 0.005, 0.005, 0.99); // Workout the number of operations of each type
    Byte *opsList = malloc(sizeof(Byte) * m);

    runDummyThreads(n_threads);
    buildOpsList(opsList, &ops, m); // Build a randomly ordered list of operations to be carried out

//    printf("time: %.3f\n",linkedListMutex(opsList, n_threads, m, n));
//    serialLinkedList(opsList, m, n);
//    printf("time: %f\n", linkedListRWLock(opsList, n_threads, m, n));

    int sample_size = 0;
    int test_samples = 20;
    float mutex_std = 0;
    float rwlock_std = 0;
    float serial_std = 0;

    // arrays for test sample memory size
    float *mutext_time = malloc(sizeof(float) * test_samples);
    float *rwlock_time = malloc(sizeof(float) * test_samples);  //=malloc(sizeof(float)*test_samples)
    float *serial_time = malloc(sizeof(float) * test_samples);


    //all three linked list impletation run
    for (int i = 0; i < test_samples; i++) {
        mutext_time[i] = linkedListMutex(opsList, n_threads, m, n);
        rwlock_time[i] = linkedListRWLock(opsList, n_threads, m, n);
        serial_time[i] = serialLinkedList(opsList, m, n);
    }


    //finding standard deviation of each linked list implementation
    mutex_std = std(mutext_time, test_samples);
    rwlock_std = std(rwlock_time, test_samples);
    serial_std = std(serial_time, test_samples);

    //find average of each linked list implementation
    float mutex_avg = findAverage(mutext_time, test_samples);
    float rwlock_avg = findAverage(rwlock_time, test_samples);
    float serial_avg = findAverage(serial_time, test_samples);

    //find sample size with 5% accurary and 95% confident interval
    int mutext_ss = findSampleSize(mutex_std, mutex_avg);
    printf("mutex sample_size %d\n", mutext_ss);
    int rwlock_ss = findSampleSize(rwlock_std, rwlock_avg);
    printf("rwlock sample_size %d\n", rwlock_ss);
    int serial_ss = findSampleSize(serial_std, serial_avg);
    printf("serial sample_size %d\n", serial_ss);

    // array with sample size
    float *mutext_time_case = malloc(sizeof(float) * mutext_ss);
    float *rwlock_time_case = malloc(sizeof(float) * rwlock_ss);  //=malloc(sizeof(float)*test_samples)
    float *serial_time_case = malloc(sizeof(float) * serial_ss);

    //mutex linked list implementation
    for (int i = 0; i < mutext_ss; i++) {
        mutext_time_case[i] = linkedListMutex(opsList, n_threads, m, n);
    }

    //rwlock linked list implementation
    for (int i = 0; i < rwlock_ss; i++) {
        rwlock_time_case[i] = linkedListRWLock(opsList, n_threads, m, n);
    }

    //serial linked list implementation
    for (int i = 0; i < serial_ss; i++) {
        serial_time_case[i] = serialLinkedList(opsList, m, n);
    }

    // final average time of each linked list implementation
    float final_mutex_avg = findAverage(mutext_time_case, mutext_ss);
    float final_rwlock_avg = findAverage(rwlock_time_case, rwlock_ss);
    float final_serial_avg = findAverage(serial_time_case, serial_ss);

    // final standard deviation values of each linked list implementation
    float final_mutex_std = std(mutext_time_case, mutext_ss);
    float final_rwlock_std = std(rwlock_time_case, rwlock_ss);
    float final_serial_std = std(serial_time_case, serial_ss);

    printf("mutex linked list average %f :  std %f\n", final_mutex_avg, final_mutex_std);
    printf("rwlock linked list average %f :  std %f\n", final_rwlock_avg, final_rwlock_std);
    printf("serial linked list average %f :  std %f\n", final_serial_avg, final_serial_std);

    return 0;
}

//==========to find the average===========
float findAverage(float *time, int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += time[i];
    }
    float average = total / size;
    return average;
}

//to find the sample size=========
int findSampleSize(float std, float average) {
    double sample;
    double base = (100 * 1.96 * std) / (5 * average);
    sample = pow(base, 2);
    return (int) ceil(sample);
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
    return sqrt(sum_deviation / (n - 1));
}

void runDummyThreads(int thread_count) {
    pthread_t *thread_handles = malloc(thread_count * sizeof(pthread_t));

    int ret1, i;

    for (i = 0; i < thread_count; i++) {
        ret1 = pthread_create(&thread_handles[i], NULL, dummyOp, NULL);

        if (ret1) {
            fprintf(stderr, "Error - pthread_create() return code: %d\n", ret1);
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < thread_count; i++) {
        pthread_join(thread_handles[i], NULL);
    }
}

void *dummyOp() {
}