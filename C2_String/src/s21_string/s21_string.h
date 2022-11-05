#ifndef SRC_S21_STRING_H
#define SRC_S21_STRING_H

// Функции поиска
void *s21_memchr(const void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char* haystack, const char *needle);

// Функции копированияю
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);

// Функции добавления
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t count);

// Функции сравнения
int s21_strcmp(const char *str1, const char *str2);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

// Функции вычисления
s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);
s21_size_t s21_strspn(const char *str1, const char *str2);

// Функция поиска ошибок
char *s21_strerror(int errnum);

// Функция разбивки
char *s21_strtok(char *str, const char *delim);

#endif  //SRC_S21_STRING_H
