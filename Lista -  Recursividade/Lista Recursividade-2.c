//Faca uma funcao recursiva que calcule e retorne o fatorial de um numero inteiro N.
#include<stdio.h>

void main()
{
	int resultado,numero;
	
	printf("Digite um numero : ");
	scanf("%d",&numero);
	
	resultado=fatorial(numero);
	
	printf("O fatorial e : %d",resultado);
	
}

int fatorial(int n)
{ 
	int fatorial2;
	if(n==0)
	{
		fatorial2=1;
	}else{
		fatorial2= n * fatorial(n-1);
	}
	return fatorial2;
}
