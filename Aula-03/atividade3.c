#include <stdio.h>

#define TAMANHO 6  

typedef struct {
    int prioridade;
    int numero;
} Senha;

void insertionSort(Senha senhas[], int n) {
    int i, j;
    Senha chave;

    for (i = 1; i < n; i++) {
        chave = senhas[i];
        j = i - 1;

        while (j >= 0 && 
               (senhas[j].prioridade < chave.prioridade || 
               (senhas[j].prioridade == chave.prioridade && senhas[j].numero > chave.numero))) {
            senhas[j + 1] = senhas[j];
            j--;
        }
        senhas[j + 1] = chave;
    }
}

void imprimirLista(Senha senhas[], int n) {
    printf("\nLista ordenada (senhas prioritárias primeiro e números em ordem crescente):\n");
    for (int i = 0; i < n; i++) {
        printf("Prioridade: %d - Número: %d\n", senhas[i].prioridade, senhas[i].numero);
    }
}

int main() {
    Senha senhas[TAMANHO] = {
        {0, 15},
        {1, 10},
        {1, 5},
        {0, 8},
        {1, 20},
        {0, 3}
    };

    insertionSort(senhas, TAMANHO);
    imprimirLista(senhas, TAMANHO);

    return 0;
}
