CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 -D_GNU_SOURCE
SOURCE_TEST=test_cat/test_1_cat.txt test_cat/test_2_cat.txt test_cat/test_3_cat.txt test_cat/test_4_cat.txt test_cat/test_5_cat.txt test_cat/test_case_cat.txt test_cat/s21_string

all: s21_string

s21_string: s21_string.c
	$(CC) $(CFLAGS) s21_string.c -o s21_string

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	clang-format -n *.c *.h
	python3 ../../materials/linters/cpplint.py --extensions=c *.c *.h
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt s21_string

clean:
	rm -rf s21_string *.o

rebuild:
	clean all
