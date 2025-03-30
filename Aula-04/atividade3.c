#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float nota;
    int matricula;
} Aluno;

void trocar(Aluno *a, Aluno *b) {
    Aluno temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Aluno arr[], int n, int i, char *chave) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n) {
        int cond = 0;
        if (strcmp(chave, "nome") == 0)
            cond = strcmp(arr[esquerda].nome, arr[maior].nome) > 0;
        else if (strcmp(chave, "nota") == 0)
            cond = arr[esquerda].nota > arr[maior].nota;
        else if (strcmp(chave, "matricula") == 0)
            cond = arr[esquerda].matricula > arr[maior].matricula;
        if (cond)
            maior = esquerda;
    }

    if (direita < n) {
        int cond = 0;
        if (strcmp(chave, "nome") == 0)
            cond = strcmp(arr[direita].nome, arr[maior].nome) > 0;
        else if (strcmp(chave, "nota") == 0)
            cond = arr[direita].nota > arr[maior].nota;
        else if (strcmp(chave, "matricula") == 0)
            cond = arr[direita].matricula > arr[maior].matricula;
        if (cond)
            maior = direita;
    }

    if (maior != i) {
        trocar(&arr[i], &arr[maior]);
        heapify(arr, n, maior, chave);
    }
}

void heapSort(Aluno arr[], int n, char *chave) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, chave);

    for (int i = n - 1; i > 0; i--) {
        trocar(&arr[0], &arr[i]);
        heapify(arr, i, 0, chave);
    }
}

int main() {
    Aluno alunos[] = {
        {"Carlos", 7.5, 1023},
        {"Ana", 8.9, 1012},
        {"Bruno", 6.7, 1034},
        {"Daniel", 9.1, 1005}
    };
    int n = sizeof(alunos) / sizeof(alunos[0]);
    char criterio[20];
    printf("Ordenar por (nome, nota, matricula): ");
    scanf("%s", criterio);
    heapSort(alunos, n, criterio);
    for (int i = 0; i < n; i++)
        printf("%s - Nota: %.2f, Matrícula: %d\n", alunos[i].nome, alunos[i].nota, alunos[i].matricula);
    return 0;
}
