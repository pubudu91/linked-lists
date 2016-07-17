#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "node.h"

#define VALUE_LIMIT (1 << 16) - 1

int main() {
    Node *head = NULL;
    int n = 1000;
//    Insert(10, &head);
//    Insert(20, &head);
//    Insert(30, &head);
//    Insert(15, &head);
//    Insert(25, &head);
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
//    printf("%d\n", Member(130, head));
//    printf("%d\n", Member(120, head));
//    printf("%d\n", Member(160, head));
    populateList(20, &head);
    print_list(head);
    return 0;
}

void populateList(int n, Node **head_p) {
    time_t t;
    int result;

    srand((unsigned) time(&t));

    for (int i = 0; i < n; (result > 0) ? ++i : i)
        result = Insert(rand() % VALUE_LIMIT, head_p);
}

//void runInsertOperation()