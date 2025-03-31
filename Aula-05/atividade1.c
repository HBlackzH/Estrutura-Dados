#include <stdio.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    char serie[10];
    int matricula;
} Aluno;

void trocar(Aluno *a, Aluno *b) {
    Aluno temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Aluno arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].matricula > arr[j + 1].matricula) {
                trocar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void removerAluno(Aluno arr[], int *n, int matricula) {
    int i, encontrado = 0;
    for (i = 0; i < *n; i++) {
        if (arr[i].matricula == matricula) {
            encontrado = 1;
            break;
        }
    }
    if (encontrado) {
        for (int j = i; j < *n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        (*n)--;
        printf("Aluno removido com sucesso.\n");
    } else {
        printf("Matrícula não encontrada.\n");
    }
}

void imprimirAlunos(Aluno arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s - Idade: %d, Série: %s, Matrícula: %d\n", arr[i].nome, arr[i].idade, arr[i].serie, arr[i].matricula);
    }
}

int main() {
    Aluno alunos[] = {
        {"Carlos", 15, "9º Ano", 1023},
        {"Ana", 14, "8º Ano", 1012},
        {"Bruno", 16, "1º Ano", 1034},
        {"Daniel", 13, "7º Ano", 1005}
    };
    int n = sizeof(alunos) / sizeof(alunos[0]);
    bubbleSort(alunos, n);
    printf("Lista de alunos ordenada por matrícula:\n");
    imprimirAlunos(alunos, n);

    int matricula;
    printf("\nDigite a matrícula do aluno a ser removido: ");
    scanf("%d", &matricula);
    removerAluno(alunos, &n, matricula);

    printf("\nLista de alunos atualizada:\n");
    imprimirAlunos(alunos, n);

    return 0;
}
