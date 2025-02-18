// Principais Headers e Funções

// 1. < stdio.h > : Entrada / Saída Padrão
// Funções para ler e escrever
// dados(console, arquivos).

// Exemplo 1 : printf,
// scanf e fopen

#include <stdio.h>

int main()
{
    // Exemplo de printf e scanf
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Você tem %d anos.\n", idade);

    // Exemplo de escrita em arquivo
    FILE *arquivo = fopen("exemplo.txt", "w");
    if (arquivo != NULL)
    {
        fprintf(arquivo, "Idade digitada: %d", idade);
        fclose(arquivo);
    }
    return 0;
}

/*
    2. <stdlib.h>: Funções Gerais
    Alocação de memória, conversões, controle de processos.
    Exemplo 2: malloc, free e atoi
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Alocação dinâmica de memória
    int *vetor = (int *)malloc(5 * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro na alocação!\n");
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        vetor[i] = i * 10;
    }

    // Conversão de string para inteiro
    char str[] = "123";
    int numero = atoi(str);
    printf("Número convertido: %d\n", numero); // Saída: 123

    free(vetor); // Libera a memória alocada
    return 0;
}

/*
    3. <string.h>: Manipulação de Strings
    Copiar, concatenar, comparar strings.

    Exemplo 3: strcpy, strcat, strlen
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char dest[50] = "Olá, ";
    char src[] = "Mundo!";

    strcat(dest, src);                        // Concatena
    printf("String concatenada: %s\n", dest); // Olá, Mundo!

    strcpy(dest, "Copia esta");           // Copia
    printf("String copiada: %s\n", dest); // Copia esta

    printf("Tamanho da string: %zu\n", strlen(dest)); // 10
    return 0;
}

/*
    4. <math.h>: Funções Matemáticas
    Operações matemáticas avançadas.

    Exemplo 4: sqrt, pow
*/
#include <stdio.h>
#include <math.h>

int main()
{
    double num = 25.0;
    double raiz = sqrt(num);
    printf("Raiz quadrada de %.2f: %.2f\n", num, raiz); // 5.00

    double potencia = pow(2, 3);
    printf("2 elevado a 3: %.2f\n", potencia); // 8.00
    return 0;
}

/*
    5. <ctype.h>: Verificação de Caracteres
    Checar se um caractere é letra, dígito, etc.

    Exemplo 5: isalpha, isdigit
*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    char c = 'A';

    if (isalpha(c))
    {
        printf("%c é uma letra.\n", c); // A é uma letra.
    }

    if (isdigit('5'))
    {
        printf("5 é um dígito.\n"); // 5 é um dígito.
    }
    return 0;
}