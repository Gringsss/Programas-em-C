#include <stdio.h>
#define T 4
int main()
{
	int v1[T],v2[T], i, m;
	
	printf("multiplicador: ");
	scanf("%d",&m);
	for(i=0;i<T;i++){
	printf("numero %d: ",i+1);
	scanf("%d",&v1[i]);	
	}
	for(i=0;i<T;i++){
		v2[i]=v1[i]*m;
	}	
		for(i=0;i<T;i++){
		printf("resultado: %d\n",v2[i]);
	}	
	
}
