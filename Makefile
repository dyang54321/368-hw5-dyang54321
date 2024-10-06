WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFLAGS = -DOPEN -DCLOSE -DLIST_PRINT -DSWITCH
SRCS = main.c a5.c
OBJS = $(SRCS:%.c=%.o)

a5: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o a5

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: a5
	$(VAL) ./a5

testall: test1 test2 test3 test4 test5

test1: a5
	./a5

clean:
	rm -f a5 *.o *.txt output? *~