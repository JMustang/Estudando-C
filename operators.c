#include <stdio.h>
#include <stdlib.h>

// + Adição
// - Subtração
// * Multiplicação
// / Divisão
// % Resto da divisãp
// ++ Adição (adiciona 1)
// -- Redução (diminue 1)

int main(int argc, char *argv[])
{
  int x = 12;
  int result1 = x + 8;
  
  printf("%d\n", result1);

  int y = 12;
  
  printf("%d\n", y+8);


  int z = 12;
  int result2 = z / 8;
  
  printf("%d\n", result2);

  int a = 12;
  int result3 = a % 8;
  
  printf("%d\n", result3);

  int b = 12;
  
  printf("%d\n", ++b);

  int c = (4 / 2) + (6 * 5) - 1;
  
  printf(" %d\n", c);


  int g = 5 + 2 * 9 / 3 - 3;

  printf("%d\n", g);

  return EXIT_SUCCESS;
}
