CC = gcc
CFLAGS = -Wall 
main: main.c btree.c linkqueue.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -rf *.o main
