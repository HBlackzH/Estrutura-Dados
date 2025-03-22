#include <stdio.h>
#include <string.h>

#define TAMANHO 5  

typedef struct {
    char simbolo[10];
    int valor;
} Carta;

void selectionSort(Carta cartas[], int n) {
    int i, j, min;
    Carta temp;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (cartas[j].valor < cartas[min].valor) {
                min = j;
            }
        }
        temp = cartas[i];
        cartas[i] = cartas[min];
        cartas[min] = temp;
    }
}

void imprimirLista(Carta cartas[], int n) {
    printf("\nLista ordenada (do menor para o maior valor):\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %d\n", cartas[i].simbolo, cartas[i].valor);
    }
}

int main() {
    Carta cartas[TAMANHO] = {
        {"Espadas", 10},
        {"Copas", 3},
        {"Ouros", 7},
        {"Paus", 1},
        {"Copas", 5}
    };

    selectionSort(cartas, TAMANHO);
    imprimirLista(cartas, TAMANHO);

    return 0;
}
