// Criar int iniciais(char iniciaisStr[], char nomeCompleto[]), que:
// -> Recebe o nome completo (nome, sobrenome, intermediários) separado por espaços;
// -> Identifica as iniciais, que sempre vêm após um ponto ou espaço (a primeira letra também é inicial);
// -> Guarda em iniciaisStr as iniciais sucedidas por um único ponto, com no máximo 10 iniciais;
// -> Retorna a quantidade de caracteres gerados.

#include <ctype.h>   // toupper

int iniciais(char iniciaisStr[], char nomeCompleto[]) {
    int i;           // índice de leitura do nome
    int k = 0;       // índice de escrita em iniciaisStr (separado!)
    int qtd = 0;     // quantas iniciais já foram guardadas

    for (i = 0; nomeCompleto[i] != '\0' && qtd < 10; i++) {
        // é inicial se for a 1ª letra, ou vier depois de espaço ou ponto
        if ((i == 0 || nomeCompleto[i-1] == ' ' || nomeCompleto[i-1] == '.')
            && nomeCompleto[i] != ' ' && nomeCompleto[i] != '.'
            && nomeCompleto[i] != '\n') {
            iniciaisStr[k++] = toupper(nomeCompleto[i]); // guarda a letra
            iniciaisStr[k++] = '.';                      // guarda o ponto
            qtd++;
        }
    }
    iniciaisStr[k] = '\0';   // fecha a string
    return k;                // caracteres gerados (letras + pontos)
}

// Programa que use a função acima, peça o nome completo e escreva a mensagem com as iniciais e quantas são. 
// Exemplo: Digite seu nome: Cesare Mansueto Giulio Lattes e Suas iniciais são 4: C.M.G.L.

#include <stdio.h>

int main() {
    char nome[100];
    char resultado[21];                       // 10 iniciais x 2 caracteres + '\0'
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);         // lê a linha inteira, com espaços
    int total = iniciais(resultado, nome);    // nome diferente do da função
    printf("Suas iniciais são %d: %s\n", total / 2, resultado); // total/2 = nº de iniciais
    return 0;
}