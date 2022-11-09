#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  int lenght = 0;
  va_list ap;
  va_start(ap, format);
  for (int i = 0; format[i] != '\0'; i++, lenght++) {
    if (format[i] == '%') {
      if (format[i + 1] != '\0') {
        i++;
      } else {
        break;
      }
      // парсер флаги
      if (format[i] == '-' || format[i] == '+' || format[i] == ' ' ||
          format[i] == '#' || format[i] == '0') {
        if (format[i + 1] != '\0') {
          i++;
        } else {
          break;
        }
      }
      // парсер ширина
      if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*') {
        if (format[i] >= '1' && format[i] <= '9') {
          if (format[i + 1] >= '0' && format[i + 1] <= '9') {
            if (format[i + 1] != '\0') {
              i++;
            } else {
              break;
            }
          }
        }
        if (format[i + 1] != '\0') {
          i++;
        } else {
          break;
        }
      }
      // парсер точности
      if (format[i] == '.') {
        if (format[i + 1] != '\0') {
          i++;
        } else {
          break;
        }
        if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*') {
          if (format[i] >= '1' && format[i] <= '9') {
            if (format[i + 1] >= '0' && format[i + 1] <= '9') {
              if (format[i + 1] != '\0') {
                i++;
              } else {
                break;
              }
            }
          }
          if (format[i + 1] != '\0') {
            i++;
          } else {
            break;
          }
        }
      }
      // парсер длины
      if (format[i] == 'h' || format[i] == 'l' || format[i] == 'L') {
        if (format[i + 1] != '\0') {
          i++;
        } else {
          break;
        }
      }
      // парсер спецификаторов
      if (format[i] == 'c' || format[i] == 'd' || format[i] == 'i' ||
          format[i] == 'f' || format[i] == 's' || format[i] == 'u' ||
          format[i] == '%' || format[i] == 'g' || format[i] == 'G' ||
          format[i] == 'e' || format[i] == 'E' || format[i] == 'x' ||
          format[i] == 'X' || format[i] == 'o' || format[i] == 'n' ||
          format[i] == 'p') {
        if (format[i + 1] != '\0') {
          i++;
        } else {
          break;
        }
      }
    } else {
      str[lenght] = format[i];
    }
  }
  return lenght;
}

// шаблон: %[флаги][ширина][.точность][длина]спецификатор
// парсер спецификаторов c, d, i, f, s, u, % доп: g, G, e, E, x, X, o, n, p
// парсер флагов  -, +, (пробел) доп: #, 0
// парсер ширины (число) доп: *
// парсер точности .(число) доп: .*
// парсер длины h, l доп: L