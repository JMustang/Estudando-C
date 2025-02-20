/*
Claro! Arrays em C são estruturas que armazenam uma coleção de
elementos do mesmo tipo em posições contíguas de memória. Eles são
amplamente usados para organizar dados de forma eficiente.
Vamos explorar desde conceitos básicos até exemplos práticos:
*/
/*
1. Declaração e Inicialização de Arrays
Array Unidimensional (1D)
*/
#include <stdio.h>

int main()
{
    // Declaração de um array de inteiros com 5 elementos
    int numeros[5];

    // Inicialização durante a declaração
    int valores[3] = {10, 20, 30};

    // Acesso aos elementos (índices começam em 0)
    printf("Primeiro elemento: %d\n", valores[0]); // 10
    printf("Terceiro elemento: %d\n", valores[2]); // 30

    return 0;
}
// Array Multidimensional (2D) – Matriz
#include <stdio.h>

int main()
{
    // Declaração de uma matriz 2x3
    int matriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    // Acesso ao elemento da linha 1, coluna 2 (índices começam em 0)
    printf("Elemento [1][2]: %d\n", matriz[1][2]); // 6

    return 0;
}

/*
2. Iterando sobre Arrays
Exemplo 1: Loop em Array 1D
*/
#include <stdio.h>

int main()
{
    int notas[5] = {7, 8, 9, 6, 10};

    // Calcula a média das notas
    float soma = 0;
    for (int i = 0; i < 5; i++)
    {
        soma += notas[i];
    }
    printf("Média: %.2f\n", soma / 5); // Saída: 8.00

    return 0;
}
// Exemplo 2: Loop em Array 2D
#include <stdio.h>

int main()
{
    int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // Imprime todos os elementos da matriz
    for (int linha = 0; linha < 2; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            printf("%d ", matriz[linha][coluna]);
        }
        printf("\n");
    }
    // Saída:
    // 1 2 3
    // 4 5 6

    return 0;
}

/*
3. Arrays e Funções
Arrays são passados por referência para funções
(modificações afetam o array original).

Exemplo 3: Passando Array para Função
*/
#include <stdio.h>

// Função para dobrar os valores de um array
void dobrarValores(int arr[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        arr[i] *= 2;
    }
}

int main()
{
    int numeros[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]); // Calcula o tamanho

    dobrarValores(numeros, tamanho);

    // Imprime os valores modificados
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", numeros[i]); // Saída: 2 4 6 8 10
    }

    return 0;
}

/*
4. Arrays Dinâmicos (Usando Ponteiros)
Arrays estáticos têm tamanho fixo, mas você pode criar arrays dinâmicos com alocação de memória (malloc, calloc).

Exemplo 4: Alocação Dinâmica
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    // Aloca memória para o array
    int *arr = (int *)malloc(tamanho * sizeof(int));

    if (arr == NULL)
    {
        printf("Erro na alocação!\n");
        return 1;
    }

    // Preenche o array
    for (int i = 0; i < tamanho; i++)
    {
        arr[i] = i * 10;
    }

    // Imprime os valores
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", arr[i]); // Exemplo: 0 10 20 30...
    }

    free(arr); // Libera a memória alocada
    return 0;
}

/*
5. Cuidados Comuns
Índices fora dos limites: Acesso a posições inválidas (ex: arr[5] em um array de tamanho 5) causa comportamento indefinido.

Tamanho fixo: Arrays estáticos não podem ser redimensionados.

Strings são arrays de caracteres: Terminadas com '\0' (null terminator).
*/
char nome[] = "Ana"; // Equivalente a {'A', 'n', 'a', '\0'}

// Exemplo Prático Final: Busca Linear

#include <stdio.h>

int buscaLinear(int arr[], int tamanho, int alvo)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (arr[i] == alvo)
        {
            return i; // Retorna o índice se encontrado
        }
    }
    return -1; // Não encontrado
}

int main()
{
    int numeros[] = {4, 2, 9, 7, 5};
    int alvo = 9;
    int indice = buscaLinear(numeros, 5, alvo);

    if (indice != -1)
    {
        printf("Valor %d encontrado no índice %d.\n", alvo, indice); // Saída: 9 no índice 2
    }
    else
    {
        printf("Valor não encontrado.\n");
    }

    return 0;
}