#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void sort_doors(struct door* doors, int num_doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);

    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;  // 0 - закрыто
    }

    sort_doors(doors, DOORS_COUNT);

    return 0;
}

void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort_doors(struct door* doors, int num_doors) {
    for (int i = 0; i < num_doors - 1; ++i) {
        for (int j = 0; j < num_doors - i - 1; ++j) {
            if (doors[j].id > doors[j + 1].id) {
                struct door temp = doors[j];
                doors[j] = doors[j + 1];
                doors[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < num_doors; ++i) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
}