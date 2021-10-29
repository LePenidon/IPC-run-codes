// importar as bibliotecas
#include <stdio.h>
#include <stdlib.h>

// definicao do tipo DATA, com dia e mes
typedef struct {
    int dia, mes;
} DATA;

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

// funcao que imprime o vetor que armazena as datas
void imprimirVetor(DATA datas[], int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        // verificaco da validez de cada elemento do vetor
        if ((datas[i].dia != 0) && (datas[i].mes != 0)) {
            // imprime o elemento atual
            printf("%d %d\n", datas[i].dia, datas[i].mes);
        }
    }
}

// funcao que verifica a validez das datas
int verificaData(int D, int M) {
    // vetor que auxilia na vericacao dos meses
    int meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // verifica a validez das datas emitidas
    if (M > 12 || M < 1) {
        // retorna 0 caso estiver invalida
        return 0;
    } else {
        if ((D > meses[M - 1]) || (D < 1)) {
            // retorna 0 caso estiver invalida
            return 0;
        } else {
            // retorna 1 caso estiver valida
            return 1;
        }
    }
}

// funcao que ordena o vetor das datas
void ordenaVetor(DATA datas[], int tamanho) {
    int i, j;
    DATA aux;

    // ordena, primeiramente, em relacao aos meses das datas
    for (i = 1; i < tamanho; i++) {
        for (j = 0; j < tamanho - i; j++) {
            if (datas[j].mes > datas[j + 1].mes) {
                aux = datas[j];
                datas[j] = datas[j + 1];
                datas[j + 1] = aux;
            }
        }
    }

    // depois, ordena em relacao aos dias
    for (i = 1; i < tamanho; i++) {
        for (j = 0; j < tamanho - i; j++) {
            // verifica se as datas a serem ordenadas possuem o mesmo mes
            if (datas[j].mes == datas[j + 1].mes) {
                if (datas[j].dia > datas[j + 1].dia) {
                    aux = datas[j];
                    datas[j] = datas[j + 1];
                    datas[j + 1] = aux;
                }
            }
        }
    }
}

// chamar a funcao main
int main(void) {
    // declarar as variaveis
    int N, i, D, M, verifica;
    DATA *datas;

    // receber o tamanho da matriz NxN
    scanf("%d", &N);

    // chama a funcao mallocSafe, para alocar dinamicamente a quantidade estabelecida
    datas = mallocSafe(N * sizeof(DATA));

    // atribui 0 a todos os elementos do vetor
    for (i = 0; i < N; i++) {
        datas[i].dia = 0;
        datas[i].mes = 0;
    }

    // receber todos os valores do vetor
    for (i = 0; i < N; i++) {
        scanf("%d %d", &D, &M);

        // verifica a validez da data a ser testada
        verifica = verificaData(D, M);

        // caso seja valida, armaneza no vetor "datas"
        if (verifica) {
            datas[i].dia = D;
            datas[i].mes = M;
        }
    }

    // chama a funcao para ordenar o vetor
    ordenaVetor(datas, N);

    // chama a funcao para imprimir o vetor
    imprimirVetor(datas, N);

    // retornar valor 0
    return 0;
}