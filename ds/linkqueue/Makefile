CC = gcc
CFLAGS = -o -Wall

main: main.c linkqueue.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY:clean
clean:
	rm -rf *.o main