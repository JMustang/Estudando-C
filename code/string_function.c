/*
Em C, a manipulação de strings é feita principalmente com funções da
biblioteca padrão <string.h> e <ctype.h>.
Vamos explorar as funções mais usadas, com exemplos práticos:
*/
/*
1. Principais Funções da Biblioteca <string.h>
a) strlen - Tamanho da String
Retorna o comprimento da string (excluindo o '\0').
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char texto[] = "Programação";
    printf("Tamanho: %zu\n", strlen(texto)); // Saída: 11
    return 0;
}

/*
b) strcpy e strncpy - Copiar Strings
strcpy(destino, origem): Copia a string origem para destino.

strncpy(destino, origem, n): Copia até n caracteres (mais seguro).
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char origem[] = "Copia isso!";
    char destino[20];

    strcpy(destino, origem);          // Copia completa
    printf("Destino: %s\n", destino); // Copia isso!

    strncpy(destino, "Seguro", 5);    // Copia 5 caracteres
    destino[5] = '\0';                // Adiciona manualmente o terminador
    printf("Destino: %s\n", destino); // Segur

    return 0;
}

/*
c) strcat e strncat - Concatenar Strings
strcat(destino, origem): Concatena origem ao final de destino.

strncat(destino, origem, n): Concatena até n caracteres.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[20] = "Olá, ";
    char str2[] = "mundo!";

    strcat(str1, str2);   // Concatenação completa
    printf("%s\n", str1); // Olá, mundo!

    strncat(str1, " Bem-vindo!", 5); // Concatena 5 caracteres
    printf("%s\n", str1);            // Olá, mundo! Bem-

    return 0;
}
/*
d) strcmp e strncmp - Comparar Strings
Compara strings lexicograficamente:

Retorno 0: Strings iguais.

Retorno < 0: Primeira string é menor.

Retorno > 0: Primeira string é maior.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "abc";
    char str2[] = "abd";

    int resultado = strcmp(str1, str2);
    printf("Comparação: %d\n", resultado); // -1 (pois 'c' < 'd')

    resultado = strncmp(str1, str2, 2);            // Compara os 2 primeiros caracteres
    printf("Comparação parcial: %d\n", resultado); // 0 (os dois primeiros são iguais)

    return 0;
}

/*
e) strchr e strrchr - Buscar Caractere
strchr(str, c): Retorna a primeira ocorrência de c em str.

strrchr(str, c): Retorna a última ocorrência de c em str.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char texto[] = "procure@email.com";
    char *pos = strchr(texto, '@');

    if (pos != NULL)
    {
        printf("Domínio: %s\n", pos + 1); // email.com
    }

    return 0;
}

/*
f) strstr - Buscar Substring
Encontra a primeira ocorrência de uma substring.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char texto[] = "Aprenda C, Python e Java";
    char *sub = strstr(texto, "Python");

    if (sub != NULL)
    {
        printf("Encontrado: %s\n", sub); // Python e Java
    }

    return 0;
}

/*
g) strtok - Dividir String em Tokens
Divide uma string em tokens com base em delimitadores.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char texto[] = "Maçã;Banana;Uva";
    char *token = strtok(texto, ";"); // Delimitador ';'

    while (token != NULL)
    {
        printf("Token: %s\n", token);
        token = strtok(NULL, ";"); // Continua a busca
    }
    // Saída:
    // Token: Maçã
    // Token: Banana
    // Token: Uva

    return 0;
}

/*
2. Funções da Biblioteca <ctype.h>
Funções para verificar ou modificar caracteres individuais.

Exemplo: Conversão para Maiúsculas
*/
#include <stdio.h>
#include <ctype.h>

int main()
{
    char palavra[] = "MixEdCaSe";
    for (int i = 0; palavra[i] != '\0'; i++)
    {
        palavra[i] = toupper(palavra[i]);
    }
    printf("%s\n", palavra); // MIXEDCASE
    return 0;
}

/*
3. Cuidados Importantes
Buffer Overflow: Use strncpy ou strncat para evitar estouro de memória.

Strings Não Terminadas: Garanta que strings tenham '\0' no final.

Modificação de Strings Constantes:
*/
#include <stdio.h>
int main()
{
    char *msg = "Texto"; // Armazenada em memória read-only
    msg[0] = 'A';        // Inválido! Use arrays (ex: char msg[] = "Texto";)
}

/*
4. Exemplo Prático Completo
Validar Senha (Letras, Números e Tamanho)
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int validarSenha(const char *senha)
{
    int temLetra = 0, temNumero = 0;

    if (strlen(senha) < 8)
    {
        return 0; // Senha muito curta
    }

    for (int i = 0; senha[i] != '\0'; i++)
    {
        if (isalpha(senha[i]))
            temLetra = 1;
        if (isdigit(senha[i]))
            temNumero = 1;
    }

    return (temLetra && temNumero);
}

int main()
{
    char senha[50];
    printf("Digite uma senha: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0'; // Remove a quebra de linha

    if (validarSenha(senha))
    {
        printf("Senha válida!\n");
    }
    else
    {
        printf("Senha inválida!\n");
    }

    return 0;
}