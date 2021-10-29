// importar as bibliotecas
#include <stdio.h>
#include <stdlib.h>

// criacao da funcao para alocar dinamicamente espacos na memoria
void *mallocSafe(int nBytes) {
    // criacao do ponteiro
    void *ptr;

    // sao alocados nBytes bytes, dados como parametro
    ptr = malloc(nBytes);

    // verifica se ocorreu algum erro na funcao malloc
    if (ptr == NULL) {
        printf("Socorro! malloc retornou null!");
        exit(EXIT_FAILURE);
    }

    // retorna o ponteiro
    return ptr;
}

// chamar a funcao main
int main(void) {
    // declarar as variaveis
    int **matriz, N, i, j, assimetrica = 0;

    // receber o tamanho da matriz NxN
    scanf("%d", &N);

    // verificar se o N e valido: menor que 10 e maior que 0
    if (N <= 0 || N > 10) {
        // imprimir erro porque o N e invalido
        printf("erro\n");
    } else {
        // chama a funcao mallocSafe, para alocar dinamicamente a quantidade de linhas estabelecidas
        matriz = mallocSafe(N * sizeof(int *));

        // em cada uma das N linhas alocadas, sao alocadas N colunas, pois e uma matriz quadrada
        for (i = 0; i < N; i++) {
            matriz[i] = mallocSafe(N * sizeof(int));
        }

        // receber todos os valores da matriz NxN
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        // verificar se os elementos das matriz normal sao iguais ao da matriz transposta
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                // verifica cada elemento da transposta com a original
                if (matriz[j][i] != matriz[i][j]) {
                    // caso o elemento seja diferente, a variavel assimetrica recebe 1
                    assimetrica = 1;
                }
            }
        }

        // caso a variavel assimentrica seja 1, imprime assimetrica
        // caso a variavel assimentrica nao seja 1, imprime simetrica
        if (assimetrica) {
            printf("assimetrica\n");
        } else {
            printf("simetrica\n");
        }
    }

    // retornar valor 0;
    return 0;
}