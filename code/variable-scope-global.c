#include <stdio.h>

// Variáveis declaradas fora de todas as funções
// são globais e podem ser acessadas em qualquer
// lugar do arquivo após sua declaração.

int global = 100; // Variável global

void funcao1()
{
    printf("Dentro de funcao1(): global = %d\n", global);
    global++; // Modifica a variável global
}

void funcao2()
{
    printf("Dentro de funcao2(): global = %d\n", global);
}

int main()
{
    funcao1();
    funcao2();
    printf("Em main(): global = %d\n", global);
    return 0;
}