CC = gcc
CFLAGS = -O0 -g -Wall


linklistmain: linklistmain.c linklist.c
	 $(CC) $(CFLAGS) $^ -o $@ 

.PHONY:clean
clean:
	rm -rf linklistmain