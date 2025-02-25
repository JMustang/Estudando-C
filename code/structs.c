/*
Structs em C são tipos de dados personalizados que permitem
agrupar variáveis de diferentes tipos sob um único nome.
Elas são essenciais para representar entidades complexas (como alunos, livros,
pontos 2D, etc.) de forma organizada.
Vamos explorar desde a declaração até exemplos práticos:
*/
/*
1. Declaração e Uso Básico
Sintaxe:
*/
#include <stdio.h>

struct NomeDaStruct
{
    char membro1;
    int membro2;
    // ...
};

int main()
{
    struct NomeDaStruct variavel;
    variavel.membro1 = 'a';
    variavel.membro2 = 10;
    printf("%c %d\n", variavel.membro1, variavel.membro2);
    return 0;
}

// Exemplo 1: Struct para Representar um Aluno
#include <stdio.h>

// Declaração da struct
struct Aluno1
{
    char nome[50];
    int idade;
    float nota;
};

int main()
{
    // Criação de uma variável do tipo struct Aluno
    struct Aluno1 aluno1;

    // Atribuição de valores aos membros
    strcpy(aluno1.nome, "João Silva");
    aluno1.idade = 20;
    aluno1.nota = 8.5;

    // Acesso aos membros
    printf("Nome: %s\n", aluno1.nome);
    printf("Idade: %d\n", aluno1.idade);
    printf("Nota: %.2f\n", aluno1.nota);

    return 0;
}

/*
2. Inicialização Direta
Você pode inicializar uma struct durante a declaração:
*/
#include <stdio.h>

struct Aluno aluno2 = {"Maria Souza", 22, 9.0};

/*
3. Structs com Ponteiros
Exemplo 2: Ponteiro para Struct
*/
#include <stdio.h>
#include <stdlib.h>

struct Ponto
{
    int x;
    int y;
};

int main()
{
    struct Ponto *pontoPtr; // Ponteiro para struct Ponto

    // Aloca memória dinamicamente
    pontoPtr = (struct Ponto *)malloc(sizeof(struct Ponto));

    pontoPtr->x = 10; // Acesso via operador '->'
    pontoPtr->y = 20;

    printf("Coordenadas: (%d, %d)\n", pontoPtr->x, pontoPtr->y); // (10, 20)

    free(pontoPtr); // Libera a memória
    return 0;
}

/*
4. Structs como Parâmetros de Função
Exemplo 3: Passando Struct para Função
*/
#include <stdio.h>

struct Livro
{
    char titulo[100];
    char autor[50];
    int paginas;
};

// Função que imprime os detalhes de um livro
void imprimirLivro(struct Livro livro)
{
    printf("Título: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Páginas: %d\n", livro.paginas);
}

int main()
{
    struct Livro meuLivro = {"Dom Casmurro", "Machado de Assis", 256};
    imprimirLivro(meuLivro);
    return 0;
}
/*
5. Arrays de Structs
Exemplo 4: Lista de Alunos
*/
#include <stdio.h>

struct Aluno
{
    char nome[50];
    float nota;
};

int main()
{
    struct Aluno turma[3]; // Array de structs

    // Preenche os dados
    for (int i = 0; i < 3; i++)
    {
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(turma[i].nome, 50, stdin);
        turma[i].nome[strcspn(turma[i].nome, "\n")] = '\0'; // Remove a quebra de linha

        printf("Digite a nota: ");
        scanf("%f", &turma[i].nota);
        getchar(); // Limpa o buffer do teclado
    }

    // Imprime os dados
    printf("\nLista de Alunos:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s - Nota: %.2f\n", turma[i].nome, turma[i].nota);
    }

    return 0;
}

/*
6. Structs Aninhadas
Structs podem conter outras structs como membros.

Exemplo 5: Endereço em uma Struct de Pessoa
*/
#include <stdio.h>

struct Endereco
{
    char rua[50];
    int numero;
    char cidade[30];
};

struct Pessoa
{
    char nome[50];
    int idade;
    struct Endereco endereco; // Struct aninhada
};

int main()
{
    struct Pessoa pessoa1 = {
        "Carlos",
        30,
        {"Rua das Flores", 123, "São Paulo"}};

    printf("%s mora em %s, %d - %s\n",
           pessoa1.nome,
           pessoa1.endereco.rua,
           pessoa1.endereco.numero,
           pessoa1.endereco.cidade);

    return 0;
}

/*
7. Typedef para Simplificar Nomes
O typedef permite criar um alias para o tipo struct, simplificando o código.

Exemplo 6: Usando Typedef
*/
#include <stdio.h>

typedef struct
{
    char modelo[50];
    int ano;
    float preco;
} Carro; // Agora usamos "Carro" em vez de "struct Carro"

int main()
{
    Carro carro1 = {"Fusca", 1970, 15000.00};
    printf("%s (%d) - R$ %.2f\n", carro1.modelo, carro1.ano, carro1.preco);
    return 0;
}

/*
8. Aplicação Prática: Sistema de Biblioteca
Exemplo 7: Gerenciar Livros
*/
#include <stdio.h>
#include <string.h>

typedef struct
{
    char titulo[100];
    char autor[50];
    int disponivel; // 1 para disponível, 0 para emprestado
} Livro;

void emprestarLivro(Livro *livro)
{
    if (livro->disponivel == 1)
    {
        livro->disponivel = 0;
        printf("Livro '%s' emprestado!\n", livro->titulo);
    }
    else
    {
        printf("Livro '%s' não está disponível.\n", livro->titulo);
    }
}

int main()
{
    Livro biblioteca[2] = {
        {"1984", "George Orwell", 1},
        {"O Senhor dos Anéis", "J.R.R. Tolkien", 1}};

    emprestarLivro(&biblioteca[0]); // Empresta "1984"
    emprestarLivro(&biblioteca[0]); // Tenta emprestar novamente

    return 0;
}

/**/
/**/