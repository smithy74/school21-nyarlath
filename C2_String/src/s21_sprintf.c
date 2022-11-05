#include "string.h"

int sprintf(char *str, const char *format, ...) {
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; format[j] != '\0'; j++) {
            if (format[j] == '%') {
                j++;
                switch (format[j])
                {
                case /* constant-expression */:
                    /* code */
                    break;
                
                default:
                    break;
                }
            }
        }
    }
}

// парсер спецификаторов c, d, i, f, s, u, % доп: g, G, e, E, x, X, o, n, p
// парсер флагов  -, +, (пробел) доп: #, 0
// парсер ширины (число) доп: *
// парсер точности .(число) доп: .*
// парсер длины h, l доп: L