#include "s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.

char *s21_strchr(const char *str, int c) {
    while(*str != '\0') {
        if (*str == (char) c) {
            return str;
        }
        str++;
    }
    return s21_NULL;
}
