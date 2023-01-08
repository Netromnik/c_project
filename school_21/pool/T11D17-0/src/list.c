#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST(a, b) (a) == (b) ? "SUCCESS" : "FAIL"

struct node* add_door(struct node* elem, struct door* door) {
  struct node* new_elem = (struct node*)malloc(sizeof(struct node));

  new_elem->id = door->id;
  new_elem->status = door->status;
  if (elem) {
    new_elem->next = elem->next;
    elem->next = new_elem;
  }
  return new_elem;
}

struct node* init(struct door* doors) {
  struct node* root = add_door(0, doors);
  struct node* tmp = root;
  for (int i = 1; i < DOORS_COUNT; i++) {
    tmp = add_door(tmp, doors + i);
  }
  return root;
}

struct node* find_door(int door_id, struct node* root) {
  struct node* tmp = root;
  for (; tmp != 0; tmp = tmp->next) {
    if (tmp->id == door_id) break;
  }
  return tmp;
}

struct node* remove_door(struct node* elem, struct node* root) {
  struct node* tmp = root;
  if (elem == root) {
    root = root->next;
    free(elem);
  } else {
    for (; tmp != 0; tmp = tmp->next) {
      if (tmp == elem) free(tmp);
    }
  }
  return root;
}

void destroy(struct node* root) {
  struct node* tmp = root;
  while (tmp->next) {
    tmp = root;
    root = root->next;
    free(tmp);
  }
  free(root);
}
