#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Carrinho {
    int quantidade_pessoas;
    char cor[20];
    struct Carrinho* prox;
    struct Carrinho* ant;
} Carrinho;

Carrinho* atual = NULL;

Carrinho* criar_carrinho(char cor[]) {
    Carrinho* novo = (Carrinho*)malloc(sizeof(Carrinho));
    novo->quantidade_pessoas = 0;
    strcpy(novo->cor, cor);
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

void inicializar_roda() {
    char cores[10][20] = {
        "Vermelho", "Azul", "Verde", "Amarelo", "Rosa",
        "Laranja", "Roxo", "Cinza", "Branco", "Preto"
    };
    Carrinho* primeiro = criar_carrinho(cores[0]);
    Carrinho* anterior = primeiro;
    for (int i = 1; i < 10; i++) {
        Carrinho* novo = criar_carrinho(cores[i]);
        anterior->prox = novo;
        novo->ant = anterior;
        anterior = novo;
    }
    anterior->prox = primeiro;
    primeiro->ant = anterior;
    atual = primeiro;
}

void girar_horario() {
    if (atual != NULL) atual = atual->prox;
}

void girar_antihorario() {
    if (atual != NULL) atual = atual->ant;
}

void embarcar(int pessoas) {
    if (atual != NULL) atual->quantidade_pessoas += pessoas;
}

void desembarcar() {
    if (atual != NULL) atual->quantidade_pessoas = 0;
}

void mostrar_atual() {
    if (atual != NULL) {
        printf("Carrinho %s com %d pessoas\n", atual->cor, atual->quantidade_pessoas);
    }
}

void liberar_roda() {
    Carrinho* temp = atual;
    Carrinho* inicio = atual;
    if (temp == NULL) return;
    do {
        Carrinho* prox = temp->prox;
        free(temp);
        temp = prox;
    } while (temp != inicio);
}

int main() {
    inicializar_roda();

    mostrar_atual();
    embarcar(3);
    girar_horario();
    mostrar_atual();
    embarcar(2);
    girar_antihorario();
    mostrar_atual();
    desembarcar();
    mostrar_atual();

    liberar_roda();
    return 0;
}
