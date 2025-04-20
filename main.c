#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidades.h"

int main(){
    FILE *Resposta = fopen("Resultado.txt", "w");

    Estrada *T1 = getEstrada("estrWakanda.txt");
    double D1 = calcularMenorVizinhanca("estrWakanda.txt");
    char *C1 = cidadeMenorVizinhanca("estrWakanda.txt");


    fprintf(Resposta,"Tamanho da estrada: %d\nNumero de cidades: %d\nMenor Vizinhaça: %.2f\nCidade Menor Vizinhaça: %s\n", T1->T, T1->N, D1, C1);
    fclose(Resposta);
    

    
return 0;
}