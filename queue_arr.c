#include <stdio.h>
#include <stdlib.h>

#include "queue_arr.h"


#define MAX_ENTRIES 10

struct queue_st {
  item *entries;
  size_t top;
  size_t bottom;
  size_t used;
  size_t size;
};


static void terminate (char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}



queue create (size_t size)
{
  queue q;

  q = malloc(sizeof(struct queue_st));
  if (q == NULL) 
    terminate("Unable to create queue.");

  q->entries = malloc(sizeof(item) * size);
  if (q->entries == NULL) {
    free(q);
    terminate("Unable to create queue.");
  }

  q->top = q->bottom = q->used = 0;
  q->size = size;

  return q;
}

bool is_empty(queue q)
{
  return !q->used;
}

bool is_full(queue q) 
{
  return q->used == q->size;
}

item *get(queue q)
{
  static item value;
  
  if (is_empty(q)) {
    printf("Queue is empty.\n");
    return NULL;
  }
  
  value = q->entries[q->bottom++];
  
  if (q->bottom == q->size)
    q->bottom = 0;
  q->used--;

  return &value;
}

item *set(queue q, item value)
{
  static item new_value;

  if (is_full(q)) {
    printf("Queue is full.\n");
    return NULL;
  }
  
  new_value = value;
  q->entries[q->top++] = new_value;
  
  if (q->top == q->size) 
    q->top = 0;
  q->used++;

  return &new_value;
}

item *peek(queue q, enum type type)
{
  static item value;
  
  if (is_empty(q)) {
    printf("Queue empty, nothing to peek\n");
    return NULL;
  }

  if (type == TOP) {
    value = q->entries[q->top];
    return &value;
  } else if (type == BOTTOM) {
    value = q->entries[q->bottom];
    return &value;
  } else {
    printf("Unknow type.\n");
    return NULL;
  }
}

void destroy(queue q)
{
  free(q->entries);
  free(q);
}


