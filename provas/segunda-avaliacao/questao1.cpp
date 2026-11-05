// Pergunta da Questão 1
// Durante a construção de um programa, foi necessário criar uma função para analisar um vetor de números reais. 
// A função deve receber os seguintes parâmetros:
// -> Um vetor de números reais contendo os valores a serem analisados;
// -> Um inteiro indicando a quantidade de elementos no vetor;
// -> Dois ponteiros (pmin e pmax), onde devem ser armazenados, respectivamente, o menor e o maior valor do vetor.


#include <stdio.h>
#include <stdlib.h>

void encontraMinMax(float vetor[], int tamanho, float *pmin, float *pmax) {
    int i;
    *pmin = vetor[0];                 // começa assumindo que o primeiro é o menor
    *pmax = vetor[0];                 // e também o maior

    for (i = 0; i < tamanho; i++) {
        if (*pmin > vetor[i])
            *pmin = vetor[i];         // achou um menor
        if (*pmax < vetor[i])
            *pmax = vetor[i];         // achou um maior
    }
}