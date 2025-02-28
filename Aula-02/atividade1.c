#include <stdio.h>

void calcular(float *resultado, float valor, char operacao) {
    switch (operacao) {
        case '+': *resultado += valor; break;
        case '-': *resultado -= valor; break;
        case '*': *resultado *= valor; break;
        case '/':
            if (valor != 0) *resultado /= valor;
            else printf("Erro: divisão por zero!\n");
            break;
        default: printf("Operação inválida!\n");
    }
}

int main() {
    float resultado = 0.0, valor;
    char operacao;

    while (1) {
        printf("\nEscolha uma operação (+, -, *, /):");
        scanf(" %c", &operacao);
        printf("Digite um valor: ");
        scanf("%f", &valor);
        calcular(&resultado, valor, operacao);
        printf("Resultado: %.2f\n", resultado);
    }
    return 0;
}
