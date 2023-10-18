//Escreva uma func¸ ˜ao recursiva ImprimeSerie(i,j,k). Esta func¸ ˜ao imprime na tela a s´ erie
//de valores do intervalo [i,j], com incremento k.
#include<stdio.h>

void Imprime_Serie(int i,int j, int k);

void main()
{
	int i,j,k,resultado;
	
	printf("Digite um numero para iniciar o intervalo :");
	scanf("%d",&i);
	
	printf("Digite um numero para ser o fim do intervalo : ");
	scanf("%d",&j);
	
	printf("Digite um incremento ");
	scanf("%d",&k);
	
	Imprime_Serie(i,j,k);
	
}

void Imprime_Serie(int i,int j, int k)
{
	if(i>j)
	{
		//printf("\n %d",i);
	}else{
		printf("\n%d",i);
		Imprime_Serie(i+k,j,k);
	}
}
