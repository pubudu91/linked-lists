#include <time.h>
#include <stdlib.h>
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
    time_t t;
    int rnd;

    srand((unsigned) time(&t));

    for (int i = 0; i < m; ) {
        rnd = (rand() % 3) + 1;
        switch (rnd) {
            case 1:
                if (ops->n_insert > 0) {
                    opsList[i++] = INSERT_OP;
                    ops->n_insert--;
                }
                break;
            case 2:
                if (ops->n_delete > 0) {
                    opsList[i++] = DELETE_OP;
                    ops->n_delete--;
                }
                break;
            case 3:
                if (ops->n_member > 0) {
                    opsList[i++] = MEMBER_OP;
                    ops->n_member--;
                }
                break;
        }
    }
}