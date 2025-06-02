#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct Aluno {
    char nome[50];
    char dataNascimento[11];
    float nota;
    struct Aluno *proximo;
} Aluno;

Aluno* tabela[TAM];

void inicializarTabela() {
    for (int i = 0; i < TAM; i++) {
        tabela[i] = NULL;
    }
}

int hash(char nome[]) {
    int soma = 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        soma += nome[i];
    }
    return soma % TAM;
}

void inserirAluno(char nome[], char dataNascimento[], float nota) {
    int pos = hash(nome);
    Aluno *novo = (Aluno *)malloc(sizeof(Aluno));
    strcpy(novo->nome, nome);
    strcpy(novo->dataNascimento, dataNascimento);
    novo->nota = nota;
    novo->proximo = tabela[pos];
    tabela[pos] = novo;
}

void buscarAluno(char nome[]) {
    int pos = hash(nome);
    Aluno *atual = tabela[pos];
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            printf("Aluno encontrado: %s, Data de Nascimento: %s, Nota: %.2f\n", atual->nome, atual->dataNascimento, atual->nota);
            return;
        }
        atual = atual->proximo;
    }
    printf("Aluno %s não encontrado.\n", nome);
}

void imprimirTabela() {
    for (int i = 0; i < TAM; i++) {
        Aluno *atual = tabela[i];
        if (atual != NULL) {
            printf("Posição %d:\n", i);
            while (atual != NULL) {
                printf("  %s - %s - Nota: %.2f\n", atual->nome, atual->dataNascimento, atual->nota);
                atual = atual->proximo;
            }
        }
    }
}

int main() {
    inicializarTabela();
    
    inserirAluno("Ana", "2005-03-15", 8.5);
    inserirAluno("Bruno", "2004-11-22", 7.8);
    inserirAluno("Carlos", "2005-06-01", 9.2);
    inserirAluno("Daniela", "2004-07-09", 6.7);
    inserirAluno("Eduardo", "2005-01-20", 7.5);
    inserirAluno("Fernanda", "2004-12-11", 8.0);
    inserirAluno("Gabriela", "2005-04-25", 9.0);
    inserirAluno("Helena", "2004-08-30", 7.9);
    inserirAluno("Isabela", "2005-02-14", 8.3);
    inserirAluno("João", "2004-05-10", 7.2);
    
    printf("\nTabela Hash de Alunos:\n");
    imprimirTabela();
    
    char nomeBusca[50];
    printf("\nDigite o nome do aluno para buscar: ");
    fgets(nomeBusca, 50, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = 0;
    buscarAluno(nomeBusca);
    
    return 0;
}
