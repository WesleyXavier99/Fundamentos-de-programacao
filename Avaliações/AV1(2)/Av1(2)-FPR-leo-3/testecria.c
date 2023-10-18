#include<stdio.h>

void main()
{
	FILE *arq = fopen("arquivoQ3.txt","r");
	int aux[20];
	int tam = 10;
	int i;
	
	for(i=0;i<tam;i++)
	{
		fscanf(arq,"%d",&aux[i]);
	}
	
	for(i=0;i<tam;i++)
	{
		printf("%d",aux[i]);
	}
	
}
