#include <stdio.h>
#include <string.h>

#define TAMANHO 5  

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

void bubbleSort(Pessoa pessoas[], int n) {
    int i, j;
    Pessoa temp;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (pessoas[j].idade < pessoas[j + 1].idade) {
                temp = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = temp;
            }
        }
    }
}

void imprimirLista(Pessoa pessoas[], int n) {
    printf("\nLista ordenada (do mais velho para o mais novo):\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %d anos\n", pessoas[i].nome, pessoas[i].idade);
    }
}

int main() {
    Pessoa pessoas[TAMANHO] = {
        {"Carlos", 25},
        {"Ana", 30},
        {"Pedro", 20},
        {"Mariana", 35},
        {"João", 28}
    };

    bubbleSort(pessoas, TAMANHO);
    imprimirLista(pessoas, TAMANHO);

    return 0;
}
