#include <stdio.h>

struct Produto{
    char nome[50];
    int quantidade;
    float preco;
    char marca[50];
};


int main() {
    struct Produto produtos[4];

    for (int i = 0; i < 4; i++) {
        printf("Digite o nome do produto %d: ", i + 1);
        scanf("%s", produtos[i].nome);
        printf("Qual a quantidade do produto %d: ", i + 1);
        scanf("%d", &produtos[i].quantidade);
        printf("Qual o preço do produto %d: ", i + 1);
        scanf("%f", &produtos[i].preco);
        printf("Digite a marca do produto %d: ", i + 1);
        scanf("%s", produtos[i].marca);
    }

    printf("\nLista dos produtos:\n");
    for (int i = 0; i < 4; i++) {
        printf("Produto %d\n", i + 1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("Preço: %.2f\n", produtos[i].preco);
        printf("Marca: %s\n\n", produtos[i].marca);
    }

    return 0;
}
