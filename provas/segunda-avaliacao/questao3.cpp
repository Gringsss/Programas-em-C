// Pergunta da Questão 3

// Deseja-se implementar uma função que retorne exclusivamente os alunos aprovados em uma disciplina, 
// utilizando a seguinte definição de estrutura:

// typedef struct {
//     int codigo;       // Código do aluno
//     char nome[30];    // Nome do aluno
//     float P1;         // Nota da prova 1
//     float P2;         // Nota da prova 2
//     int nroFaltas;    // contabiliza ausências
// } alunos_t;

// A função deve ter o seguinte protótipo:

// int * codigoDosAprovados(alunos_t* aluno, int nroAlunos);

// A função deve realizar as seguintes tarefas:

// 1. Calcular a média aritmética das notas P1 e P2 de cada aluno no vetor fornecido.
// 2. Selecionar os alunos cuja média seja maior ou igual a 7.0.
// 3. Criar dinamicamente um vetor contendo apenas os códigos dos alunos aprovados. O último código do vetor deve ser zero (0).
// 4. Retornar o ponteiro para o vetor com os códigos dos aprovados. Note que mesmo no caso de nenhum aluno ser aprovado, 
//    haverá o retorno do ponteiro de um vetor, cujo primeiro elemento valha zero (0).

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char nome[30];
    float P1;
    float P2;
    int nroFaltas;
} alunos_t;

alunos_t * leArquivoAlunos(int * qtdeAlunos);

int * codigoDosAprovados(alunos_t* aluno, int nroAlunos) {
    int i, j = 0, ap = 0;
    float media;

    for (i = 0; i < nroAlunos; i++) {            // calcula a média e conta quantos aprovados
        media = (aluno[i].P1 + aluno[i].P2) / 2;
        if (media >= 7.0)
            ap++;
    }

    int *codAprovado = (int*) malloc((ap + 1) * sizeof(int));  // aloca espaço para os códigos dos aprovados + 1 para o zero final

    for (i = 0; i < nroAlunos; i++) {            // preenche o vetor de aprovados
        media = (aluno[i].P1 + aluno[i].P2) / 2;
        if (media >= 7.0) {
            codAprovado[j] = aluno[i].codigo;
            j++;
        }
    }
    codAprovado[j] = 0;                          // marca o final do vetor com zero
    return codAprovado;
}

// Dada uma função supostamente já criada e validada, com o protótipo alunos_t * leArquivoAlunos(int * qtdeAlunos) 
// capaz de carregar dados de alunos de um arquivo, retornando o ponteiro para um vetor de estruturas com os dados dos alunos 
// além de armazenar a quantidade de alunos lidos no local apontado pelo parâmetro qtdeAlunos.

// Crie um programa que:

// 1. Utilize a função leArquivoAlunos para carregar os dados dos alunos.
// 2. Utilize a função aprovados criada anteriormente para obter o vetor de código de alunos aprovados.
// 3. Exiba os códigos dos alunos aprovados, separados por vírgula.
// 4. Libere memória que foi alocada dinamicamente.

int main() {
    int qtdeAlunos;
    alunos_t *alunos = leArquivoAlunos(&qtdeAlunos);          // lê os dados do arquivo e retorna o ponteiro para o vetor de alunos
    int *aprovados = codigoDosAprovados(alunos, qtdeAlunos);  // chama a função para obter os códigos dos alunos aprovados

    printf("Codigos dos alunos aprovados: ");
    for (int i = 0; aprovados[i] != 0; i++) {
        if (i > 0)
            printf(", ");                        // separa os códigos por vírgula
        printf("%d", aprovados[i]);              // imprime o código do aluno aprovado
    }
    printf("\n");

    free(aprovados);                             // libera a memória alocada para os códigos dos aprovados
    free(alunos);
    return 0;
}