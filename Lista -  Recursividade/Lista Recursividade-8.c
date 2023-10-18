#include<stdio.h>
//Fac¸a uma func¸ ˜ao recursiva que receba um n´umero inteiro positivo N e imprima todos os
//n´umeros naturais de 0 at ´e N em ordem decrescente.

void main()
{
	int n,resultado;
	
	printf("Digite uma numero : ");
	scanf("%d",&n);
	
	Exibir_Naturais(n);
}

int Exibir_Naturais(int n)
{
	
	if(n==0)
	{
		printf("\n%d",n);
	}else{
		printf("\n%d",n);
		Exibir_Naturais(n-1);
	}
}
