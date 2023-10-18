#include <stdio.h>
#include <stdlib.h>
/*
Crie um programa que:
(a) Aloque dinamicamente um array de 5 n´umeros inteiros,
(b) Pec¸a para o usu´ ario digitar os 5 n´umeros no espac¸o alocado,
(c) Mostre na tela os 5 n´umeros,
(d) Libere a mem´ oria alocada.*/

void main()
{
	int *vetor;
	vetor = (int *)malloc(5*sizeof(int));
	int i;
	
	
	
	for(i=0;i<5;i++)
	{
		printf("Digite um valor para a pos[%d]\n",i);
		scanf("%d",&vetor[i]);
	}
	
	for(i=0;i<5;i++)
	{
		printf("pos[%d] = %d\n",i,vetor[i]);
	}
	
	free(vetor);
}
