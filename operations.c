#include <stdlib.h>
#include "node.h"
#include "ops.h"

// Convert the percentages of each operation into a concrete number
void ops_init(Ops *ops, int m, double p_ins, double p_del, double p_mem) {
    int n_ins = (int) (p_ins * m);
    int n_del = (int) (p_del * m);
    int n_mem = (int) (p_mem * m);

    ops->n_insert = n_ins;
    ops->n_delete = n_del;
    ops->n_member = n_mem;
}

void buildOpsList(Byte *opsList, Ops *ops, int m) {
    int rnd;

    setSeed();

    for (int i = 0; i < m;) {
        rnd = (rand() % 3) + 1;
        switch (rnd) {
            case INSERT_OP:
                if (ops->n_insert > 0) {
                    opsList[i++] = INSERT_OP;
                    ops->n_insert--;
                }
                break;
            case DELETE_OP:
                if (ops->n_delete > 0) {
                    opsList[i++] = DELETE_OP;
                    ops->n_delete--;
                }
                break;
            case MEMBER_OP:
                if (ops->n_member > 0) {
                    opsList[i++] = MEMBER_OP;
                    ops->n_member--;
                }
                break;
        }
    }
}

void populateLinkedList(int n, Node **head_pp) {
    int result;

    setSeed();

    // Insert n unique random integers in the range 0 - 65535 to the list
    for (int i = 0; i < n; (result > 0) ? ++i : i)
        result = Insert(rand() % VALUE_LIMIT, head_pp);
}

void deleteLinkedList(Node *head) {
    Node *current;
    while ((current = head) != NULL) {
        head = head->next;
        free(current);
    }
}

void setSeed() {
    srand(((rand()) % VALUE_LIMIT) * 39163);
}