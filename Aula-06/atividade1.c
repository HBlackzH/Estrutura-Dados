#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Musica {
    char nome[100];
    char artista[100];
    struct Musica* prox;
    struct Musica* ant;
} Musica;

Musica* inicio = NULL;
Musica* fim = NULL;
Musica* atual = NULL;

Musica* criar_musica(char nome[], char artista[]) {
    Musica* nova = (Musica*)malloc(sizeof(Musica));
    strcpy(nova->nome, nome);
    strcpy(nova->artista, artista);
    nova->prox = NULL;
    nova->ant = NULL;
    return nova;
}

void inserir_inicio(char nome[], char artista[]) {
    Musica* nova = criar_musica(nome, artista);
    if (inicio == NULL) {
        inicio = fim = atual = nova;
    } else {
        nova->prox = inicio;
        inicio->ant = nova;
        inicio = nova;
    }
}

void inserir_fim(char nome[], char artista[]) {
    Musica* nova = criar_musica(nome, artista);
    if (fim == NULL) {
        inicio = fim = atual = nova;
    } else {
        fim->prox = nova;
        nova->ant = fim;
        fim = nova;
    }
}

void avancar() {
    if (atual != NULL && atual->prox != NULL) {
        atual = atual->prox;
    }
}

void voltar() {
    if (atual != NULL && atual->ant != NULL) {
        atual = atual->ant;
    }
}

void mostrar_atual() {
    if (atual != NULL) {
        printf("Tocando agora: \"%s\" por %s\n", atual->nome, atual->artista);
    }
}

void liberar_playlist() {
    Musica* temp = inicio;
    while (temp != NULL) {
        Musica* prox = temp->prox;
        free(temp);
        temp = prox;
    }
}

int main() {
    inserir_fim("Blinding Lights", "The Weeknd");
    inserir_inicio("Bohemian Rhapsody", "Queen");
    inserir_fim("Shape of You", "Ed Sheeran");

    mostrar_atual();
    avancar();
    mostrar_atual();
    avancar();
    mostrar_atual();
    avancar();
    voltar();
    mostrar_atual();

    liberar_playlist();
    return 0;
}
