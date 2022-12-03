#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  int len = 0;
  va_list(arg_list);
  va_start(arg_list, format);
  for (int i = 0; format[i] != '\0'; i++) {
    if (format[i] == '%') {
      i++;
      int token = i;
      char specif = get_specif(format, token, &i);
      //formatation_str(str, format, &i, token);
      if(specif = SPECIFS[0]) {
        specif_char(str, format, token, &i, &len, &arg_list);
      }
      printf("%c\n", specif);
    } else {
      str[len] = format[i];
      len++;
      i++;
    }
  }
  va_end(arg_list);
  return len;
}

// #pragma region parser
char skip_part(const char *format, int token, int i, int *skip) {
  if (i--) /* flags */
    while (format[token] && strchr(FLAGS, format[token])) token += 1;
  if (i--) { /* width */
    if (format[token] == STAR)
      token += 1;
    else
      while (format[token] && strchr(DIGITS, format[token])) token += 1;
  }
  if (i--) { /* precision */
    if (format[token] == DOT) {
      token += 1;
      if (format[token] == STAR)
        token += 1;
      else
        while (format[token] && strchr(DIGITS, format[token])) token += 1;
    }
  }
  if (i--) /* length */
    if (format[token] && strchr(LENGHT, format[token])) token += 1;
  if (i) /* specifier */
    if (format[token] && strchr(SPECIFS, format[token])) token += 1;
  if(*skip != 0) *skip == token;
  return format[token];
}

// int get_flag(const char *token, char flag) {
//   while (strchr(FLAGS, *token)) {
//     if (*token == flag) return 1;
//     token++;
//   }
//   return 0;
// }

int get_width(const char *format, int token) {
  int num = 1;
  char ch = skip_part(format, token, 1, num);
  int result = -1;
  if (format[num] == STAR) {
    result = -2;
  }
  if (atol(format[num], num)) {
    result = atol(format, num);
  }
  return result;
}

// int get_rigor(const char *token) {
//   token = skip_part(token, 2);
//   int result = -1;
//   if (*token == DOT) {
//     token++;
//     result = -3;
//     if (*token == STAR) {
//       result = -2;
//     }
//     if (atol(token)) {
//       result = atol(token);
//     } else if (*token == '0') {
//       /*  .. == '0' --- because atol() returns 0 as fail, we should
//        *      check for 0 value additionally
//        */
//       result = 0;
//     }
//   }
//   return result;
// }
// char get_lenght(const char *token) {
//   token = skip_part(token, 3);
//   if (*token && strchr(LENGHT, *token)) {
//     return *token;
//   }
//   return '\0';
// }

char get_specif(const char *format, int token, int *scip) {
  char *spec = skip_part(format, token, 4, &scip);
  if (spec && strchr(SPECIFS, spec)) {
    return spec;
  }
  return '\0';
}

//#pragma endregion



void specif_char(char *str, const char *format, int token, int *i, int *len, va_list *arg_list) {
  int scip = 0;

}

// Преобразование типов

long atol(const char *str, int num) {
  long result = 0;
  int is_minus = 0;
  if (str[num] == '-') {
    is_minus = 1;
    num++;
  }
  while (*str && strchr(DIGITS, *str)) {
    result *= 10;
    result += str[num] - '0';
    num++;
  }
  return is_minus ? -result : result;
}


// шаблон: %[флаги][ширина][.точность][длина]спецификатор
// парсер спецификаторов c, d, i, f, s, u, % доп: g, G, e, E, x, X, o, n, p
// парсер флагов  -, +, (пробел) доп: #, 0
// парсер ширины (число) доп: *
// парсер точности .(число) доп: .*
// парсер длины h, l доп: L
