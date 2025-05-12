#include <stdio.h>
#include <stdlib.h>

typedef struct Operacao {
    float numero1;
    float numero2;
    char operador;
    float resultado;
    struct Operacao* prox;
} Operacao;

Operacao* topo = NULL;

float calcular(float a, float b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return b != 0 ? a / b : 0;
    return 0;
}

void empilhar(float n1, float n2, char op) {
    Operacao* nova = (Operacao*)malloc(sizeof(Operacao));
    nova->numero1 = n1;
    nova->numero2 = n2;
    nova->operador = op;
    nova->resultado = calcular(n1, n2, op);
    nova->prox = topo;
    topo = nova;
}

void desempilhar() {
    if (topo == NULL) return;
    Operacao* temp = topo;
    topo = topo->prox;
    free(temp);
}

void mostrar_topo() {
    if (topo == NULL) {
        printf("Nenhuma operação.\n");
        return;
    }
    printf("%.2f %c %.2f = %.2f\n", topo->numero1, topo->operador, topo->numero2, topo->resultado);
}

int main() {
    empilhar(10, 5, '+');
    mostrar_topo();

    empilhar(20, 4, '*');
    mostrar_topo();

    desempilhar();
    mostrar_topo();

    empilhar(15, 3, '/');
    mostrar_topo();

    return 0;
}
