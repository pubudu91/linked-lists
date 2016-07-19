#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "nodeListmutex.h"

int thread_count;                    //thread count
void* threadOperation(void* rank);   //thread function

int main(){
    long thread;
    pthread_t* thread_handles;

    thread_count = 1024;
    thread_handles = malloc(thread_count*sizeof(pthread_t));

    for(thread=0; thread < thread_count ; thread++){
        pthread_create(&thread_handles[thread],NULL,threadOperation, (void*)thread);
    }
    for(thread=0; thread < thread_count ; thread++){
        pthread_join(thread_handles[thread],NULL);
    }
    free(thread_handles);
    return 0;

}

void *threadOperation(void* rank){
    long my_rank = (long) rank;

    return NULL;
}
int Insert(int value, Node_List **head_pp) {
    Node_List *current_p = *head_pp;
    Node_List *prev_p = NULL;
    Node_List *temp_p;

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

int Delete(int value, Node_List **head_pp) {
    Node_List *current_p = *head_pp;
    Node_List *prev_p = NULL;

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
    Node_List* current_p = head_p;

    while(current_p != NULL && current_p->value < value)
        current_p = current_p->next;

    if(current_p != NULL && current_p->value == value)
        return 1;
    else
        return 0;
}

void print_list(Node *head) {
    Node_List *current = head;
    int count = 0;

    while (current != NULL) {
        printf("%d: %d\n", ++count, current->value);
        current = current->next;
    }
}


void mutexInsert (int value, Node_List **head_pp ) {

}
