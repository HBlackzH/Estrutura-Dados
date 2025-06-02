#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    char nome[50];
    int quantidade;
    float valor;
    struct Produto *esquerda;
    struct Produto *direita;
} Produto;

Produto* criarProduto(char nome[], int quantidade, float valor) {
    Produto *novo = (Produto *)malloc(sizeof(Produto));
    strcpy(novo->nome, nome);
    novo->quantidade = quantidade;
    novo->valor = valor;
    novo->esquerda = novo->direita = NULL;
    return novo;
}

Produto* inserirProduto(Produto *raiz, char nome[], int quantidade, float valor) {
    if (raiz == NULL) {
        return criarProduto(nome, quantidade, valor);
    }
    if (strcmp(nome, raiz->nome) < 0) {
        raiz->esquerda = inserirProduto(raiz->esquerda, nome, quantidade, valor);
    } else if (strcmp(nome, raiz->nome) > 0) {
        raiz->direita = inserirProduto(raiz->direita, nome, quantidade, valor);
    }
    return raiz;
}

void buscarProduto(Produto *raiz, char nome[]) {
    if (raiz == NULL) {
        printf("Produto %s não encontrado.\n", nome);
        return;
    }
    if (strcmp(nome, raiz->nome) == 0) {
        printf("Produto encontrado: %s - Quantidade: %d - Valor: R$%.2f\n", raiz->nome, raiz->quantidade, raiz->valor);
    } else if (strcmp(nome, raiz->nome) < 0) {
        buscarProduto(raiz->esquerda, nome);
    } else {
        buscarProduto(raiz->direita, nome);
    }
}

void imprimirProdutos(Produto *raiz) {
    if (raiz != NULL) {
        imprimirProdutos(raiz->esquerda);
        printf("%s - Quantidade: %d - Valor: R$%.2f\n", raiz->nome, raiz->quantidade, raiz->valor);
        imprimirProdutos(raiz->direita);
    }
}

int main() {
    Produto *estoque = NULL;
    estoque = inserirProduto(estoque, "Arroz", 10, 5.99);
    estoque = inserirProduto(estoque, "Feijão", 8, 7.49);
    estoque = inserirProduto(estoque, "Leite", 15, 3.50);
    estoque = inserirProduto(estoque, "Café", 5, 12.99);
    estoque = inserirProduto(estoque, "Açúcar", 20, 4.25);
    
    char nomeBusca[50];
    printf("Digite o nome do produto para buscar: ");
    fgets(nomeBusca, 50, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = 0;
    buscarProduto(estoque, nomeBusca);
    
    printf("\nLista de Produtos no Estoque:\n");
    imprimirProdutos(estoque);
    
    return 0;
}
