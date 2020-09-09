CC =  gcc
CFLAGS = -g -Wall

main: main.c linklist.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY:clean
clean:
	rm - rf *.o main
