#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>

#define DOT '.'
#define STAR '*'
#define FLAGS "-+ #0"
#define DIGITS "0123456789"
#define LENGHT "hlL"
#define SPECIFS "cdieEfgGosuxXpn%"


int s21_sprintf(char *str, const char *format, ...);

// Парсинг после процента
char skip_part(const char *format, int *token, int i);
// int get_flag(const char *token, char flag);
// int get_width(const char *token);
// int get_rigor(const char *token);
// char get_lenght(const char *token);
char get_specif(const char *format, int *token);

long atol(const char *str);

#endif  // S21_SPRINTF_H
