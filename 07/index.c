// importar as bibliotecas
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// chamar a funcao que calcula a distancia entre dois pontos
double distanciaDoisPontos(double dist1[2], double dist2[2]) {
    // declarar as variaveis
    double distancia;

    // "distancia" recebe a formula da distancia euclidiana entre dois pontos
    distancia = sqrt(((dist1[0] - dist2[0]) * (dist1[0] - dist2[0])) + ((dist1[1] - dist2[1]) * (dist1[1] - dist2[1])));

    // retornar o valor da distancia entre os dois pontos estabelecidos
    return distancia;
}

// chamar funcao main
int main(void) {
    // declarar as variaveis
    // OBS: dist[0] = eixo x; dist[1] = eixo y;
    double distancias[5][2], distTotal = 0, pontoInicial[2], dist2[2], dist1[2];
    int i, j;

    // definir o ponto de partida (origem) == (0,0)
    for (i = 0; i < 2; i++) {
        pontoInicial[i] = 0;
    }

    // receber todas as coordenadas
    // OBS: a matriz "distancias" armazena, em cada linha (i), todas as distancias dadas
    // OBS: distancias[i][0] = distancia numero i, no eixo x
    // OBS: distancias[i][1] = distancia numero i, no eixo y
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%lf", &distancias[i][j]);
        }
    }

    // como sao 6 pontos totais, rodar 5 vezes a funcao da distancia entre pontos
    for (i = 0; i < 5; i++) {
        // analise de casos do i
        switch (i) {
            // caso i==0, e o ponto de partida, ou seja, o vetor pontoInicial
            case 0:
                // o vetor dist2 recebe os valores do proximo ponto
                dist2[0] = distancias[i][0];
                dist2[1] = distancias[i][1];

                // distTotal, somada ao seu valor inicial, recebe a distancia entre os pontos dados
                distTotal += distanciaDoisPontos(pontoInicial, dist2);

                break;

            default:
                // o vetor dist1 recebe os valores do ponto anterior a ser olhado
                dist1[0] = distancias[i - 1][0];
                dist1[1] = distancias[i - 1][1];

                // o vetor dist2 recebe os valores do proximo ponto
                dist2[0] = distancias[i][0];
                dist2[1] = distancias[i][1];

                // distTotal, somada ao seu valor inicial, recebe a distancia entre os pontos dados
                distTotal += distanciaDoisPontos(dist1, dist2);

                break;
        }
    }

    // imprimir o valor da distancia total entre todos os 5 pontos dados
    printf("%.2lf\n", distTotal);

    // retornar valor 0;
    return 0;
}