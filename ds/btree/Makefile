CC = gcc
CFLAGS = -Wall 
main: main.c btree.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -rf *.o main
