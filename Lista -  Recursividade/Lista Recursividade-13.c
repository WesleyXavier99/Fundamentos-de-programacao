//Escreva uma func¸ ˜ao recursiva SomaSerie(i,j,k). Esta func¸ ˜ao devolve a soma da s´ erie de
//valores do intervalo [i,j], com incremento k.
#include<stdio.h>

void main()
{
	int i,j,k,resultado;
	
	printf("Digite um numero para iniciar o intervalo :");
	scanf("%d",&i);
	
	printf("Digite um numero para ser o fim do intervalo : ");
	scanf("%d",&j);
	
	printf("Digite um incremento ");
	scanf("%d",&k);
	
	resultado=Soma_Serie(i,j,k);
	
	printf("O resultado e : %d", resultado);
}

int Soma_Serie(int i,int j,int k)
{
	int soma=0;
	
	if(i>j)
	{
		printf("\n if 1");
		soma+=0;
	}else{
		soma=i + Soma_Serie(i+k,j,k);;
		printf("\ni : %d", i);
		printf("\nsoma %d", soma);
	}
	return soma;
}
