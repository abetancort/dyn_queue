#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG

#include "queue_lnk.h"



int main(void)
{
  int i;
  int total = 0;
  queue q;
  item val;
  item *val_p;
 
  const int size = 100000;

  srand(time(NULL));

  printf("\nCreating queue\n");
  q = create();
  
  printf("Press enter to continue.\n");
  while (getchar() != '\n')
    ;

  printf("\nSetting %d entries in queue to fill it up\n", size);

  for (i = 0; i < size; i++) {
    val = rand() % 100;;
    val_p = set(q, val);
  }
  printf("Done. Total entries: %d\n", total += i);


  printf("Press enter to continue.\n");
  while (getchar() != '\n')
    ;

  printf("\nGetting %d entries from queue \n", size / 2);

  for (i = 0; i < size / 2; i++) {
    val_p = get(q);
  }
  printf("Done. Total entries: %d\n", total += - i);

  printf("\nSetting another %d entries in queue so it folds\n", size/3);
  for (i = 0; i < size/3; i++) {
    val = rand() % 100;;
    val_p = set(q, val);
  }
  printf("Done. Total entries: %d\n", total +=  i);

  printf("\nGetting another %d entries from queue so bottom folds\n", 
        (int)(size / 2 * 1.30));
  
  for (i = 0; i < (int)(size / 2 * 1.30); i++) {
    val_p = get(q);
  }
  printf("Done. Total entries: %d\n", total +=  -i);

  printf("Press enter to continue.\n");
  while (getchar() != '\n')
    ;

  printf("\nEmptying the queue\n");
  i = 0;
  while (get(q) != NULL) {
    i++;
  }
  printf("An additional %d entries expurged\n", i);
  printf("Done. Total entries: %d\n", total +=  -i);


  printf("Press enter to continue.\n");
  while (getchar() != '\n')
    ;
  printf("\nDestroying queue\n");
  destroy(q);

  printf("Press enter to continue.\n");
  while (getchar() != '\n')
    ;
 
}
