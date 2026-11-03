#include <stdio.h>

int main()
{
	int i;
	char compras[3][50];
	
	for(i=0;i<3;i++)
	{
		printf("item %d da lista: ",i+1);
		scanf("%s",&compras[i]);
	}
	printf("lista\n");
	for(i=0;i<3;i++)
	{
		printf("item %d: %s\n",i+1,compras[i]);
	}
}
