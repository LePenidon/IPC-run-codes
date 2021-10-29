#include <stdio.h>
#include <stdlib.h>

// definicao do tipo "fatoresPrimos", que possui um fator e a quantidade de vezes desse fator
typedef struct {
    int fator;
    int ocorrencias;
} fatoresPrimos;

// declaracao da funcao que imprime um vetor
void printarVetor(fatoresPrimos *vetor, int tamanho) {
    // declaracao da variavel
    int i;

    // percorre o vetor e imprime cada posicao individualmente
    for (i = 0; i < tamanho; i++) {
        printf("%d %d ", vetor[i].fator, vetor[i].ocorrencias);
    }

    printf("\n");

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

// declaracao da funcao que fatora o numero, e retorna o tamanho do vetor alocado
int fatoracao(int numero, fatoresPrimos **vetor) {
    // declaracao das variaveis
    int tamanho = 0, teste = 0, i;
    fatoresPrimos *auxiliar;
    fatoresPrimos *final;

    // alocacao do do vetor auxiliar, com quantidade "numero" de casas
    auxiliar = mallocSafe(numero * sizeof(fatoresPrimos));

    // atribuicao de 0 a todas as casas do vetor auxiliar
    for (i = 0; i < numero; i++) {
        auxiliar[i].fator = 0;
        auxiliar[i].ocorrencias = 0;
    }

    // verifica se o numero e divisivel por 2, e quantas vezes isso acontece
    while (numero % 2 == 0) {
        // caso seja a primeira devisao por 2, atribui ao vetor auxiliar
        // o fator 2
        if (teste == 0) {
            auxiliar[tamanho].fator = 2;
            teste = 1;
            // adiciona mais 1  a quantidade total de fatores utilizados
            tamanho++;
        }

        auxiliar[tamanho - 1].ocorrencias++;
        numero /= 2;
    }

    for (int i = 3; i <= numero; i += 2) {
        teste = 0;

        // verifica se o numero e divisivel por i, e quantas vezes isso acontece
        while (numero % i == 0) {
            // caso seja a primeira devisao por i, atribui ao vetor auxiliar
            // o fator i
            if (teste == 0) {
                auxiliar[tamanho].fator = i;
                teste = 1;
                // adiciona mais 1  a quantidade total de fatores utilizados
                tamanho++;
            }
            auxiliar[tamanho - 1].ocorrencias++;
            numero /= i;
        }
    }

    teste = 0;

    // caso seja o resto desse processo seja > 2
    // atribui ao vetor auxiliar o fator i
    if (numero > 2) {
        auxiliar[tamanho].fator = numero;
        auxiliar[tamanho].ocorrencias++;
        tamanho++;
    }

    // atribui o tamanho "tamanho" ao vetor "final", pela funcao mallocSafe()
    final = mallocSafe(tamanho * sizeof(fatoresPrimos));

    // atribui ao vetor "final", apenas as casas utilizadas do vetor auxiliar
    for (i = 0; i < tamanho; i++) {
        final[i] = auxiliar[i];
    }

    // atribui ao ponteiro de vetor recebido como parametro, o vetor "final"
    *vetor = final;

    // retorna o tamanho do vetor "final"
    return tamanho;
}

// declaracao da funcao que realiza um potencia de numeros inteiros
int intPow(int base, int exp) {
    int pow = 1;

    while (exp) {
        if (exp % 2) {
            pow *= base;
        }

        exp /= 2;
        base *= base;
    }

    // retorna o valor obtido
    return pow;
}

// declaracao da funcao que realiza o MDC, entre dois vetores de fatoresPrimos
int mdc(fatoresPrimos *fatores01, int tamanho01, fatoresPrimos *fatores02, int tamanho02) {
    // declaracao das variaveis
    int i, mdc;
    int n1 = 1, n2 = 1;

    // por meio dos fatores primos obtidos, consegue o numero original
    for (i = 0; i < tamanho01; i++) {
        n1 *= intPow(fatores01[i].fator, fatores01[i].ocorrencias);
    }

    // por meio dos fatores primos obtidos, consegue o numero original
    for (i = 0; i < tamanho02; i++) {
        n2 *= intPow(fatores02[i].fator, fatores02[i].ocorrencias);
    }

    // verifica se os dois numeros sao iguais ou um e maior do que o outro
    if (n1 > n2) {
        // verifica qual o maior numero que divide os dois valores simultaneamente
        for (i = 1; i <= n2; i++) {
            if ((n1 % i == 0) && (n2 % i == 0)) {
                mdc = i;
            }
        }
    } else if (n1 < n2) {
        // verifica qual o maior numero que divide os dois valores simultaneamente
        for (i = 1; i <= n1; i++) {
            if ((n1 % i == 0) && (n2 % i == 0)) {
                mdc = i;
            }
        }
    } else {
        mdc = n1;
    }

    // retorna o valor obtido
    return mdc;
}

// declaracao da funcao que realiza o MMC, entre dois vetores de fatoresPrimos
int mmc(fatoresPrimos *fatores01, int tamanho01, fatoresPrimos *fatores02, int tamanho02) {
    // declaracao das variaveis
    int i, mmc, aux;
    int n1 = 1, n2 = 1;

    // por meio dos fatores primos obtidos, consegue o numero original
    for (i = 0; i < tamanho01; i++) {
        n1 *= intPow(fatores01[i].fator, fatores01[i].ocorrencias);
    }

    // por meio dos fatores primos obtidos, consegue o numero original
    for (i = 0; i < tamanho02; i++) {
        n2 *= intPow(fatores02[i].fator, fatores02[i].ocorrencias);
    }

    // realiza o MDC entre n1 e n2
    for (i = 2; i <= n2; i++) {
        aux = n1 * i;
        if ((aux % n2) == 0) {
            mmc = aux;
            // sai do loop
            i = n2 + 1;
        }
    }

    // retorna o valor obtido
    return mmc;
}

// declaracao da funcao principal
int main(void) {
    // declaracao das variaveis
    int n1, n2, tamanho01, tamanho02;
    fatoresPrimos *fatores01, *fatores02;

    // recebe os dois valores
    scanf("%d %d", &n1, &n2);

    // chama a funcao fatoracao() para cada valor, que atribui um vetor com os fatores primos,
    // e tambem recebe o tamanho desse vetor
    tamanho01 = fatoracao(n1, &fatores01);
    tamanho02 = fatoracao(n2, &fatores02);

    // imprime os fatores primos e as ocorrencias de cada valor
    printarVetor(fatores01, tamanho01);
    printarVetor(fatores02, tamanho02);

    // imprime o mdc dos valores
    printf("%d\n", mdc(fatores01, tamanho01, fatores02, tamanho02));
    // imprime o mmc dos valores
    printf("%d\n", mmc(fatores01, tamanho01, fatores02, tamanho02));

    // retorna 0
    return EXIT_SUCCESS;
}