#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

int buscar(No* raiz, int alvo, char caminho[]) {
    if (raiz == NULL) return 0;
    if (raiz->valor == alvo) {
        strcat(caminho, " -> ");
        char num[20];
        sprintf(num, "%d", raiz->valor);
        strcat(caminho, num);
        return 1;
    }

    strcat(caminho, " -> E");
    if (buscar(raiz->esquerda, alvo, caminho)) return 1;
    caminho[strlen(caminho) - 4] = '\0';

    strcat(caminho, " -> D");
    if (buscar(raiz->direita, alvo, caminho)) return 1;
    caminho[strlen(caminho) - 4] = '\0';

    return 0;
}

void imprimir_arvore(No* raiz, int nivel) {
    if (raiz == NULL) return;
    for (int i = 0; i < nivel; i++) printf("  ");
    printf("%d\n", raiz->valor);
    imprimir_arvore(raiz->esquerda, nivel + 1);
    imprimir_arvore(raiz->direita, nivel + 1);
}

int main() {
    No* raiz = criar_no(1);
    raiz->esquerda = criar_no(2);
    raiz->direita = criar_no(3);
    raiz->esquerda->esquerda = criar_no(4);
    raiz->esquerda->direita = criar_no(5);
    raiz->direita->direita = criar_no(6);
    raiz->direita->direita->esquerda = criar_no(7);

    int numero;
    printf("Digite o número a ser buscado: ");
    scanf("%d", &numero);

    char caminho[200] = "Raiz";
    if (buscar(raiz, numero, caminho)) {
        printf("Caminho até %d: %s\n", numero, caminho);
    } else {
        printf("Número não encontrado. Árvore completa:\n");
        imprimir_arvore(raiz, 0);
    }

    return 0;
}
