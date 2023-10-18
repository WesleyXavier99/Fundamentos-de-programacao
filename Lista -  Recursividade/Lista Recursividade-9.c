#include<stdio.h>
//Fac¸a uma func¸ ˜ao recursiva que receba um n´umero inteiro positivo par N e imprima todos
//os n´umeros pares de 0 at ´e N em ordem crescente.

void main()
{
	int n;
	
	printf("Digite uma numero par : ");
	scanf("%d",&n);
	
	Imprime_Pares(n);
}

int Imprime_Pares(int n)
{
	
	if(n==0)
	{
		printf("\n%d",n);
	}else{
		Imprime_Pares(n-2);
		printf("\n%d",n);
	}
}
