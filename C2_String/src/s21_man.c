#include "s21_sprintf.h"

int main(void) {
    char buff[1024] = {0};
    int lenght = s21_sprintf(buff, "My name is: %s", "Kristina");
    printf("Длина строки: %d\n", lenght);
    printf("Строка: %s\n", buff);
    char buff2[1024] = {0};
    int lenght2 = sprintf(buff2, "My name is:%c", ' ');
    printf("Длина строки: %d\n", lenght2);
    printf("Строка: %s\n", buff2);
}