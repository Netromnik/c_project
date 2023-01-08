#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);

void output(struct door* doors) {
  for (int i = 0; i < DOORS_COUNT; i++) {
    printf("%d,%d\n", doors[i].id, doors[i].status);
  }
}

void bubbleSort(struct door* doors, int size) {
  for (int step = 0; step < size - 1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {
      doors[i].status = 0;
      if (doors[i].id > doors[i + 1].id) {
        struct door temp = doors[i];
        doors[i] = doors[i + 1];
        doors[i + 1] = temp;
      }
    }
  }
}

int main() {
  struct door doors[DOORS_COUNT];

  initialize_doors(doors);
  bubbleSort(doors, DOORS_COUNT);
  output(doors);
  return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
  srand(time(0));

  int seed = rand() % MAX_ID_SEED;
  for (int i = 0; i < DOORS_COUNT; i++) {
    doors[i].id = (i + seed) % DOORS_COUNT;
    doors[i].status = rand() % 2;
  }
}
