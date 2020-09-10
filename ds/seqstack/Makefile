CC = gcc 
CFLAGS = -c -Wall

main: main.c seqstack.c
	$(CC) $(CFLAGS) $@ -o $^

.PHONY:clean
clean:
	rm -rf *.o