#include "s21_string.h"

// Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest.

char *s21_strcat(char *dest, const char *src) {
    char *flag;
    char *strr = dest;
    while (*strr != '\0') {
        strr++;
    }
    while (*src != '\0') {
        *strr++ = *src++;
    }
    *strr = '\0';
    flag = dest;
    return flag;
}
