#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Corredor {
    char nome[100];
    float tempo;
    struct Corredor* esquerda;
    struct Corredor* direita;
} Corredor;

Corredor* criar_corredor(char nome[], float tempo) {
    Corredor* novo = (Corredor*)malloc(sizeof(Corredor));
    strcpy(novo->nome, nome);
    novo->tempo = tempo;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

void inserir(Corredor** raiz, char nome[], float tempo, float corte) {
    if (*raiz == NULL) {
        *raiz = criar_corredor(nome, tempo);
        return;
    }
    if (tempo < corte)
        inserir(&(*raiz)->direita, nome, tempo, corte);
    else
        inserir(&(*raiz)->esquerda, nome, tempo, corte);
}

void imprimir_classificados(Corredor* raiz, float corte) {
    if (raiz == NULL) return;
    imprimir_classificados(raiz->direita, corte);
    if (raiz->tempo < corte)
        printf("%s - %.2f segundos\n", raiz->nome, raiz->tempo);
    imprimir_classificados(raiz->esquerda, corte);
}

int main() {
    Corredor* raiz = NULL;
    float tempo_corte;
    printf("Informe o tempo de corte (em segundos): ");
    scanf("%f", &tempo_corte);

    inserir(&raiz, "João", 12.3, tempo_corte);
    inserir(&raiz, "Maria", 11.5, tempo_corte);
    inserir(&raiz, "Lucas", 14.2, tempo_corte);
    inserir(&raiz, "Ana", 10.9, tempo_corte);
    inserir(&raiz, "Carlos", 15.6, tempo_corte);

    printf("\nCorredores classificados (tempo menor que %.2f):\n", tempo_corte);
    imprimir_classificados(raiz, tempo_corte);

    return 0;
}
