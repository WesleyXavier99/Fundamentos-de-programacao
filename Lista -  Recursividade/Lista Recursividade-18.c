#include<stdio.h>


void main()
{
	int n,resultado;
	
	printf("Digite um numero : ");
	scanf("%d",&n);
	
	resultado=Super_Fatorial(n);
	printf("O fatorial e : %d",resultado);
}

int Super_Fatorial(int n)
{
	int soma=0;
	
	if(n==0)
	{
		soma=1;
	}else{
		soma = fatorial(n) * Super_Fatorial(n-1);	
	}
	return soma;
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

