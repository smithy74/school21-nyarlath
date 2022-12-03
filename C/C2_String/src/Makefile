FLAGS = -std=c11 -Wall -Werror -Wextra
OS := $(shell uname)

ifeq ($(OS),Linux)
	CHFLAGS = -lcheck -lm -lpthread -lrt -lsubunit
else
	CHFLAGS = -lcheck -lm -lpthread
endif

all: clean s21_string.a

s21_string.o:
	gcc $(FLAGS) -c s21_*.c

s21_string.a: s21_string.o
	ar -cr s21_string.a *.o
	rm -rf *.o

unit-test.o:
	gcc $(FLAGS) -c unit_test.c s21_*.c

#test: clean
#	gcc $(FLAGS)  s21_string.c s21_sprintf.c s21_sscanf.c unit-test.c $(CHFLAGS) -o unit-test

#Link with static lib
test: unit_test.c s21_string.a
	gcc $(FLAGS)  s21_string.a unit_test.c $(CHFLAGS) -o unit-test

test1: clean
	gcc $(FLAGS)  s21_string.c s21_sprintf.c s21_sscanf.c test_telega.c $(CHFLAGS) -o unit-test

#test: clean unit-test.o s21_string.a
#	gcc s21_string.a unit-test.o -o unit-test $(FLAGS)


#Linux version
#test: unit-test.o
#	gcc s21_string.a unit-test.o -lcheck -lm -lpthread -lrt -lsubunit -o test

gcov_report: s21_string.a
	gcc --coverage -lcheck s21_*.c unit_test.c -o gcov
	./gcov
	lcov -t "./gcov" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html
	rm -rf *.gcno *gcda *.gcov


clean:
	rm -rf *.o *.a unit-test
	rm -rf *.gcno *gcda *.gcov gcov program
	rm -rf report report.info