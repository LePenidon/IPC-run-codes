// importar as bibliotecas
#include <stdio.h>
#include <stdlib.h>

// funcao main
int main(void) {
    // declarar as variaveis
    char letra1, letra2;
    int diferenca, i;

    // receber o valor das letras
    scanf("%c %c", &letra1, &letra2);

    // verificar se a letra1 e menor, maior ou igual a letra2
    if (letra1 < letra2) {
        // realizar a diferenca positiva entre as letras
        diferenca = letra2 - letra1;

        // uma repeticao de (diferenca + 1) vezes, que imprime, a partir
        // da menor letra, a sequencia ate a maior
        for (i = letra1; i < (letra1 + diferenca + 1); i++) {
            printf("%c", i);
        }
    } else if (letra1 > letra2) {
        // realizar a diferenca positiva entre as letras
        diferenca = letra1 - letra2;

        // uma repeticao de (diferenca + 1) vezes, que imprime, a partir
        // da menor letra, a sequencia ate a maior
        for (i = letra2; i < (letra2 + diferenca + 1); i++) {
            printf("%c", i);
        }
    } else {
        // como as duas letras sao iguais, imprimir qualquer uma
        printf("%c\n", letra1);
    }

    // retornar valor 0;
    return 0;
}