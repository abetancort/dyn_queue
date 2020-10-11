#ifndef QUEUE_LNK_H 

#define QUEUE_LNK_H 

#include <stdbool.h>

typedef int item;
enum type {TOP, BOTTOM};
typedef struct queue_st *queue;


queue create(void);
bool is_empty(queue q);
item *set(queue q, item value);
item *get(queue q);
item *peek(queue q, enum type type);
void destroy(queue q);
#endif /* QUEUE_LNK_H */
