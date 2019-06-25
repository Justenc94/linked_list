/**********************************************************
Name: Justen Crockett
Assignment: 03
Purpose:
***********************************************************/
#include "functions.h"

void make_test_cases(int *ids, char **data, int num_cases) {

    for (int i = 0; i < num_cases; i++) {
        ids[i] = rand() % MAX_ID + 1000;
        for (int j = 0; j < BUFFER_SIZE - 1; j++) {
            data[i][j] = 'a' + i;
        }
        data[i][BUFFER_SIZE - 1] = '\0';
    }
}

void make_head_cases(int *ids, char **data, int num_cases) {

    for (int i = 0; i < num_cases; i++) {
        ids[i] = rand() % MAX_ADD_HEAD_ID;
        for (int j = 0; j < BUFFER_SIZE - 3; j++) {
            data[i][j] = 'a' + i;
        }
        data[i][BUFFER_SIZE - 3] = '\0';
    }
}

void make_tail_cases(int *ids, char **data, int num_cases) {

    for (int i = 0; i < num_cases; i++) {
        ids[i] = rand() % MAX_ADD_TAIL_ID+10000;
        for (int j = 0; j < BUFFER_SIZE - 3; j++) {
            data[i][j] = 'a' + i;
        }
        data[i][BUFFER_SIZE - 3] = '\0';
    }
}