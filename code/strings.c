/*
Strings em C são sequências de caracteres armazenadas em arrays de char,
terminadas pelo caractere nulo '\0'.
Elas são fundamentais para manipulação de
texto e possuem particularidades importantes.
Vamos explorar desde declaração até operações comuns,
com exemplos práticos:
*/
/*
1. Declaração e Inicialização
Formas de Criar uma String:
*/
#include <stdio.h>

int main()
{
    // Forma 1: Inicialização direta (o compilador adiciona '\0' automaticamente)
    char saudacao[] = "Olá, mundo!"; // Tamanho calculado automaticamente

    // Forma 2: Array de char com tamanho fixo
    char nome[20] = "Ana"; // Restante preenchido com '\0'

    // Forma 3: Usando ponteiro (string em memória read-only)
    char *mensagem = "Bem-vindo!"; // Armazenada em uma seção de memória constante

    // Imprimindo strings
    printf("%s\n", saudacao); // Olá, mundo!
    printf("%s\n", nome);     // Ana
    printf("%s\n", mensagem); // Bem-vindo!

    return 0;
}

/*
2. Entrada e Saída de Strings
Lendo do Usuário:
*/
#include <stdio.h>

int main()
{
    char nome[30];

    printf("Digite seu nome: ");
    // Usando fgets (mais seguro que gets, evita buffer overflow)
    fgets(nome, sizeof(nome), stdin); // Lê incluindo o caractere de nova linha (\n)

    printf("Nome digitado: %s", nome); // Exemplo: "Nome digitado: João\n"

    // Observação: scanf pode ser usado, mas é arriscado sem limitar o tamanho:
    scanf("%29s", nome); // Lê até 29 caracteres (evita overflow)

    return 0;
}

/*
3. Funções de Manipulação de Strings (<string.h>)
Exemplo 1: strlen, strcpy, strcat
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[20] = "Hello";
    char str2[] = " World!";

    printf("Tamanho de str1: %zu\n", strlen(str1)); // 5

    strcat(str1, str2); // Concatena: "Hello World!"
    printf("str1 após concatenação: %s\n", str1);

    char copia[20];
    strcpy(copia, str1); // Copia: "Hello World!"
    printf("Cópia: %s\n", copia);

    return 0;
}
// Exemplo 2: strcmp (Comparação)
#include <stdio.h>
#include <string.h>

int main()
{
    char senha[] = "12345";
    char tentativa[20];

    printf("Digite a senha: ");
    fgets(tentativa, sizeof(tentativa), stdin);
    tentativa[strcspn(tentativa, "\n")] = '\0'; // Remove o '\n' do fgets

    if (strcmp(senha, tentativa) == 0)
    {
        printf("Senha correta!\n");
    }
    else
    {
        printf("Senha incorreta!\n");
    }

    return 0;
}

// 4. Percorrendo uma String Caractere por Caractere
#include <stdio.h>

int main()
{
    char texto[] = "C programming";

    int i = 0;
    while (texto[i] != '\0')
    {
        printf("%c ", texto[i]); // Imprime cada caractere
        i++;
    }
    // Saída: C   p r o g r a m m i n g

    return 0;
}
// 5. Conversão de Case (usando <ctype.h>)
#include <stdio.h>
#include <ctype.h>

void paraMaiusculas(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = toupper(str[i]);
        i++;
    }
}

int main()
{
    char palavra[] = "AbCdEf";
    paraMaiusculas(palavra);
    printf("%s\n", palavra); // ABCDEF
    return 0;
}

/*
6. Cuidados Comuns
Buffer Overflow: Sempre aloque espaço suficiente para o '\0'.

char str[5];
strcpy(str, "Hello"); // Inválido! "Hello" tem 5 caracteres + '\0' (6 no total)
*/
/*
Strings Constantes: Não modifique strings declaradas com char*.

char *msg = "Texto"; // Armazenada em memória read-only
msg[0] = 'A'; // Comportamento indefinido (pode causar crash)!
*/

/*
Caractere Nulo: Sempre termine
strings manualmente se construir caractere por caractere.

char str[4] = {'A', 'B', 'C', '\0'}; // Correto
*/

/*
7. Exemplo Prático: Inverter uma String
*/
#include <stdio.h>
#include <string.h>

void inverterString(char *str)
{
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (inicio < fim)
    {
        char temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;
        inicio++;
        fim--;
    }
}

int main()
{
    char palavra[] = "Recursão";
    inverterString(palavra);
    printf("String invertida: %s\n", palavra); // oãsruceR
    return 0;
}