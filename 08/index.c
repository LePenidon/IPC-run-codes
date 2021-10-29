// importar as bibliotecas
#include <stdio.h>
#include <stdlib.h>

// chamar a funcao main
int main(void) {
    // declarar as variaveis
    int produtos[10], i, procurar, naoTem = 1;

    // repeticao para receber os valores
    for (i = 0; i < 10; i++) {
        // receber, 10 vezes, os valores dos produtos
        scanf("%d", &produtos[i]);

        // caso i == 9, ou seja, ultima repeticao, receber o valor a ser procurado
        if (i == 9) {
            scanf("%d", &procurar);
        }
    }

    // repeticao para os 10 valores dados
    for (i = 0; i < 10; i++) {
        // caso o vetor na posicao i seja igual ao valor a ser procurado, entra nessa condicao
        if (produtos[i] == procurar) {
            // a variavel auxiliar naoTem recebe 0, ou seja, tem
            naoTem = 0;

            // imprimir a posicao da qual o valor do vetor e igual ao que esta sendo procurado
            printf("%d ", i + 1);
        }
    }

    // caso naoTem seja 1, imprimir que nao esta entre os proximos 10
    if (naoTem) {
        printf("nao esta entre os proximos 10\n");
    }

    // retornar valor 0;
    return 0;
}