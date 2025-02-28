/*
File Handling (Manipulação de Arquivos) em C permite ler e escrever dados em arquivos,
persistindo informações além da execução do programa.
Vamos explorar as funções essenciais e exemplos práticos:
*/

/*
Funções Principais
| **Função**           | **Descrição**                                                                 |
|-----------------------|-----------------------------------------------------------------------------|
| `fopen()`             | Abre um arquivo. Retorna um `FILE*` (ponteiro para o arquivo).             |
| `fclose()`            | Fecha um arquivo.                                                          |
| `fprintf()`           | Escreve dados formatados em um arquivo (como `printf`, mas para arquivos). |
| `fscanf()`            | Lê dados formatados de um arquivo (como `scanf`, mas para arquivos).       |
| `fgets()` / `fputs()` | Lê/escreve uma linha de texto.                                              |
| `fread()` / `fwrite()`| Lê/escreve dados binários.                                                  |

---

### **Modos de Abertura de Arquivo**
| **Modo** | **Descrição**                                                                 |
|----------|-----------------------------------------------------------------------------|
| `"r"`    | Abre para leitura (arquivo deve existir).                                   |
| `"w"`    | Abre para escrita (cria um novo arquivo ou sobrescreve o existente).        |
| `"a"`    | Abre para adicionar dados ao final (append).                                |
| `"r+"`   | Abre para leitura e escrita.                                               |
| `"wb"`   | Abre para escrita em modo binário.                                         |

---
*/
/*
Exemplo 1: Escrevendo em um Arquivo de Texto
*/
#include <stdio.h>

int main()
{
    FILE *arquivo = fopen("exemplo.txt", "w"); // Modo escrita

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // Escreve linhas no arquivo
    fprintf(arquivo, "Linha 1\n");
    fprintf(arquivo, "Linha 2\n");

    fclose(arquivo); // Fecha o arquivo
    printf("Dados escritos com sucesso!\n");
    return 0;
}

/*
Exemplo 2: Lendo de um Arquivo de Texto
*/
#include <stdio.h>

int main()
{
    FILE *arquivo = fopen("exemplo.txt", "r"); // Modo leitura

    if (arquivo == NULL)
    {
        printf("Arquivo não encontrado!\n");
        return 1;
    }

    char linha[100];

    // Lê linha por linha até o fim do arquivo
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        printf("%s", linha);
    }

    fclose(arquivo);
    return 0;
}

// Exemplo 3: Adicionando Dados (Append)

#include <stdio.h>

int main()
{
    FILE *arquivo = fopen("exemplo.txt", "a"); // Modo append

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fprintf(arquivo, "Linha 3 (append)\n");

    fclose(arquivo);
    printf("Dados adicionados!\n");
    return 0;
}

// Exemplo 4: Trabalhando com Dados Binários

#include <stdio.h>

struct Pessoa
{
    char nome[50];
    int idade;
};

int main()
{
    // Escreve uma struct em arquivo binário
    FILE *arquivo = fopen("dados.bin", "wb");
    if (arquivo == NULL)
        return 1;

    struct Pessoa p = {"Ana", 30};
    fwrite(&p, sizeof(struct Pessoa), 1, arquivo); // Escreve 1 elemento

    fclose(arquivo);

    // Lê a struct do arquivo binário
    arquivo = fopen("dados.bin", "rb");
    if (arquivo == NULL)
        return 1;

    struct Pessoa p_lida;
    fread(&p_lida, sizeof(struct Pessoa), 1, arquivo);

    printf("Nome: %s, Idade: %d\n", p_lida.nome, p_lida.idade); // Ana, 30

    fclose(arquivo);
    return 0;
}

// Exemplo 5: Verificação de Erros com `feof` e `ferror`

#include <stdio.h>

int main()
{
    FILE *arquivo = fopen("arquivo_inexistente.txt", "r");

    if (arquivo == NULL)
    {
        perror("Erro ao abrir arquivo"); // Mensagem detalhada do erro
        return 1;
    }

    // Verifica se o fim do arquivo foi atingido
    if (feof(arquivo))
    {
        printf("Fim do arquivo.\n");
    }

    // Verifica se ocorreu um erro durante a operação
    if (ferror(arquivo))
    {
        printf("Erro durante a leitura.\n");
    }

    fclose(arquivo);
    return 0;
}

/*
Boas Práticas
1. **Sempre feche arquivos**: Use `fclose()` para garantir que os dados sejam salvos.
2. **Verifique `NULL`**: Após `fopen()`, confira se o ponteiro não é `NULL`.
3. **Modo binário para dados não textuais**: Use `"wb"` ou `"rb"` para arquivos binários.
4. **Limpe buffers**: Use `fflush(arquivo)` se necessário (ex: logs em tempo real).
*/