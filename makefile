CC = gcc
CFLAGS = -ggdb3 -Wall -pedantic -ansi -std=c99 -O

all: queue_lnk_test queue_arr_test

queue_lnk_test: queue_lnk_test.o queue_lnk.o
	$(CC) $(CFLAGS) -o queue_lnk_test queue_lnk_test.o queue_lnk.o

queue_arr_test:	queue_arr_test.o queue_arr.o
	$(CC) $(CFLAGS) -o queue_arr_test queue_arr_test.o queue_arr.o

queue_arr_test.o: queue_arr_test.c queue_arr.h
	$(CC) $(CFLAGS) -c queue_arr_test.c

queue_arr.o:	queue_arr.c queue_arr.h
	$(CC) $(CFLAGS) -c queue_arr.c


queue_lnk_test.o: queue_lnk_test.c queue_lnk.h
	$(CC) $(CFLAGS) -c queue_lnk_test.c

queue_lnk.o: queue_lnk.c queue_lnk.h
	$(CC) $(CFLAGS) -c queue_lnk.c
