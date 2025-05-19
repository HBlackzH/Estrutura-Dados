#include <stdio.h>
#include <stdlib.h>

typedef struct Operacao {
    float num1;
    float num2;
    char operador;
    struct Operacao* prox;
} Operacao;

Operacao* pilha = NULL;

Operacao* criar_operacao(float n1, float n2, char op) {
    Operacao* nova = (Operacao*)malloc(sizeof(Operacao));
    nova->num1 = n1;
    nova->num2 = n2;
    nova->operador = op;
    nova->prox = NULL;
    return nova;
}

void empilhar(float n1, float n2, char op) {
    Operacao* nova = criar_operacao(n1, n2, op);
    nova->prox = pilha;
    pilha = nova;
}

void desempilhar() {
    if (pilha == NULL) return;
    Operacao* temp = pilha;
    pilha = pilha->prox;
    free(temp);
}

float calcular() {
    Operacao* atual = pilha;
    float resultado = 0;
    while (atual != NULL) {
        float res = 0;
        if (atual->operador == '+') res = atual->num1 + atual->num2;
        else if (atual->operador == '-') res = atual->num1 - atual->num2;
        else if (atual->operador == '*') res = atual->num1 * atual->num2;
        else if (atual->operador == '/') res = atual->num2 != 0 ? atual->num1 / atual->num2 : 0;
        resultado += res;
        atual = atual->prox;
    }
    return resultado;
}

int main() {
    empilhar(10, 2, '+');
    empilhar(8, 3, '*');
    empilhar(9, 3, '/');

    desempilhar(); // remove a última operação (divisão)

    float resultado = calcular();
    printf("Resultado final: %.2f\n", resultado);

    return 0;
}
