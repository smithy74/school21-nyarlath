#include "s21_string.h"

// Сравнивает первые n байтов str1 и str2.

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    unsigned char *s1 = (unsigned char *)str1;
    unsigned char *s2 = (unsigned char *)str2;
    s21_size_t i = 0, flag = 0;
    while (i < n) {
        if (s1[i] != s2[i]) {
            flag = (s1[i] - s2[i]);
            i += n;
        }
        i++;
    }
    return flag;
}

