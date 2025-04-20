#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidades.h"

//implementando as funcoes
Estrada *getEstrada(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    
    Estrada *estrada = malloc(sizeof(Estrada));
    if (estrada == NULL) {
        printf("Erro ao alocar memória para Estrada.\n");
        fclose(arquivo);
        return NULL;
    }

    // Lê primeira linha, comprimento da estrada T.
    fscanf(arquivo, "%d", &estrada->T);

    // Lê segunda linha, quantidade de cidades N.
    fscanf(arquivo, "%d", &estrada->N);

    // Aloca memória para as cidades com base em N
    estrada-> C = malloc(estrada->N * sizeof(Cidade));
    if (estrada-> C == NULL) {
        printf("Erro ao alocar memória para cidades.\n");
        free(estrada);
        fclose(arquivo);
        return NULL;
    }

    // Lê as cidades
    for (int i = 0; i < estrada->N; i++) {
        fscanf(arquivo, "%d %[^\n]", &estrada->C[i].Posicao, estrada->C[i].Nome);
    }

    fclose(arquivo);
    return estrada;
}
//Funcao para ordenar as cidades com base na posicoes
void selectionSort(Cidade *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].Posicao < arr[minIndex].Posicao) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Cidade temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

//Retorna a Menor Vizinhaça
double calcularMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (estrada == NULL || estrada->N < 1) return -1;

    //Ordenar as cidades por posição
    selectionSort(estrada->C, estrada->N);

    // Como temos N cidades, teremos (N - 1) pontos centrais entre elas.
    double *termoCentral = malloc((estrada->N - 1) * sizeof(double)); 
    for (int i = 0; i < estrada->N - 1; i++) {    //Calcula os pontos centrais entre cada par de cidades consecutivas.
        termoCentral[i] = (estrada->C[i].Posicao + estrada->C[i+1].Posicao) / 2.0;
    }

    double menorVizinhanca = 1e9;//inicializa com 10ˆ9 mais compacto
   

    //Calcular a vizinhança de cada cidade.
    for (int i = 0; i < estrada->N; i++) {
        double inicio, fim;

        if (i == 0) { // A primeira cidade começa em 0 e vai até o primeiro ponto central.
            inicio = 0;
            fim = termoCentral[0];
        } else if (i == estrada->N - 1) {// A última cidade começa no último ponto central e vai até o fim da estrada.
            inicio = termoCentral[i - 1];
            fim = estrada->T;
        } else { // As cidades do meio vão do ponto central anterior até o próximo ponto central.
            inicio = termoCentral[i - 1];
            fim = termoCentral[i];
        }

        double vizinhanca = fim - inicio;// Tamanho da vizinhança da cidade atual.

        if (vizinhanca < menorVizinhanca) {// Se for a menor vizinhança encontrada até agora, atualiza.
            menorVizinhanca = vizinhanca;
        }
    }
    free(termoCentral);
    free(estrada->C);
    free(estrada);

    return menorVizinhanca;
}

//printar cidade com menor vizinhança
char *cidadeMenorVizinhanca(const char *nomeArquivo){

    Estrada *estrada = getEstrada(nomeArquivo);
    if (estrada == NULL || estrada->N < 1) return NULL;

    // Ordenar as cidades por posição
    selectionSort(estrada->C, estrada->N);

    // Como temos N cidades, teremos (N - 1) pontos centrais entre elas.
    double *termoCentral = malloc((estrada->N - 1) * sizeof(double)); 

    //Calcula os pontos centrais entre cada par de cidades consecutivas.
    for (int i = 0; i < estrada->N - 1; i++) {
        termoCentral[i] = (estrada->C[i].Posicao + estrada->C[i+1].Posicao) / 2.0;
    }

    double menorVizinhanca = 1e9;//inicializa com 10ˆ9 mais compacto
    int indiceCidadeMenor = -1; //inicializa indice cidade menor vizança

    //Calcular a vizinhança de cada cidade.
    for (int i = 0; i < estrada->N; i++) {
        double inicio, fim;

        if (i == 0) { // A primeira cidade começa em 0 e vai até o primeiro ponto central.
            inicio = 0;
            fim = termoCentral[0];
        } else if (i == estrada->N - 1) {// A última cidade começa no último ponto central e vai até o fim da estrada.
            inicio = termoCentral[i - 1];
            fim = estrada->T;
        } else { // As cidades do meio vão do ponto central anterior até o próximo ponto central.
            inicio = termoCentral[i - 1];
            fim = termoCentral[i];
        }

        double vizinhanca = fim - inicio;// Tamanho da vizinhança da cidade atual.

        if (vizinhanca < menorVizinhanca) {// Se for a menor vizinhança encontrada até agora, atualiza.
            menorVizinhanca = vizinhanca;
            indiceCidadeMenor = i;
        }
    }

     // Proteção: se nenhuma cidade foi considerada válida
     if (indiceCidadeMenor == -1) {
        free(termoCentral);
        free(estrada->C);
        free(estrada);
        return NULL;
    }

    // Copia o nome da cidade antes de liberar a memória
    char *nome = strdup(estrada->C[indiceCidadeMenor].Nome);

    free(termoCentral);
    free(estrada->C);
    free(estrada);

    return nome;
}

    

