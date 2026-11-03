#include <stdio.h>
#define ETAPAS 4
#define TEMPO 4

int main()
{
	int idx, etapas[ETAPAS], tempo[TEMPO], hr1, min1;
	int hr2, min2, inicio, ponto=0;
	
	for(idx=0;idx<ETAPAS;idx++)
	{
		etapas[idx]=0;
		tempo[idx]=0;
	}
	
	printf("Tempo de inicio do competidor (HH:MM): ");
	scanf("%d:%d",&hr1,&min1);
	inicio=(int)min1+(hr1*60);
	
	for(idx=0;idx<ETAPAS;idx++)
	{
		printf("Tempo limite da %d etapa: ",idx+1);
		scanf("%d",&etapas[idx]);
	}
	
	for(idx=0;idx<ETAPAS;idx++)
	{
		printf("Tempo da %d etapa (HH:MM): ",idx+1);
		scanf("%d:%d",&hr2,&min2);
		tempo[idx]=(int)min2+(hr2*60);
	}

	for(idx=0;idx<ETAPAS;idx++)
	{
		if((inicio+etapas[idx])==tempo[idx])
			ponto++;
	}
	
	printf("\nPontos totais: %d",ponto);
}
