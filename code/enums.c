/*
Enums (enumerações) em C são tipos de dados que permitem definir um conjunto de constantes
nomeadas, tornando o código mais legível e organizado.
Elas são úteis para representar opções fixas, como dias da semana,
estados, categorias, etc. Vamos explorar desde a sintaxe básica até exemplos práticos:
*/
/*
1. Sintaxe Básica
Declaração de um enum:
*/
#include <stdio.h>

enum NomeEnum
{
    CONSTANTE1,
    CONSTANTE2,
    // ...
};
// Por padrão, as constantes são atribuídas a valores inteiros sequenciais começando em 0.

// 2. Exemplo 1: Dias da Semana
#include <stdio.h>

// Declaração do enum
enum DiasSemana
{
    DOMINGO, // 0
    SEGUNDA, // 1
    TERCA,   // 2
    QUARTA,  // 3
    QUINTA,  // 4
    SEXTA,   // 5
    SABADO   // 6
};

int main()
{
    enum DiasSemana hoje = QUARTA;

    if (hoje == QUARTA)
    {
        printf("Hoje é quarta-feira!\n"); // Saída: Hoje é quarta-feira!
    }

    // Imprime o valor numérico da constante
    printf("Valor numérico de QUARTA: %d\n", hoje); // 3

    return 0;
}

/*
3. Atribuindo Valores Personalizados
Você pode definir explicitamente os valores das constantes:
*/
enum Status
{
    SUCESSO = 200,
    ERRO_CLIENTE = 400,
    ERRO_SERVIDOR = 500
};

int main()
{
    printf("Código de sucesso: %d\n", SUCESSO); // 200
    return 0;
}
/*
4. Enums em Estruturas de Controle
Exemplo 2: Switch-Case com Enum
*/
#include <stdio.h>

enum EstadoProcesso
{
    INICIADO,
    EM_EXECUCAO,
    CONCLUIDO,
    CANCELADO
};

void verificarEstado(enum EstadoProcesso estado)
{
    switch (estado)
    {
    case INICIADO:
        printf("Processo iniciado.\n");
        break;
    case EM_EXECUCAO:
        printf("Processo em execução.\n");
        break;
    case CONCLUIDO:
        printf("Processo concluído!\n");
        break;
    default:
        printf("Estado inválido.\n");
    }
}

int main()
{
    verificarEstado(EM_EXECUCAO); // Saída: Processo em execução.
    return 0;
}

/*
5. Usando typedef para Simplificar
O typedef permite criar um alias para o enum, evitando repetir a palavra-chave enum:
*/
#include <stdio.h>

typedef enum
{
    VERMELHO,
    VERDE,
    AZUL
} Cor;

int main()
{
    Cor cor_fundo = VERDE;
    printf("Cor selecionada: %d\n", cor_fundo); // 1
    return 0;
}

// 6. Exemplo Prático: Menu de Opções
#include <stdio.h>

typedef enum
{
    SAIR,
    CRIAR,
    EDITAR,
    EXCLUIR
} OpcaoMenu;

void executarOpcao(OpcaoMenu opcao)
{
    switch (opcao)
    {
    case CRIAR:
        printf("Item criado.\n");
        break;
    case EDITAR:
        printf("Item editado.\n");
        break;
    case EXCLUIR:
        printf("Item excluído.\n");
        break;
    case SAIR:
        printf("Saindo...\n");
        break;
    default:
        printf("Opção inválida.\n");
    }
}

int main()
{
    executarOpcao(CRIAR); // Saída: Item criado.
    return 0;
}

// 7. Enums com Valores Explícitos e Não Sequenciais
enum Direcoes
{
    NORTE = 1,
    LESTE = 2,
    SUL = 3,
    OESTE = 4
};

int main()
{
    printf("Direção LESTE: %d\n", LESTE); // 2
    return 0;
}

// Exemplo Final: Gerenciador de Tarefas
#include <stdio.h>

typedef enum
{
    BAIXA,
    MEDIA,
    ALTA
} Prioridade;

typedef struct
{
    char descricao[100];
    Prioridade prioridade;
} Tarefa;

void exibirTarefa(Tarefa t)
{
    const char *nivel_prioridade[] = {"Baixa", "Média", "Alta"};
    printf("Tarefa: %s (Prioridade: %s)\n", t.descricao, nivel_prioridade[t.prioridade]);
}

int main()
{
    Tarefa tarefa1 = {"Revisar código", ALTA};
    exibirTarefa(tarefa1); // Saída: Tarefa: Revisar código (Prioridade: Alta)
    return 0;
}