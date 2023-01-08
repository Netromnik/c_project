#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

#define TEST(a, b) (a) == (b) ? "SUCCESS" : "FAIL"
void initialize_doors(struct door* doors) {
  srand(time(0));

  int seed = rand() % MAX_ID_SEED;
  for (int i = 0; i < DOORS_COUNT; i++) {
    doors[i].id = (i + seed) % DOORS_COUNT;
    doors[i].status = rand() % 2;
  }
}

void add_door_test1() {
  struct door d = {.id = 4, .status = 1};

  printf("TEST 1:\n");
  printf("INPUT DATA:\n");
  printf("node = 0\n");
  printf("door: id = %d status %d\n", d.id, d.status);
  printf("\n");
  struct node* node = add_door(0, &d);

  printf("\nOUTPUT DATA:\n");
  printf("%p", node);
  int n = node ? node->id : 0;
  printf("%s\n", TEST(n, d.id));
  printf("%s\n", node ? "SUCCESS" : "FAIL");
  destroy(node);
}

void add_door_test2() {
  struct door d = {.id = 4, .status = 1};

  printf("TEST 2:\n");
  printf("INPUT DATA:\n");
  printf("node = 1\n");
  printf("door: id = %d status %d\n", d.id, d.status);
  printf("\n");

  struct node* node = add_door(0, &d);
  struct node* node2 = add_door(node, &d);

  printf("\nOUTPUT DATA:\n");
  printf("%p", node);
  printf("%s\n", TEST(node2, node->next));
  destroy(node);

  printf("\n");
}

void add_door_test() {
  add_door_test1();
  add_door_test2();
}

void remove_door_test() {
  struct door doors[DOORS_COUNT];
  initialize_doors(doors);
  struct node* link_list = init(doors);
  struct node* next = link_list->next;
  find_door(1, next);
  printf("TEST 1:\n");
  printf("INPUT DATA:\n");
  printf("%p || %p \n", link_list, link_list);
  link_list = remove_door(link_list, link_list);
  printf("%s\n", TEST(link_list, next));
  destroy(link_list);
  link_list = init(doors);
  printf("TEST2:\n");
  printf("INPUT DATA:\n");
  printf("%p || %p \n", link_list, link_list->next);
  printf("\nOUTPUT DATA:\n");
  next = link_list->next;
  printf("%s\n", TEST(remove_door(link_list, next), next));

  destroy(link_list);
  printf("\n");
}

int main() {
  add_door_test();
  remove_door_test();
  return 0;
}
