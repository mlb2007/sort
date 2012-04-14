CC=gcc
CPP=g++
CPPFLAGS=-g -Wall -std=c++0x
LDFLAGS=

all: lcs.o
	${CPP} ${LDFLAGS} -o Test_LCS -lpthread -lm $<

lcs: lcs.o
	${CPP} ${LDFLAGS} -o Test_LCS -lpthread -lm $<

insert_sort: insertion_sort.o
	${CPP} ${LDFLAGS} -o Test_Sort -lpthread -lm $<

%.o: %.cpp Makefile
	${CPP} ${CPPFLAGS} -c $<

clean:
	rm -f *.d *.o Test_LCS Test_Sort
