CC = gcc
CFLAGS = -Wall 
main: main.c btree.c linkqueue.c linkstack.c
	$(CC) $(CFLAGS) $^ -o $@
# linkstackmain: linkstackmain.c linkstack.c
# 	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -rf *.o main
