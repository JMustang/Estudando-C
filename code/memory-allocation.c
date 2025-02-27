/*
Dynamic Memory Allocation (Alocação Dinâmica de Memória) em C
permite que programas solicitem memória em tempo de execução,
gerenciando recursos de forma flexível.
Isso é essencial quando o tamanho dos dados não é
conhecido em tempo de compilação (ex: listas dinâmicas,
processamento de arquivos grandes).
Vamos explorar as funções principais e exemplos práticos:
*/
/*
Principais Funções
As funções para alocação dinâmica estão na biblioteca <stdlib.h>:
*/
/*
Função	            Descrição

malloc(size)	    Aloca size bytes de memória. Retorna um ponteiro para o início do bloco.
calloc(n, size)	    Aloca n * size bytes, inicializando todos os bits com zero.
realloc(ptr, size)	Redimensiona o bloco de memória apontado por ptr para size bytes.
free(ptr)	        Libera a memória alocada, evitando vazamentos.
*/

/*
1. Alocação com malloc
Exemplo: Array Dinâmico de Inteiros
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
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    // Preenche o array
    for (int i = 0; i < tamanho; i++)
    {
        array[i] = i * 10;
    }

    // Imprime os valores
    printf("Array: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", array[i]);
    }

    // Libera a memória alocada
    free(array);

    return 0;
}

/*
2. Alocação com calloc
Exemplo: Array Inicializado com Zeros
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho = 5;

    // Aloca e inicializa com zeros
    int *array = (int *)calloc(tamanho, sizeof(int));

    if (array == NULL)
    {
        printf("Erro na alocação!\n");
        return 1;
    }

    // Imprime os valores (todos serão 0)
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", array[i]); // 0 0 0 0 0
    }

    free(array);
    return 0;
}

/*
3. Redimensionamento com realloc
Exemplo: Aumentar o Tamanho de um Array
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array = (int *)malloc(2 * sizeof(int));
    array[0] = 10;
    array[1] = 20;

    // Redimensiona para 4 elementos
    int *novo_array = (int *)realloc(array, 4 * sizeof(int));

    if (novo_array == NULL)
    {
        printf("Erro no redimensionamento!\n");
        free(array); // Libera o array original se falhar
        return 1;
    }

    array = novo_array; // Atualiza o ponteiro
    array[2] = 30;
    array[3] = 40;

    // Imprime
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", array[i]); // 10 20 30 40
    }

    free(array);
    return 0;
}

/*
4. Liberação de Memória com free
Sempre libere a memória alocada para evitar vazamentos:
*/
#include <stdlib.h>
#include <stdio.h>

int *ptr = (int *)malloc(5 * sizeof(int));
// ... uso do ptr ...
free(ptr);  // Libera a memória
ptr = NULL; // Boa prática: evita "dangling pointers"

// 5. Exemplo Prático: Lista Dinâmica de Nomes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num_nomes;
    printf("Quantos nomes deseja armazenar? ");
    scanf("%d", &num_nomes);
    getchar(); // Limpa o buffer do teclado

    // Aloca array de ponteiros para strings
    char **nomes = (char **)malloc(num_nomes * sizeof(char *));

    for (int i = 0; i < num_nomes; i++)
    {
        char buffer[100];
        printf("Digite o nome %d: ", i + 1);
        fgets(buffer, 100, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove a quebra de linha

        // Aloca memória para cada nome
        nomes[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(nomes[i], buffer);
    }

    // Imprime os nomes
    printf("\nNomes armazenados:\n");
    for (int i = 0; i < num_nomes; i++)
    {
        printf("%s\n", nomes[i]);
    }

    // Libera a memória de cada nome e do array
    for (int i = 0; i < num_nomes; i++)
    {
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}

/**/
/**/