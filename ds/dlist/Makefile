CC = gcc
CFALGS = -O0 -g -Wall


main: main.c dlist.c
	$(CC) $(CFALGS) $^ -o $@

.PHONY: clean
clean:
	rm -rf main