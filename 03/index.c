//importar as bibliotecas
#include <stdio.h>
#include <stdlib.h>

//chamar função main
int main(void) {
    //declarar de variáveis
    int m, n, soma;

    // receber os valores m e n
    scanf("%d %d", &n, &m);

    //realizar a soma dos valores
    soma = n + m;

    //imprimir a soma
    printf("%d\n", soma);

    // verificar e imprimir se a soma for par ou impar
    if (soma % 2 == 0) {
        printf("par\n");
    } else {
        printf("impar\n");
    }

    //retornar valor 0;
    return 0;
}