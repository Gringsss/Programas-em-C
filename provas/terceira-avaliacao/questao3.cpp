// Existem muitas maneiras de se comprimir informação. Um determinado arquivo binário possui registros com a seguinte estrutura:

// typedef struct {
//                  int codigoSensor;   // guarda o código do sensor, que é um número entre 0 e 100000
//                  float temperatura; // guarda a última temperatura lida pelo sensor, que é uma temperatura entre -20°C e 100°C
//                  int ehDigital; // 1 se o sensor for do tipo "digital", 0 se for "analógico"
//                  int foiAtualizado; // 1 se o sensor foi atualizado na última leitura, ou 0 caso contrário.
//                  int emAlarme; // 1 se o sensor está em alarme (fora da temperatura de controle)
//                 } sensor_t;

// Os dados relevantes deverão ser enviados por um canal de comunicação muito restrito, e deseja-se comprimir a informação, usando o seguinte formato 
// (bits do mais significativo ao menos significativo):

// 17 bits mais significativos : códigoSensor
// 7 bits: temperatura (em graus, convertidos para valores inteiros sem arredondamento  e ajustados de -20 a 100 para 0 a 120)
// 1 bit: ehDigital
// 1 bit: foiAtualizado
// 1 bit: emAlarme
// 5 bits menos significativos: quantidade de bits ativos no restante da informação (codigoSensor, temperatura, ehDigital, foiAtualizado, emAlarme)

// Crie uma função em linguagem C que receba um dado do tipo sensor_t e retorne um int (de 32 bits) 
// com a informação comprimida. Presuma que os dados recebidos já estão validados.
// Crie um programa que, usando a função anteriormente criada, leia um arquivo chamado 
// "sensors.dat" com n sensores, e gere um arquivo "sensorsCompressed.dz" que contenha os dados comprimidos.

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    int codigoSensor;   // Número entre 0 e 100000 
    float temperatura;  // Temperatura entre -20°C e 100°C
    int ehDigital;      // 1 para digital, 0 para analógico
    int foiAtualizado;  // 1 se foi atualizado, 0 caso contrário
    int emAlarme;       // 1 se em alarme, 0 caso contrário
} sensor_t;

// Função para contar o número de bits ativos em um inteiro
int contarBitsAtivos(uint32_t valor) {
    int count = 0;
    while (valor) {
        if (valor & 1) count++;      // parênteses corretos
        valor >>= 1;
    }
    return count;
}

uint32_t comprimirSensor(sensor_t sensor) {
    uint32_t resultado = 0;

    // bits 15..31: codigoSensor (cast para unsigned evita overflow de int)
    resultado |= ((uint32_t)sensor.codigoSensor) << 15;

    // bits 8..14: temperatura truncada e ajustada para 0..120
    uint32_t temp = (uint32_t)((int)sensor.temperatura + 20);
    resultado |= (temp & 0x7F) << 8;

    // bit 7: ehDigital
    resultado |= ((uint32_t)(sensor.ehDigital & 0x1)) << 7;

    // bit 6: foiAtualizado
    resultado |= ((uint32_t)(sensor.foiAtualizado & 0x1)) << 6;

    // bit 5: emAlarme
    resultado |= ((uint32_t)(sensor.emAlarme & 0x1)) << 5;

    // bits 0..4: quantidade de bits ativos de tudo que já foi montado
    // (máximo 27, cabe em 5 bits)
    resultado |= (uint32_t)contarBitsAtivos(resultado) & 0x1F;

    return resultado;
}

int main(void) {
    FILE *entrada = fopen("sensors.dat", "rb");
    if (entrada == NULL) {
        perror("Erro ao abrir sensors.dat");
        return 1;
    }

    FILE *saida = fopen("sensorsCompressed.dz", "wb");
    if (saida == NULL) {
        perror("Erro ao criar sensorsCompressed.dz");
        fclose(entrada);
        return 2;
    }

    sensor_t sensor;
    // lê um registro por vez até o fim do arquivo
    while (fread(&sensor, sizeof(sensor_t), 1, entrada) == 1) {
        uint32_t comprimido = comprimirSensor(sensor);
        fwrite(&comprimido, sizeof(uint32_t), 1, saida);
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}