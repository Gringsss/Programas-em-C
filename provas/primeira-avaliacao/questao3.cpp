// Dada a struct climaMetter_t (int dia, mes, ano; float temp, moisture, rainfall;), 
// criar void maisChuvosos(climaMetter_t V[], int N, int X). N é o número de elementos válidos e X é quantas datas listar. 
// A função deve ordenar V em ordem decrescente de precipitação e listar as X datas mais chuvosas. 
// Exemplo com 5 registros e maisChuvosos(V, 5, 3):

// As 3 datas mais chuvosas são:
// 1) 20/03/2025 - Precipitação: 18.40 mm
// 2) 10/03/2025 - Precipitação: 12.30 mm
// 3) 30/03/2025 - Precipitação: 8.70 mm

#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
    float temp;      // temperatura em °C
    float moisture;  // umidade
    float rainfall;  // precipitação pluviométrica
} climaMetter_t;

void maisChuvosos(climaMetter_t V[], int N, int X) {
    int i, trocou;
    climaMetter_t temp;               // auxiliar do mesmo tipo da struct

    do {
        trocou = 0;                   // nenhuma troca ainda nesta passada
        for (i = 0; i < N - 1; i++) { // usa N, não um número fixo
            if (V[i].rainfall < V[i+1].rainfall) {  // compara vizinhos; maior chuva vai para a frente
                temp = V[i];          // troca as duas structs inteiras
                V[i] = V[i+1];
                V[i+1] = temp;
                trocou = 1;           // houve troca, precisa repetir
            }
        }
    } while (trocou);                 // repete até uma passada sem trocas

    printf("As %d datas mais chuvosas são:\n", X);
    for (i = 0; i < X && i < N; i++) {  // lista as X primeiras (já ordenadas)
        printf("%d) %02d/%02d/%04d - Precipitação: %.2f mm\n",
               i + 1, V[i].dia, V[i].mes, V[i].ano, V[i].rainfall);
    }
}