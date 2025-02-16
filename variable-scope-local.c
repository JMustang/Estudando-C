#include <stdio.h>

// Local veriables are only accessible within the function they are declared in
void exemplo()
{
    int x = 10; // Variável local à função 'exemplo'
    printf("Dentro de exemplo(): x = %d\n", x);
}

int main()
{
    exemplo();
    // printf("Fora de exemplo(): x = %d\n", x); // ERRO: 'x' não existe aqui
    return 0;
}
// Explicação: x só existe dentro da função exemplo().
