CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE

all: s21_cat

s21_cat : main.o reader.o parser.o
	${CC} ${CFLAGS} main.o reader.o parser.o -o s21_cat

main.o : main.c
	${CC} ${CFLAGS} -c main.c

reader.o : reader.c
	${CC} ${CFLAGS} -c reader.c

parser.o : parser.c
	${CC} ${CFLAGS} -c parser.c

clean :
	rm -rf *.o s21_cat *.log

rebuild : clean all

test_f : rebuild
	sh test_func_cat.sh

test_l : rebuild
	sh test_leak_cat.sh

style: 
	cp ../../materials/linters/.clang-format ../../src
	clang-format -n *.c *.h
	rm -rf ../../src/.clang-format
