#include<stdio.h>
#include<stdlib.h>
/*Faca um programa que leia um numero N e:
 Crie dinamicamente e leia um vetor de inteiro de N posicoes;
 Leia um numero inteiro X e conte e mostre os multiplos desse numero que existem
no vetor.*/

void main()
{
	int *vetor,n,num,i,cont=0;
	
	printf("Digite o numero de posições:\n");
	scanf("%d",&n);
	
	printf("Digite um valor: ");
	scanf("%d",&num);
	
	vetor = (int *)malloc(n * sizeof(int));
	
	for(i=0;i<n;i++)
	{
		printf("pos[%d] : ",i);
		scanf("%d",&vetor[i]);
		printf("\n");
		fflush(stdin);
	}
	
	for(i=0;i<n;i++)
	{
		if(vetor[i]%num==0)
		{
			printf("%d ",vetor[i]);
			cont++;
		}
	}
	
	printf("\nmultiplos: %d ",cont);
}
