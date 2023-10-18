#include<stdio.h>

void main ()
{
	int n,resultado;
	
	printf("Digite um numero : ");
	scanf("%d",&n);
	
	resultado=HiperFatorial(n);
	printf("O fatorial e : %d",resultado);
}

int HiperFatorial(int n)
{
	int soma=0;
	
	if(n==0)
	{
		soma=1;
	}else{
		soma= potencia(n) * HiperFatorial(n-1);
	}
	
	return soma;
}

int potencia(int n)
{
	int i;
	int pot=n;
	
	for(i=1;i<n;i++)
	{
		pot=pot*n;
	}
	return pot;
}
