// Uma determinada máquina industrial  obedece os seguintes comandos, do protocolo UCPRO (fictício):

// S 000
// M 000,000,000
// D 000

// Onde S é o comando que define velocidade, e os números inteiros que seguem (que podem ser de 000 a 999) definem a velocidade. 
// M é o comando para movimentação em um sistema de coordenada cartesiana, onde 000,000,000 são coordenadas x, y, z de 3 dígitos inteiros cada. 
// Por fim, D é o comando que determina um delay (atraso) de 000 a 999 milésimos de segundo.

// No entanto, um software de CAM gera um código de saída no formato CANXCOD (fictício) de um arquivo texto com um formato diferente:

// speed 0
// move 0,0,0
// delay 0

// Neste formato, os comandos são expressos de maneira diferente, com "speed" no lugar de "S", "move" no lugar de "M" e "delay" no lugar de "D". 
// Os parâmetros também são números inteiros, mas não são sempre de 3 dígitos, podendo ser de 1, 2 ou 3 dígitos.

// Sua missão é criar um programa em linguagem C que atue como um  "pós processador", que leia o arquivo no formato CANXCOD e traduza para o formato UCPRO. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int traduzirParaUCPRO(const char *entrada, const char *saida) {
    FILE *arquivoEntrada, *arquivoSaida;
    char comando[16]; // Buffer para armazenar o comando lido
    int x, y, z;      // Coordenadas para o comando "move"
    int valor;        // Velocidade ou delay

    // Abrir o arquivo de entrada
    arquivoEntrada = fopen(entrada, "r");
    if (arquivoEntrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return -1; // código de erro "arbitrado"
    }

    // Abrir o arquivo de saída
    arquivoSaida = fopen(saida, "w");
    if (arquivoSaida == NULL) {
        perror("Erro ao criar o arquivo de saída");
        fclose(arquivoEntrada);
        return -2; // código de erro "arbitrado"
    }

    // Processar o arquivo linha por linha
    while (fscanf(arquivoEntrada, "%15s", comando) == 1) {   // le linhas de até 20 caracteres 
        if (strcmp(comando, "speed") == 0) { // compara string lida. Se for velocidade...
            fscanf(arquivoEntrada, "%d", &valor); // le o valor da velocidade
            fprintf(arquivoSaida, "S %03d\n", valor); // e escreve o código traduzido no formato UCPRO
        } else if (strcmp(comando, "move") == 0) { // se for um "move"
            fscanf(arquivoEntrada, "%d,%d,%d", &x, &y, &z); // lê as coordenadas
            fprintf(arquivoSaida, "M %03d,%03d,%03d\n", x, y, z); // escreve arquivo de saída.
        } else if (strcmp(comando, "delay") == 0) { // se for um delay
            fscanf(arquivoEntrada, "%d", &valor); // lê arquivo de entrada
            fprintf(arquivoSaida, "D %03d\n", valor); // escreve a saída no formato UCPRO
        }
    }
    // Fechar os arquivos
    fclose(arquivoEntrada);
    fclose(arquivoSaida);
    return 0;   // adicionar: sucesso
}

int main() {
    const char *arquivoEntrada = "codigo_canxcod.txt";
    const char *arquivoSaida = "codigo_ucpro.txt";

    // Chamar a função de tradução
    traduzirParaUCPRO(arquivoEntrada, arquivoSaida);

    return 0;
}