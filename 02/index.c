//importar as bibliotecas
#include <stdio.h>
#include <stdlib.h>

//chamar função main
int main(void) {
    //declarar de variáveis
    int A, B, C, X, R;

    //receber valores
    scanf("%d %d %d %d", &A, &B, &C, &X);

    //realizar o cálculo
    R = A * (X * X) + B * X + C;

    //imprimir o resultado do cálculo
    printf("%d\n", R);

    //retornar valor 0;
    return 0;
}