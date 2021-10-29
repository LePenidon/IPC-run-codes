// importar as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definicao do tipo DIA, com "dia", "mes" e "ano"
typedef struct {
    int dia;
    int mes;
    int ano;
} DIA;

// definicao do tipo HORA, com "hora" e "min"
typedef struct {
    int hora;
    int min;
} HORA;

// definicao do tipo AGENDA, com "nomes[10]", "data" e "horario"
typedef struct {
    char nomes[10];
    DIA data;
    HORA horario;
} AGENDA;

// definicao da funcao que recebe os comprimissos
void receberValoresAgenda(AGENDA compromissos[7]) {
    int i;

    // percorre 7 vezes o vetor
    for (i = 0; i < 7; i++) {
        // recebe o nome
        scanf("%s", compromissos[i].nomes);
        getchar();

        // recebe a data
        scanf("%d %d %d", &compromissos[i].data.dia, &compromissos[i].data.mes, &compromissos[i].data.ano);
        getchar();

        // recebe o horario
        scanf("%d %d", &compromissos[i].horario.hora, &compromissos[i].horario.min);
        getchar();
    }

    // retorna
    return;
}

// definicao da funcao que analisa e imprime os comprimissos baseado no local
void imprimirValoresLocal(AGENDA compromissos[7], char localProcurado[10]) {
    int i, aux = 1;

    // percorre o vetor 7 vezes
    for (i = 0; i < 7; i++) {
        // verifica se o nome da posicao atual e igual ao nome procurado
        if (strcmp(compromissos[i].nomes, localProcurado) == 0) {
            // verifica se os minutos do compromisso da posicao atual e menor que 10
            if (compromissos[i].horario.min < 10) {
                // imprime as infomacoes do compromisso da posicao atual
                printf("%s\n%d/%d/%d\n%d:0%d\n", compromissos[i].nomes, compromissos[i].data.dia, compromissos[i].data.mes, compromissos[i].data.ano, compromissos[i].horario.hora, compromissos[i].horario.min);
            } else {
                // imprime as infomacoes do compromisso da posicao atual
                printf("%s\n%d/%d/%d\n%d:%d\n", compromissos[i].nomes, compromissos[i].data.dia, compromissos[i].data.mes, compromissos[i].data.ano, compromissos[i].horario.hora, compromissos[i].horario.min);
            }

            // atribui 0 a variavel caso exista pelo menos 1 compromisso igual ao procurado
            aux = 0;
        }
    }

    // verifica se foi achado algum comprimisso igual ao procurado
    if (aux) {
        printf("nao ha compromisso agendado para este dado\n");
    }

    // retorna
    return;
}

// definicao da funcao que analisa e imprime os comprimissos baseado na data
void imprimirValoresData(AGENDA compromissos[7], DIA dataProcurada) {
    int i, aux = 1;

    // percorre o vetor 7 vezes
    for (i = 0; i < 7; i++) {
        // verifica se o dia, mes e ano sao iguais aos procurados
        if ((compromissos[i].data.dia == dataProcurada.dia) && (compromissos[i].data.mes == dataProcurada.mes) && (compromissos[i].data.ano == dataProcurada.ano)) {
            // verifica se os minutos do compromisso da posicao atual e menor que 10
            if (compromissos[i].horario.min < 10) {
                // imprime as infomacoes do compromisso da posicao atual
                printf("%s\n%d/%d/%d\n%d:0%d\n", compromissos[i].nomes, compromissos[i].data.dia, compromissos[i].data.mes, compromissos[i].data.ano, compromissos[i].horario.hora, compromissos[i].horario.min);
            } else {
                // imprime as infomacoes do compromisso da posicao atual
                printf("%s\n%d/%d/%d\n%d:%d\n", compromissos[i].nomes, compromissos[i].data.dia, compromissos[i].data.mes, compromissos[i].data.ano, compromissos[i].horario.hora, compromissos[i].horario.min);
            }

            // atribui 0 a variavel caso exista pelo menos 1 compromisso igual ao procurado
            aux = 0;
        }
    }

    // verifica se foi achado algum comprimisso igual ao procurado
    if (aux) {
        printf("nao ha compromisso agendado para este dado\n");
    }

    // retorna
    return;
}

// chamar a funcao main
int main(void) {
    // declarar as variaveis
    AGENDA compromissos[7];
    int procura;
    char localProcurado[10];
    DIA dataProcurada;

    // chama a funcao para receber os valores
    receberValoresAgenda(compromissos);

    // recebe o tipo de procura
    scanf("%d", &procura);

    // procura por local ou por data
    if (procura == 1) {
        // recebe o local
        scanf("%s", localProcurado);
        getchar();

        // chama a funcao para imprimir (caso existir) os valores
        imprimirValoresLocal(compromissos, localProcurado);
    } else if (procura == 2) {
        // recebe a data
        scanf("%d %d %d", &dataProcurada.dia, &dataProcurada.mes, &dataProcurada.ano);
        getchar();

        // chama a funcao para imprimir (caso existir) os valores
        imprimirValoresData(compromissos, dataProcurada);
    }

    // retornar valor 0;
    return EXIT_SUCCESS;
}