CC = gcc
CFLAGS = -O0 -g -Wall


seqlistmain: seqlistmain.c seqlist.c
	 $(CC) $(CFLAGS) $^ -o $@ 

.PHONY:clean
clean:
	rm -rf seqlistmain