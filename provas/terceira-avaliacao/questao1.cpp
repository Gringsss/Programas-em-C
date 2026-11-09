// Nesta questão, inicialmente, sugiro criar uma função que retorne "verdadeiro" caso uma string específica esteja na posição X 
// relativa do arquivo. Depois, vc pode varrer todas as posições do arquivo, usando esta função.
// Tem baixa eficiência devido a leituras redundantes, mas é uma abordagem simples. 

#define MAX_STRING 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

int encontraString(const char *s, const char *nomeArq) {
    size_t len = strlen(s);
    size_t janela = len + SIZE;            // tamanho da janela de leitura
    char *buff = malloc(janela + 1);       // +1 para o '\0'
    if (buff == NULL) return -1;

    FILE *arq = fopen(nomeArq, "rb");
    if (arq == NULL) {
        printf("\nArquivo de entrada não encontrado..");
        free(buff);
        return -1;
    }

    long blocosLidos = 0;
    size_t lidos;
    // fread com tamanho 1 retorna a quantidade de BYTES lidos,
    // então o último pedaço (menor que a janela) também é analisado
    while ((lidos = fread(buff, 1, janela, arq)) > 0) {
        buff[lidos] = '\0';                // garante string válida para o strstr
        char *ptr = strstr(buff, s);
        if (ptr != NULL) {
            long pos = blocosLidos * SIZE + (ptr - buff);
            fclose(arq);
            free(buff);
            return (int)pos;
        }
        if (lidos < janela) break;         // chegou ao fim do arquivo
        blocosLidos++;
        fseek(arq, -(long)len, SEEK_CUR);  // volta len bytes (sobreposição)
    }

    fclose(arq);
    free(buff);
    return -1;
}

int main()
{
    printf("\nIniciando...");
    printf("\nRetorno %i\n", encontraString("Isso eh um teste", "arq.txt"));
}