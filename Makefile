WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFLAGS = -DOPEN -DCLOSE -DLIST_PRINT -DSWITCH
SRCS = main.c a5.c
OBJS = $(SRCS:%.c=%.o)

a5: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o a5 -lm

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: a5
	$(VAL) ./a5 points.tx

test: a5
	./a5 points.tx

clean:
	rm -f a5 *.o *.txt output? *~