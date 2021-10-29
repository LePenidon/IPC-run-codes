#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

// declaracao da funcao que verifica o produto escalar dos vetores par a par
int produtoEscalar(int **vetores, int colunas) {
    // declaracao das variaveis
    int i;
    int produtos[3] = {0, 0, 0};

    // percorre os vetores e multiplica a posicao i dos vetores 0 e 1
    for (i = 0; i < colunas; i++) {
        produtos[0] += vetores[0][i] * vetores[1][i];
    }

    // percorre os vetores e multiplica a posicao i dos vetores 0 e 2
    for (i = 0; i < colunas; i++) {
        produtos[1] += vetores[0][i] * vetores[2][i];
    }

    // percorre os vetores e multiplica a posicao i dos vetores 1 e 2
    for (i = 0; i < colunas; i++) {
        produtos[2] += vetores[1][i] * vetores[2][i];
    }

    // verifica se alguma soma dos produtos foi diferente de 0
    // ou seja, nao sao ortogonais
    for (i = 0; i < 3; i++) {
        if (produtos[i] != 0) {
            // retorna 0 caso nao sejam ortogonais par a par
            return 0;
        }
    }

    // retorna 1 caso sejam ortogonais par a par
    return 1;
}

// declaracao da funcao que verifica se todos os vetores sao unitarios
int verificacaoUnitarios(int **vetores, int linhas, int colunas) {
    // declaracao das variaveis
    int i, j, somas[3] = {0, 0, 0}, modulos[3] = {0, 0, 0};

    // percorre a vetores e realiza a multiplicao das coordenadas j do vetor i
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            somas[i] += vetores[i][j] * vetores[i][j];
        }
    }

    // realiza o modulo de cada vetor, separadamente
    for (i = 0; i < linhas; i++) {
        modulos[i] = sqrt(somas[i]);
    }

    // verifica se algum modulo e diferente de 1
    // ou seja, nao unitario
    for (i = 0; i < linhas; i++) {
        if (modulos[i] != 1) {
            // retorna 0 caso algum modulo seja diferente de 1
            return 0;
        }
    }

    // retorna 1 caso todos os modulos sejam 1
    return 1;
}

// declaracao da funcao que libera os espacos de uma vetores alocada
void freeVetoresInt(int **vetores, int linhas) {
    // declaracao da variavel
    int i;

    // percorre a vetores e libera suas linhas
    for (i = 0; i < linhas; i++) {
        free(vetores[i]);
        vetores[i] = NULL;
    }

    // libera a vetores (vetor de vetores)
    free(vetores);
    vetores = NULL;

    return;
}

// declaracao da funcao principal
int main(void) {
    // declaracao das variaveis
    int **vetores;
    int qtdVetores = 3, n, i, j;

    // recebe o tamanho da vetores
    scanf("%d", &n);

    // atribui o tamanho desejado aos vetores, pela funcao mallocSafe()
    vetores = mallocSafe(qtdVetores * sizeof(int *));
    for (i = 0; i < qtdVetores; i++) {
        vetores[i] = mallocSafe(n * sizeof(int));
    }

    // percorre os vetores e recebe valores para cada posicao individual
    for (i = 0; i < qtdVetores; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &vetores[i][j]);
        }
    }

    // verifica se todos os vetores sao ortonormais
    if (verificacaoUnitarios(vetores, qtdVetores, n) && produtoEscalar(vetores, n)) {
        printf("sao ortonormais\n");
    } else {
        printf("nao sao ortonormais\n");
    }

    // chama a funcao para liberar o espaco alocado pelos vetores
    freeVetoresInt(vetores, qtdVetores);

    return 0;
}