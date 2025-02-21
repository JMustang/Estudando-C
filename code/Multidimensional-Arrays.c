/*
1. Declaração e Inicialização
Array 2D (Matriz)
Declarado com dois índices: [linhas][colunas].
*/
#include <stdio.h>

int main()
{
    // Declaração e inicialização de uma matriz 3x3
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // Declaração sem inicialização (preenchida posteriormente)
    int grid[2][2];
    grid[0][0] = 10;
    grid[0][1] = 20;

    return 0;
}

/*
Array 3D
Declarado com três índices: [profundidade][linhas][colunas].
*/
int cubo[2][3][3] = {
    {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},         // Camada 0
    {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}} // Camada 1
};

/*
2. Acesso e Modificação de Elementos
Os elementos são acessados usando índices para cada dimensão.
*/
#include <stdio.h>

int main()
{
    int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // Acessando elemento da linha 1, coluna 2 (índices começam em 0)
    printf("Elemento [1][2]: %d\n", matriz[1][2]); // Saída: 6

    // Modificando um elemento
    matriz[0][1] = 100;
    printf("Novo valor [0][1]: %d\n", matriz[0][1]); // Saída: 100

    return 0;
}

/*
3. Iterando sobre Arrays Multidimensionais
Use loops aninhados para percorrer todas as dimensões.

Exemplo 1: Percorrendo uma Matriz 2D
*/
#include <stdio.h>

int main()
{
    int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};

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
Exemplo 2: Percorrendo um Array 3D
*/
#include <stdio.h>

int main()
{
    int cubo[2][2][2] = {
        {{1, 2}, {3, 4}},
        {{5, 6}, {7, 8}}};

    for (int camada = 0; camada < 2; camada++)
    {
        printf("Camada %d:\n", camada);
        for (int linha = 0; linha < 2; linha++)
        {
            for (int coluna = 0; coluna < 2; coluna++)
            {
                printf("%d ", cubo[camada][linha][coluna]);
            }
            printf("\n");
        }
    }
    // Saída:
    // Camada 0:
    // 1 2
    // 3 4
    // Camada 1:
    // 5 6
    // 7 8

    return 0;
}

/*
4. Passando Arrays Multidimensionais para Funções
Em C, você precisa especificar o tamanho das colunas (para arrays 2D) ou dimensões subsequentes (para arrays 3D) nos parâmetros da função.

Exemplo 3: Função para Somar uma Matriz
*/
#include <stdio.h>

// O tamanho das colunas deve ser especificado!
int somaMatriz(int matriz[][3], int linhas)
{
    int soma = 0;
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            soma += matriz[i][j];
        }
    }
    return soma;
}

int main()
{
    int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("Soma da matriz: %d\n", somaMatriz(matriz, 2)); // Saída: 21
    return 0;
}

/*
5. Alocação Dinâmica de Arrays Multidimensionais
Use ponteiros para criar arrays multidimensionais com tamanho definido em tempo de execução.

Exemplo 4: Matriz Dinâmica (Ponteiro para Ponteiro)
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
            matriz[i][j] = i * colunas + j + 1;
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
    // Saída:
    // 1 2 3
    // 4 5 6

    // Libera a memória
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

/*
6. Aplicações Práticas
Exemplo 5: Multiplicação de Matrizes
*/
#include <stdio.h>

void multiplicarMatrizes(int a[][2], int b[][2], int resultado[][2], int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            resultado[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                resultado[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int resultado[2][2];

    multiplicarMatrizes(a, b, resultado, 2);

    // Imprime o resultado
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }
    // Saída:
    // 19 22
    // 43 50

    return 0;
}
/*
Cuidados Importantes
Índices fora dos limites: Acesso a posições
inválidas causa comportamento indefinido.
Alocação/desalocação de memória: Sempre libere
memória alocada dinamicamente para evitar vazamentos.
Tamanho fixo em funções: Para arrays 2D, o
tamanho das colunas deve ser conhecido em tempo de
compilação (a menos que use alocação dinâmica).
*/