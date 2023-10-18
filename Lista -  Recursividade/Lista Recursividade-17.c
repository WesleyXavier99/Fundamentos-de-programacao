#include<stdio.h>

void main()
{
	int n,aux,resultado;
	
	printf("Digite um numero :");
	scanf("%d",&n);
	
	aux=n;
	resultado=Fatorial_Quadruplo(n,aux*2);
	
	printf("Resultado : %d",resultado);
} 

int Fatorial_Quadruplo(int n,int aux)
{
	int soma;
	
	if(aux==n)
	{
		soma=1;
	}else{
		soma= aux * Fatorial_Quadruplo(n,aux-1);
	}
	
	return soma;
}

