#include <stdio.h>

int main() {
  int numero;
  int soma = 0;

  printf("Digite números positivos para somar. Digite um número negativo ou "
         "zero para parar.\n");

  while (1) { // Loop infinito
    printf("Digite um número: ");
    scanf("%d", &numero);

    // Verifica se o número é negativo ou zero
    if (numero <= 0) {
      break; // Sai do loop
    }

    soma += numero; // Adiciona o número à soma
  }

  printf("A soma dos números positivos digitados é: %d\n", soma);

  return 0;
}
