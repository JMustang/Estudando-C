#include <stdio.h>

// static em variáveis locais :
// Mantém o valor entre chamadas da função, mas o escopo ainda é local.

// static em variáveis globais :
// Restringe o escopo ao arquivo onde foi
// declarada(não é visível em outros arquivos via extern).

void contador()
{
    static int count = 0; // Preserva o valor entre chamadas
    count++;
    printf("Contador: %d\n", count);
}

int main()
{
    contador(); // Contador: 1
    contador(); // Contador: 2
    contador(); // Contador: 3
    return 0;
}