#include <stdio.h>
#include <string.h>

struct Aluno {
  char nome[50];
  float nota;
};

int main() {
  struct Aluno aluno[] = {
      {"Alice", 10.0}, {"Junior", 9.0}, {"Olaf", 6.0},    {"Flouk", 8.0},
      {"Thor", 4.0},   {"Freia", 9.5},  {"Thorfin", 2.5}, {"Shiva", 4.0},
      {"Loki", 6.0},   {"Odin", 3.0},   {"Freyz", 8.5},   {"Lakhsimi", 9.5},
  };

  // Essa variavel 'tamanho' é a quantidade de elementos do array 'alunos'.
  int tamanho = sizeof(aluno) / sizeof(aluno[0]);
  int media = 6;

  for (int i = 0; i < tamanho; i++) {
    if (aluno[i].nota >= media) {
      printf(" %s: %1f. Aluno aprovado.\n", aluno[i].nome, aluno[i].nota);
    } else {
      printf(" %s: %2f. Aluno reprovado.\n", aluno[i].nome, aluno[i].nota);
    }
  }
  return 0;
}
