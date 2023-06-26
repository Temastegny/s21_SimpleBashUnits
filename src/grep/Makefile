CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -D_GNU_SOURCE

all : s21_grep

s21_grep : main.o reader.o parser.o
		${CC} ${CFLAGS} main.o reader.o parser.o -o s21_grep

main.o : main.c
		${CC} ${CFLAGS} -c main.c

reader.o : reader.c
		${CC} ${CFLAGS} -c reader.c

parser.o : parser.c
		${CC} ${CFLAGS} -c parser.c

clean : 
		rm -rf *.o s21_grep *.log

rebuild : clean all

test_f : rebuild
		sh test_func_grep.sh

test_l : rebuild
		sh test_leak_grep.sh

style: 
		cp ../../materials/linters/.clang-format ../../src
		clang-format -n *.c *.h
		rm -rf ../../src/.clang-format
