
#include <stdio.h>

// Uma variável local pode "esconder" uma variável global com o mesmo nome.

int x = 10; // Variável global

void funcao()
{
    int x = 20;                              // Variável local "esconde" a global
    printf("Dentro da funcao: x = %d\n", x); // Usa o 'x' local
}

int main()
{
    printf("Em main (antes da funcao): x = %d\n", x); // Global
    funcao();
    printf("Em main (depois da funcao): x = %d\n", x); // Global
    return 0;
}