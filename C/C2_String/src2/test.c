#include <stdio.h>
#include <string.h>

int main() {
  // int age;
  // char name[30], country[30], details[100];

  // printf("Enter your name : ");
  // fgets(name, 30, stdin);

  // printf("Enter your country : ");
  // fgets(country, 30, stdin);

  // printf("Enter your age : ");
  // scanf("%d", &age);

  // sprintf(details, "Name : %s Age : %d Country : %s ", name, age, country);
  // printf("details : \n\n %s", details);
  //   printf("%ld", sizeof(details));

  char *buffer;
  int j; //i, j;
  //double fp;
  char *s = "computer";
  //char c;
  /*  форматирует и печатает различные данные */
  j = sprintf(buffer, "%s\n", s);
  // printf("%d\n", j);
  // j += sprintf(buffer + j, "%c\n", c);
  // printf("%d\n", j);
  // j += sprintf(buffer + j, "%d\n", i);
  // printf("%d\n", j);
  // j += sprintf(buffer + j, "%f\n", fp);
  printf("%d\n", j);
  printf("%s\n", buffer);

  return 0;
}