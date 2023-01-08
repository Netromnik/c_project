#ifndef LIST
#define LIST
#define DOORS_COUNT 15

struct door {
  int id;
  int status;
};

struct node {
  int id;
  int status;
  struct node* next;
};

void initialize_doors(struct door* doors);
struct node* add_door(struct node* elem, struct door* door);
struct node* init(struct door* doors);
struct node* find_door(int door_id, struct node* root);
struct node* remove_door(struct node* elem, struct node* root);
void destroy(struct node* root);

#endif
