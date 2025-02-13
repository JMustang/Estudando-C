#include <stdio.h>

int main() {
  int a = 10;
  int b = 20;

  if (a >= b) {
    printf("%d é maior que %d.\n", a, b);
  } else {
    printf("%d é menor que %d.\n", a, b);
  }

  int age = 16;
  if (age >= 18) {
    printf("Maior de idade, ja pode votar.\n");
  } else {
    printf("Menor de idade, ainda não pode votar.\n");
  }

  int z = 5;
  if (!(z % 2 == 0)) {
    printf("Inside if");
  } else {
    printf("Inside else");
  }

  return 0;
}
