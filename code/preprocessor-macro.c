/*O pré-processador em C é um programa que processa o código-fonte antes da compilação,
executando diretivas como `#include`, `#define`, `#ifdef`, etc.
Macros são definições criadas com `#define` que permitem substituições de texto,
constantes ou funções simplificadas. Vamos explorar com exemplos práticos:
*/

// 1. Diretivas Básicas do Pré-Processador

// a) `#include`
// Inclui o conteúdo de um arquivo (como cabeçalhos `.h`):

#include <stdio.h> // Inclui a biblioteca padrão de I/O
// #include "meu_header.h"  Inclui um arquivo local

/*
b) `#define` para Constantes
Substitui um identificador por um valor:
*/

#define PI 3.14159
#define TAMANHO_MAX 100

int main()
{
    float area = PI * 2 * 2; // Substituído por 3.14159 * 2 * 2
    return 0;
}

/*
    ## #* *
    2. Macros com Argumentos(Function - like Macros)
     * *Macros podem receber argumentos para substituições mais dinâmicas :
*/
#define SOMA(a, b) (a + b)
#define QUADRADO(x) (x * x)
#define MAX(a, b) ((a) > (b) ? (a) : (b)) // Macro segura com parênteses

int main()
{
    int resultado = SOMA(3, 5); // Substituído por (3 + 5)
    int quad = QUADRADO(4);     // Substituído por (4 * 4)
    int maior = MAX(10, 20);    // Substituído por ((10) > (20) ? (10) : (20))
    return 0;
}

// Cuidado com Macros !Macros não têm verificação de tipo e podem causar efeitos colaterais:

int x = 5;
// int quad_errado = QUADRADO(x++);  x++ * x++ (x é incrementado duas vezes!)

// 3. Macros Multilinha **
// Use `\` para definir macros em várias linhas:
#define LOG(msg)               \
    printf("[LOG] %s\n", msg); \
    printf("Arquivo: %s\n", __FILE__); // __FILE__ é uma macro pré-definida

int main()
{
    LOG("Iniciando o programa");
    return 0;
}

// 4. Compilação Condicional(`#ifdef `, `#ifndef `, `#endif `) * *Útil para código específico de plataforma ou para debug :

#define DEBUG // Comente para desativar

int main()
{
#ifdef DEBUG
    printf("Modo debug ativado!\n");
#endif

#ifndef VERSION
#define VERSION "1.0"
#endif

    printf("Versão: %s\n", VERSION);
    return 0;
}

// 5. Operadores `#` e `##`* *
// `#` (Stringizing): Converte um argumento em string literal.-
// `##` (Token Pasting): Concatena tokens.

// Exemple:
#define STRINGIZE(x) #x
#define CONCAT(a, b) a##b

int main()
{
    printf("%s\n", STRINGIZE(Hello)); // Imprime "Hello"
    int xy = 100;
    printf("%d\n", CONCAT(x, y)); // Imprime o valor de xy (100)
    return 0;
}

/*
6. Macros Pré -
Definidas
O pré -
 processador define macros úteis automaticamente : |
                                                          **Macro ** | **Descrição ** |
| -- -- -- -- -- -- -- -- -| -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --|
| `__LINE__` | Número da linha atual.|
| `__FILE__` | Nome do arquivo atual.|
| `__DATE__` | Data de compilação(ex : "Jul 21 2023").|
| `__TIME__` | Hora de compilação(ex : "10:30:00").|

printf("Compilado em %s às %s\n", __DATE__, __TIME__);
*/