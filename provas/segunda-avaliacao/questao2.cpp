// Pergunta da Questão 2
// Para armazenar dados de produtos disponíveis à venda, utiliza-se um vetor de estruturas com o seguinte formato:
//
// typedef struct {
//     int codigo;        // Código do produto
//     char descr[30];    // Descrição do produto
//     float vlr;         // Valor bruto do produto
// } produto_t;

// Deseja-se implementar uma função que receba a lista de produtos (ponteiro e quantidade) e selecione produtos dentro de um intervalo de valores. 
// A função deve armazenar esses produtos em um novo vetor alocado dinamicamente, retornando um ponteiro para este vetor e indicando a quantidade de produtos encontrados.

// Implemente a função com o seguinte protótipo:

// produto_t* encontrarProdutos(produto_t P[], int qtdeProd, float vlrmin, float vlrmax, int *tam);

// A função deve (1 ponto para cada funcionalidade atendida):
// 1. Alocar dinamicamente um vetor que armazene todos os produtos cujo valor bruto esteja no intervalo [vlr_min, vlr_max] (inclusive).
// 2. Indicar a quantidade de produtos encontrados no local indicado por tam.
// 3. Retornar o ponteiro para o vetor alocado. Caso nenhum elemento seja localizado, retornar NULL.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char descr[30];
    float vlr;
} produto_t;

produto_t* encontrarProdutos(produto_t P[], int qtdeProd, float vlrmin, float vlrmax, int *tam) {
    int i, cont = 0, idx = 0;         // cont: quantos achou; idx: posição no novo vetor

    for (i = 0; i < qtdeProd; i++) {  // 1a passada: só conta
        if (P[i].vlr >= vlrmin && P[i].vlr <= vlrmax)
            cont++;
    }

    *tam = cont;                      // informa a quantidade (vale 0 se não achou)
    if (cont == 0)
        return NULL;

    produto_t *sel = (produto_t*) malloc(cont * sizeof(produto_t));

    for (i = 0; i < qtdeProd; i++) {  // 2a passada: copia os selecionados
        if (P[i].vlr >= vlrmin && P[i].vlr <= vlrmax) {
            sel[idx] = P[i];
            idx++;
        }
    }
    return sel;
}