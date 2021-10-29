//importar as bibliotecas
#include <stdio.h>
#include <stdlib.h>

//chamar função main
int main(void) {
    //declarar de variáveis
    int D, triploD;

    //receber valor
    scanf("%d", &D);

    //calcular o triplo
    triploD = D * 3;

    //imprimir o triplo
    printf("%d\n", triploD);

    //retornar valor 0;
    return 0;
}