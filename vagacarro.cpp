#include <stdio.h>
#define V 4
int main()
{
	int i, vagas[V];
	float media, total, pag, vagaspag=0;
	
	total=0.0;
	for(i=0;i<V;i++){
		printf("Vaga %d: ",i+1);
		scanf("%f",&pag);
		vagas[i]=pag;
		if(pag>0){
			vagaspag+=1;
			total+=pag;
		}
	}

	media=(float)total/vagaspag;
	printf("media: %.2f\n",media);
	for(i=0;i<V;i++){
			printf("\nVaga %d: %d",i+1,vagas[i]);
		if(vagas[i]<media*0.80){
			printf("* reajustar");
		}
	}
	
	
}
