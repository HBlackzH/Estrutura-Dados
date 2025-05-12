#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Paciente {
    char nome[100];
    char cpf[20];
    int gravidade;
    struct Paciente* prox;
} Paciente;

Paciente* emergencia = NULL;
Paciente* uti = NULL;
Paciente* triagem = NULL;

Paciente* criar_paciente(char nome[], char cpf[], int gravidade) {
    Paciente* novo = (Paciente*)malloc(sizeof(Paciente));
    strcpy(novo->nome, nome);
    strcpy(novo->cpf, cpf);
    novo->gravidade = gravidade;
    novo->prox = NULL;
    return novo;
}

void enfileirar(Paciente** fila, Paciente* paciente) {
    if (*fila == NULL) {
        *fila = paciente;
    } else {
        Paciente* temp = *fila;
        while (temp->prox != NULL)
            temp = temp->prox;
        temp->prox = paciente;
    }
}

Paciente* desenfileirar(Paciente** fila) {
    if (*fila == NULL) return NULL;
    Paciente* removido = *fila;
    *fila = (*fila)->prox;
    removido->prox = NULL;
    return removido;
}

void encaminhar_emergencia() {
    Paciente* p = desenfileirar(&emergencia);
    if (p == NULL) return;
    if (p->gravidade >= 8)
        enfileirar(&uti, p);
    else
        enfileirar(&triagem, p);
}

void listar_fila(Paciente* fila, const char* nome_fila) {
    printf("\nFila %s:\n", nome_fila);
    while (fila != NULL) {
        printf("Nome: %s | CPF: %s | Gravidade: %d\n", fila->nome, fila->cpf, fila->gravidade);
        fila = fila->prox;
    }
}

int main() {
    enfileirar(&emergencia, criar_paciente("João", "12345678900", 5));
    enfileirar(&emergencia, criar_paciente("Maria", "98765432100", 9));
    enfileirar(&emergencia, criar_paciente("Ana", "11122233344", 7));

    encaminhar_emergencia();
    encaminhar_emergencia();
    encaminhar_emergencia();

    listar_fila(uti, "UTI");
    listar_fila(triagem, "Triagem");
    listar_fila(emergencia, "Emergência");

    return 0;
}
