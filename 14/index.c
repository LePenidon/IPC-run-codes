// importando as bibliotecas
#include <stdio.h>
#include <stdlib.h>

// definicao do tipo "posto", que possui a distancia ate o proximo posto e a gasolina de cada um
typedef struct {
    int distanciaProx;
    int qtdGasolina;
} posto;

// declaracao da funcao recursiva que calcula o gasto de gasolina
int gastoGasolina(posto *vetor, int posicao, int tamanho, int vezes, int gasolina) {
    // verifica se a funcao rodou as vezes corretas
    if (vezes == 0) {
        return 1;
    } else {
        // verifica quando posicao deve voltar ao inicio
        if (posicao == tamanho) {
            // reseta a posicao ao inicio
            posicao = 0;
        }
        // soma a quantidade de gasolina no posto atual
        gasolina += vetor[posicao].qtdGasolina;
        // subtrai os litros de gasolina gastos para chegar ao proximo posto
        gasolina -= vetor[posicao].distanciaProx;

        // verifica se e possivel chegar ate o proximo posto
        if (gasolina < 0) {
            // retorna 0 caso nao seja possivel
            return 0;
        }

        // por recursao, chama a funcao gastoGasolina(), mas com algumas mudancas:
        //  - e adicinado 1 ao valor da posicao, para ir ao proximo posto
        //  - e subtraido 1 das vezes a serem rodadas a funcao
        return gastoGasolina(vetor, ++posicao, tamanho, --vezes, gasolina);
    }
}

// declaracao da funcao que imprime o percurso
void printaPercurso(posto *vetor, int tamanho, int posicao) {
    // declaracao das variaveis
    int count = 0;
    int gasolinaAtual = 0;

    // roda a quantidade de vezes de postos existentes
    do {
        // reseta a posicao da posicao, ao inicio
        if (posicao == tamanho) {
            posicao = 0;
        }

        // soma a quantidade de gasolina no posto atual
        gasolinaAtual += vetor[posicao].qtdGasolina;
        // imprime o valor da gasolina
        printf("%d ", gasolinaAtual);

        // subtrai os litros de gasolina gastos para chegar ao proximo posto
        gasolinaAtual -= vetor[posicao].distanciaProx;

        // adiciona 1 na posicao do posto
        posicao++;

        // adiciona um no contador
        count++;
    } while (count < tamanho);

    // quebra uma linha
    printf("\n");

    return;
}

// declaracao da funcao que verifica o percurso
void verificaInicio(posto *vetor, int tamanho) {
    // declaracao das variaveis
    int i;
    int gasolinaAtual = 0;

    // roda a quantidade de postos existentes
    for (i = 0; i < tamanho; i++) {
        // verifica se a posicao atual do posto e uma solucao para o problema
        if (gastoGasolina(vetor, i, tamanho, tamanho, gasolinaAtual)) {
            // imprime a posicao do posto com uma solucao
            printf("%d\n", i + 1);
            // chama a funcao que imprime o percurso
            printaPercurso(vetor, tamanho, i);

            // sai da funcao
            return;
        }
    }

    // sai da funcao
    return;
}

// declaracao da funcao que aloca os espacos desejados, com seguranca
void *mallocSafe(int nBytes) {
    // declaracao do ponteiro a ser retornado
    void *ptr;

    // aloca os espacos
    ptr = malloc(nBytes);

    // caso o ponteiro tenha valor "NULL", a alocacao deu errado e o programa de encerra
    if (ptr == NULL) {
        printf("Socorro! malloc retornou null!\n");
        exit(EXIT_FAILURE);
    }

    // retorna o ponteiro
    return ptr;
}

// declaracao da funcao principal
int main(void) {
    // declaracao das variaveis
    int totalPostos, i;
    posto *postos;

    // recebe o total de postos
    scanf("%d", &totalPostos);

    // alococa dinamicamente o vetor de postos
    postos = mallocSafe(totalPostos * sizeof(posto));

    // recebe as distancias entre os postos
    for (i = 0; i < totalPostos; i++) {
        scanf("%d", &postos[i].distanciaProx);
    }

    // recebe a quantidade de gasolina de cada posto
    for (i = 0; i < totalPostos; i++) {
        scanf("%d", &postos[i].qtdGasolina);
    }

    // chama a funcao que resolve o problema
    verificaInicio(postos, totalPostos);

    // retorna 0
    return EXIT_SUCCESS;
}