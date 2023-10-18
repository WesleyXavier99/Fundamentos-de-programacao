#include <stdio.h>
#include <stdlib.h>
/*
Faca um programa que leia do usuario o tamanho de um vetor a ser lido e faca a alocacao
dinamica de memoria. Em seguida, leia do usu´ ario seus valores e imprima o vetor lido.
*/

void main()
{
	int *vetor;
	int elementos,i;

	printf("Digite o numero de elementos para esse vetor\n");
	scanf("%d",&elementos);
	
	vetor = (int *)malloc(elementos*sizeof(int));
	
	for(i=0;i<elementos;i++)
	{
		printf("Digite um valor para a pos[%d]\n",i);
		scanf("%d",&vetor[i]);
	}
	
	for(i=0;i<elementos;i++)
	{
		printf("pos[%d] = %d\n",i,vetor[i]);
	}
	
	free(vetor);
}
