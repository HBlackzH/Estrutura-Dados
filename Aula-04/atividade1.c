#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int quantidade;
    float preco;
} Produto;

void merge(Produto arr[], int l, int m, int r, char *chave) {
    int n1 = m - l + 1, n2 = r - m;
    Produto L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        int condicao = 0;
        if (strcmp(chave, "nome") == 0)
            condicao = strcmp(L[i].nome, R[j].nome) <= 0;
        else if (strcmp(chave, "quantidade") == 0)
            condicao = L[i].quantidade <= R[j].quantidade;
        else if (strcmp(chave, "preco") == 0)
            condicao = L[i].preco <= R[j].preco;
        
        if (condicao)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(Produto arr[], int l, int r, char *chave) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, chave);
        mergeSort(arr, m + 1, r, chave);
        merge(arr, l, m, r, chave);
    }
}

int main() {
    Produto produtos[] = {
        {"Caderno", 10, 15.50},
        {"Caneta", 50, 2.00},
        {"Borracha", 30, 1.50},
        {"Lápis", 40, 1.00}
    };
    int n = sizeof(produtos) / sizeof(produtos[0]);
    char criterio[20];
    printf("Ordenar por (nome, quantidade, preco): ");
    scanf("%s", criterio);
    mergeSort(produtos, 0, n - 1, criterio);
    for (int i = 0; i < n; i++)
        printf("%s - Qtd: %d, Preço: %.2f\n", produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
    return 0;
}
