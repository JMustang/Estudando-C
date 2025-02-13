#include <math.h>
#include <stdio.h>

void greet() { printf("Good day!\n"); }

int soma(int a, int b) { return a + b; }

int main() {

  greet();

  float raiz = sqrt(16);
  printf("A raiz quadrada de 16 é %f\n", raiz);

  int result = soma(4, 6);
  printf("resultado da soma é %d\n", result);
  return 0;
}
