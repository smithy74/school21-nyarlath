#include "s21_string.h"

// Выполняет поиск первого вхождения символа c
// В первых n байтах строки, на которую указывает аргумент str.
/**
 * Функция s21_memchr - Выполняет поиск первого вхождения символа c
 * @param str аргумент строки
 * @param c количество
 * @param n размер
 * @return возвращает указатель на строку
*/
void *s21_memchr(const void *str, int c, s21_size_t n) {
    unsigned char *str1 = (unsigned char*)str;
    int check = 0;
    while (n--) {
        if (*str1 == (unsigned char)c) {
            check = 1;
            break;
        }
        str1++;
    }
    if (check != 1) {
        str1 = s21_NULL;
    }
    return str1;
}
