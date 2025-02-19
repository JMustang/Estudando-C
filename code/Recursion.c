/*
Estrutura Básica de uma Função Recursiva
Uma função recursiva precisa de:

Caso Base: Condição que interrompe a recursão (evita loops infinitos).

Passo Recursivo: Chamada à função com um subproblema menor.

Exemplo 1: Fatorial de um Número
O fatorial de n (n!) é n * (n-1) * ... * 1.
Caso Base: 0! = 1 ou 1! = 1.
Passo Recursivo: n! = n * (n-1)!.
*/
#include <stdio.h>

int fatorial(int n)
{
    if (n <= 1)
    { // Caso base
        return 1;
    }
    else
    { // Passo recursivo
        return n * fatorial(n - 1);
    }
}

int main()
{
    int num = 5;
    printf("Fatorial de %d: %d\n", num, fatorial(num)); // Saída: 120
    return 0;
}
/*
Exemplo 2: Sequência de Fibonacci
Cada número é a soma dos dois anteriores.
Caso Base: fib(0) = 0, fib(1) = 1.
Passo Recursivo: fib(n) = fib(n-1) + fib(n-2).
*/
#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0)
        return 0; // Caso base 1
    if (n == 1)
        return 1;                               // Caso base 2
    return fibonacci(n - 1) + fibonacci(n - 2); // Passo recursivo
}

int main()
{
    int num = 6;
    printf("Fibonacci de %d: %d\n", num, fibonacci(num)); // Saída: 8 (0,1,1,2,3,5,8)
    return 0;
    // Observação: Essa abordagem é ineficiente para números grandes,
    // pois recalcula os mesmos valores múltiplas vezes.
}

/*
Exemplo 3: Torre de Hanói
Resolver o quebra-cabeça movendo discos entre torres, seguindo regras.
Passo Recursivo:

Mover n-1 discos da origem para a auxiliar.

Mover o disco restante para o destino.

Mover n-1 discos da auxiliar para o destino.
*/
#include <stdio.h>

void torreHanoi(int n, char origem, char destino, char auxiliar)
{
    if (n == 1)
    { // Caso base
        printf("Mova disco 1 de %c para %c\n", origem, destino);
        return;
    }
    torreHanoi(n - 1, origem, auxiliar, destino);                // Passo 1
    printf("Mova disco %d de %c para %c\n", n, origem, destino); // Passo 2
    torreHanoi(n - 1, auxiliar, destino, origem);                // Passo 3
}

int main()
{
    int discos = 3;
    torreHanoi(discos, 'A', 'C', 'B'); // Origem: A, Destino: C, Auxiliar: B
    return 0;
}

/*
Exemplo 4: Verificar Palíndromo
Uma string é palíndromo se pode ser lida igualmente de trás para frente.
Caso Base: String vazia ou com um caractere.
Passo Recursivo: Comparar primeiro e último caractere,
depois chamar recursão para a substring interna.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindromo(char *str, int inicio, int fim)
{
    if (inicio >= fim)
        return 1; // Caso base
    if (tolower(str[inicio]) != tolower(str[fim]))
        return 0;                                  // Caracteres diferentes
    return isPalindromo(str, inicio + 1, fim - 1); // Passo recursivo
}

int main()
{
    char palavra[] = "Radar";
    int tamanho = strlen(palavra) - 1; // Índice do último caractere

    if (isPalindromo(palavra, 0, tamanho))
    {
        printf("É um palíndromo!\n"); // Saída: É um palíndromo!
    }
    else
    {
        printf("Não é um palíndromo.\n");
    }
    return 0;
}