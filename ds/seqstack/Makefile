CC = gcc 
CFLAGS = -g -Wall

main: main.c seqstack.c
	$(CC) $(CFLAGS) $^ -o $@
.PHONY:clean
clean:
	rm -rf *.o