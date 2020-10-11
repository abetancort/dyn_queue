#include <stdio.h>
#include <stdlib.h>

#include "queue_lnk.h"

struct node_st {
  item value;
  struct node_st *next;
};

typedef struct node_st *node;

struct queue_st {
  node top;
  node bottom;
  size_t used;
};

enum signal_e {RUN, KILL};

static void error_q(char *message, enum signal_e signal)
{
  printf("%s\n", message);
  if (signal == KILL) 
    exit(EXIT_FAILURE);
}

queue create(void)
{
  queue new_queue;
  new_queue = malloc(sizeof(struct queue_st));

  if (new_queue == NULL)
    error_q("Unable to create queue", KILL);

  new_queue->top = NULL;
  new_queue->bottom = NULL;
  new_queue->used = 0;
  
  return new_queue;
}

bool is_empty(queue q)
{
  return q->bottom == NULL;
}

item *set(queue q, item value)
{
  static item new_val;
  node new_node = malloc(sizeof(struct node_st));
  
  if (new_node == NULL) {
    error_q("Unable to create new entry.", RUN);
    return NULL;
  }

  new_node->value = new_val = value;
  new_node->next = NULL;
 
  if (q->top != NULL)
    q->top->next = new_node;
  q->top = new_node;

  if (q->bottom == NULL)
    q->bottom = new_node;

  return &new_val;
}

item *get(queue q)
{
  static item value;
  
  if (is_empty(q)) {
    error_q("Empty queue.", RUN);
    return NULL;
  }

  value = q->bottom->value;

  node old_node = q->bottom;
  q->bottom = q->bottom->next;
  if (is_empty(q)) 
    q->top = NULL;

  free(old_node);

  return  &value;
}

item *peek(queue q, enum type type)
{
  static item value;
  
  if (is_empty(q)) {
    error_q("Empty queue", RUN);
    return NULL;
  }

  if (type == TOP)
    value = q->top->value;
  else if (type == BOTTOM)
    value = q->bottom->value;
  else
    error_q("Wrong type", RUN);

  return &value;
}

void destroy(queue q)
{
  while (!is_empty(q))
    get(q);
  free(q);
}


