/*
Ponteiros em C são variáveis que armazenam endereços de memória de outras variáveis.
Eles são fundamentais para manipulação dinâmica de memória, arrays,
strings e funções. Vamos explorar desde o básico até exemplos práticos:
*/
/*
1. Conceitos Básicos
Declaração: tipo *nome_ponteiro; (ex: int *p;).

Operadores:

&: Retorna o endereço de uma variável.

*: Acessa o valor no endereço armazenado pelo ponteiro (dereferência).

Exemplo 1: Ponteiro Simples
*/
#include <stdio.h>

int main()
{
    int num = 10;
    int *p;   // Declara um ponteiro para int
    p = &num; // p armazena o endereço de num

    printf("Valor de num: %d\n", num);      // 10
    printf("Endereço de num: %p\n", &num);  // Endereço em hexadecimal
    printf("Valor via ponteiro: %d\n", *p); // 10 (dereferência)

    *p = 20;                                // Modifica num indiretamente
    printf("Novo valor de num: %d\n", num); // 20

    return 0;
}

/*
2. Ponteiros e Arrays
Em C, arrays são ponteiros constantes para o primeiro elemento.

Exemplo 2: Acessando Array com Ponteiros
*/
#include <stdio.h>

int main()
{
    int vetor[3] = {10, 20, 30};
    int *p = vetor; // p aponta para o primeiro elemento (vetor[0])

    for (int i = 0; i < 3; i++)
    {
        printf("vetor[%d] = %d\n", i, *(p + i)); // Acesso via aritmética de ponteiros
    }
    // Saída:
    // vetor[0] = 10
    // vetor[1] = 20
    // vetor[2] = 30

    return 0;
}

/*
3. Ponteiros e Strings
Strings são arrays de char, e ponteiros são usados para manipulá-las.

Exemplo 3: Percorrendo uma String
*/
#include <stdio.h>

int main()
{
    char texto[] = "Hello";
    char *p = texto;

    while (*p != '\0')
    {
        printf("%c ", *p);
        p++; // Avança para o próximo caractere
    }
    // Saída: H e l l o

    return 0;
}

/*
4. Ponteiros para Funções
Permitem passar funções como argumentos ou criar callbacks.

Exemplo 4: Função como Parâmetro
*/
#include <stdio.h>

void dobrar(int *x)
{
    *x *= 2;
}

int main()
{
    int valor = 5;
    dobrar(&valor);                       // Passa o endereço de 'valor'
    printf("Valor dobrado: %d\n", valor); // 10

    return 0;
}

/*
5. Alocação Dinâmica de Memória
Ponteiros são essenciais para alocar memória em tempo de execução (malloc, free).

Exemplo 5: Array Dinâmico
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    // Aloca memória para 'tamanho' inteiros
    int *array = (int *)malloc(tamanho * sizeof(int));

    if (array == NULL)
    {
        printf("Erro na alocação!\n");
        return 1;
    }

    // Preenche o array
    for (int i = 0; i < tamanho; i++)
    {
        array[i] = i * 10;
    }

    // Imprime
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", array[i]); // Exemplo: 0 10 20...
    }

    free(array); // Libera a memória
    return 0;
}

/*
6. Ponteiros para Ponteiros
Úteis para matrizes dinâmicas ou listas encadeadas.

Exemplo 6: Matriz Dinâmica (Ponteiro para Ponteiro)
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas = 2, colunas = 3;

    // Aloca memória para as linhas (array de ponteiros)
    int **matriz = (int **)malloc(linhas * sizeof(int *));

    for (int i = 0; i < linhas; i++)
    {
        // Aloca memória para as colunas de cada linha
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    // Preenche a matriz
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            matriz[i][j] = i + j;
        }
    }

    // Imprime
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Libera a memória
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

/*
7. Cuidados Comuns
Ponteiros Não Inicializados:
int *p; // Ponteiro "selvagem" (aponta para lixo de memória)
*p = 10; // Comportamento indefinido!
*/
// Vazamento de Memória: Sempre use free após malloc/calloc.
// Dangling Pointers: Ponteiros que apontam para memória já liberada.
/*
int *p = (int*) malloc(sizeof(int));
free(p);
*p = 5; // Inválido! 'p' é um dangling pointer.
*/
/**/