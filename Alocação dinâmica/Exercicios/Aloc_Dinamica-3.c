#include<stdio.h>
#include<stdlib.h>
/*
Faca um programa que leia do usuario o tamanho de um vetor a ser lido e fac¸a a alocacao
dinamica de memoria. Em seguida, leia do usuario seus valores e mostre quantos dos
numeros sao pares e quantos sao impares.*/

void main()
{
	int *vetor,elementos,i,cont=0;
	
	printf("Digite o numero de elementos para esse vetor:\n");
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
		if((vetor[i]%2) == 0)
		{
			cont++;
		}
	}
	
	printf("O numero de numeros pares e igual a %d\n",cont);
	printf("O numero de numero impares e igual a %d\n",elementos - cont);
	
	
}


