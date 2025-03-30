#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int potencia;
    char marca[50];
} Carro;

void trocar(Carro *a, Carro *b) {
    Carro temp = *a;
    *a = *b;
    *b = temp;
}

int comparar(Carro a, Carro b, char *chave) {
    if (strcmp(chave, "nome") == 0)
        return strcmp(a.nome, b.nome);
    else if (strcmp(chave, "marca") == 0)
        return strcmp(a.marca, b.marca);
    else if (strcmp(chave, "potencia") == 0)
        return a.potencia - b.potencia;
    return 0;
}

int particionar(Carro arr[], int baixo, int alto, char *chave) {
    Carro pivo = arr[alto];
    int i = baixo - 1;
    for (int j = baixo; j < alto; j++) {
        if (comparar(arr[j], pivo, chave) <= 0) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return i + 1;
}

void quickSort(Carro arr[], int baixo, int alto, char *chave) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto, chave);
        quickSort(arr, baixo, pi - 1, chave);
        quickSort(arr, pi + 1, alto, chave);
    }
}

int main() {
    Carro carros[] = {
        {"Mustang", 450, "Ford"},
        {"Civic", 158, "Honda"},
        {"Corolla", 169, "Toyota"},
        {"Golf", 230, "Volkswagen"}
    };
    int n = sizeof(carros) / sizeof(carros[0]);
    char criterio[20];
    printf("Ordenar por (nome, marca, potencia): ");
    scanf("%s", criterio);
    quickSort(carros, 0, n - 1, criterio);
    for (int i = 0; i < n; i++)
        printf("%s - Potência: %d, Marca: %s\n", carros[i].nome, carros[i].potencia, carros[i].marca);
    return 0;
}
