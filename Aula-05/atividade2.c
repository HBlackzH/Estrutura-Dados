#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    char nome[50];
    int quantidade;
    struct Produto *proximo;
} Produto;

typedef struct {
    Produto *inicio;
} ListaCompras;

void inicializarLista(ListaCompras *lista) {
    lista->inicio = NULL;
}

void inserirNoFinal(ListaCompras *lista, char nome[], int quantidade) {
    Produto *novo = (Produto *)malloc(sizeof(Produto));
    strcpy(novo->nome, nome);
    novo->quantidade = quantidade;
    novo->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        Produto *atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

void inserirNoInicio(ListaCompras *lista, char nome[], int quantidade) {
    Produto *novo = (Produto *)malloc(sizeof(Produto));
    strcpy(novo->nome, nome);
    novo->quantidade = quantidade;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
}

void imprimirLista(ListaCompras *lista) {
    Produto *atual = lista->inicio;
    while (atual != NULL) {
        printf("%s - Quantidade: %d\n", atual->nome, atual->quantidade);
        atual = atual->proximo;
    }
}

int main() {
    ListaCompras lista;
    inicializarLista(&lista);

    int opcao;
    char nome[50];
    int quantidade;

    do {
        printf("\n1 - Inserir no início\n");
        printf("2 - Inserir no final\n");
        printf("3 - Imprimir lista\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1 || opcao == 2) {
            printf("Nome do produto: ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = 0;
            printf("Quantidade: ");
            scanf("%d", &quantidade);
            getchar();

            if (opcao == 1) {
                inserirNoInicio(&lista, nome, quantidade);
            } else {
                inserirNoFinal(&lista, nome, quantidade);
            }
        } else if (opcao == 3) {
            printf("\nLista de Compras:\n");
            imprimirLista(&lista);
        }
    } while (opcao != 0);

    return 0;
}
