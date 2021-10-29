//importar as bibliotecas
#include <stdio.h>
#include <stdlib.h>

//chamar função main
int main(void) {
    //declarar de variáveis
    int m, n;

    //receber valores
    scanf("%d %d", &n, &m);

    //verificar os casos de n (categoria)
    switch (n) {
        //caso 1: doce
        case 1:
            //verificar os casos de m (produtos disponiveis)
            switch (m) {
                //caso 11: bolo
                case 11:
                    printf("tem\n");
                    break;
                //caso 12: torta
                case 12:
                    printf("tem\n");
                    break;
                //qualquer outro valor de m: nao tem
                default:
                    printf("nao tem\n");
                    break;
            }
            break;

        //caso 2: salgado
        case 2:
            //verificar os casos de m (produtos disponiveis)
            switch (m) {
                //caso 21: pao
                case 21:
                    printf("tem\n");
                    break;
                //caso 22: empada
                case 22:
                    printf("tem\n");
                    break;
                //qualquer outro valor de m: nao tem
                default:
                    printf("nao tem\n");
                    break;
            }
            break;

        //caso 3: bebida
        case 3:
            //verificar os casos de m (produtos disponiveis)
            switch (m) {
                //caso 31: cafe
                case 31:
                    printf("tem\n");
                    break;
                //caso 32: suco
                case 32:
                    printf("tem\n");
                    break;
                //qualquer outro valor de m: nao tem
                default:
                    printf("nao tem\n");
                    break;
            }
            break;

        //qualquer outro valor de n: erro
        default:
            printf("erro\n");
            break;
    }

    //retornar valor 0;
    return 0;
}