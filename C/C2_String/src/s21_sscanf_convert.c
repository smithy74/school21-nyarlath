#include "s21_sscanf.h"

int convert_calc(int arglue) {
  if (arglue >= '0' && arglue <= '9')
    arglue -= '0';
  else if (arglue == 'x')
    arglue = 0;
  else if (arglue == 'a' || arglue == 'A')
    arglue = 10;
  else if (arglue == 'b' || arglue == 'B')
    arglue = 11;
  else if (arglue == 'c' || arglue == 'C')
    arglue = 12;
  else if (arglue == 'd' || arglue == 'D')
    arglue = 13;
  else if (arglue == 'e' || arglue == 'E')
    arglue = 14;
  else if (arglue == 'f' || arglue == 'F')
    arglue = 15;
  return arglue;
}

int arg_lid(int num, const char *str_pattern) {
  int res = 0;
  if (num == 10 && (*str_pattern >= '0' && *str_pattern <= '9')) res = 1;
  if (num == 8 && (*str_pattern >= '0' && *str_pattern <= '7')) res = 1;
  if (num == 16 && ((*str_pattern >= '0' && *str_pattern <= '9') ||
                    (*str_pattern >= 'a' && *str_pattern <= 'f') ||
                    (*str_pattern >= 'A' && *str_pattern <= 'F') ||
                    (*str_pattern == 'x' || *str_pattern == 'X')))
    res = 1;
  return res;
}

const char *if_minus(int *flags, const char *str_pattern) {
  if (*str_pattern == '-') {
    flags[4] = 1;
    flags[1]--;
    str_pattern++;
  }
  return str_pattern;
}

void count_arg_riable(int count, int *count_f, const int *flags, int *amt) {
  if (count && *count_f && flags[2])
    *amt += 1;
  else if (!count)
    *count_f = 0;
}

int str_arg_lid(char c) {
  int res = 1;
  switch (c) {
    case '\0':
    case '\n':
    case '\t':
    case '\v':
    case '\f':
    case '\r':
    case ' ':
      res = 0;
      break;
  }
  return res;
}
