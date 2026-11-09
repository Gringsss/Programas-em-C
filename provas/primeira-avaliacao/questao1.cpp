// Normalizar uma matriz com a fórmula vlr_normalizado = (vlr_atu - vlr_min) / (vlr_max - vlr_min). 
// Escrever uma função que receba uma matriz inteira 10x10, exiba a matriz original e depois a normalizada (reais entre 0 e 1).

#include <stdio.h>

void normalizada(int matriz[10][10]) {
    int i, j;
    int vlr_min = matriz[0][0];   // começa pelo primeiro elemento, não por 0
    int vlr_max = matriz[0][0];
    float vlr_normalizado;

    printf("Matriz original:\n");
    for (i = 0; i < 10; i++) {            // percorre as linhas
        for (j = 0; j < 10; j++) {        // percorre as colunas
            printf("%d\t", matriz[i][j]); // mostra o valor
            if (matriz[i][j] > vlr_max) vlr_max = matriz[i][j]; // atualiza o maior
            if (matriz[i][j] < vlr_min) vlr_min = matriz[i][j]; // atualiza o menor
        }
        printf("\n");                     // quebra a linha ao fim de cada linha da matriz
    }

    printf("Matriz normalizada:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (vlr_max == vlr_min)       // evita divisão por zero
                vlr_normalizado = 0.0;
            else                          // (float) antes da divisão
                vlr_normalizado = (float)(matriz[i][j] - vlr_min) / (vlr_max - vlr_min);
            printf("%.2f\t", vlr_normalizado);
        }
        printf("\n");
    }
}

int main() {
    int i, j, matriz[10][10];
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            scanf("%d", &matriz[i][j]);   // leitura (só para testar)
    normalizada(matriz);                  // chamada sem tipos
    return 0;
}