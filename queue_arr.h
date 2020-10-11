
#ifndef QUEUE_ARR_H
#define QUEUE_ARR_H

#include <stdbool.h>

typedef int item;
typedef struct queue_st *queue;
enum type {TOP, BOTTOM};

queue create (size_t size);
item *get(queue q);
bool is_empty(queue q);
bool is_full(queue q);
item *set(queue q, item value);
item *peek(queue q, enum type type);
void destroy(queue q);

#ifdef DEBUG
struct queue_st {
  item *entries;
  size_t top;
  size_t bottom;
  size_t used;
  size_t size;
};
#endif /* DEBUG */

#endif /* QUEUE_ARR_H */
