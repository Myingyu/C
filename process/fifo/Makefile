CC = gcc
CFLAGS = -g -Wall

create_fifo: create_fifo.c
	$(CC) $(CFLAGS) $^ -o $@
read_fifo: read_fifo.c
	$(CC) $(CFLAGS) $^ -o $@
write_fifo: write_fifo.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY:clean
clean:
	rm -rf *.o