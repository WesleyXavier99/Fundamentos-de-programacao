#include<stdio.h>

void main()
{
	int n,k,resultado;
	
	printf("Digite uma base : ");
	scanf("%d",&k);
	printf("Digite uma potencia : ");
	scanf("%d",&n);
	
	resultado=potencia(k,n);
	
	printf("O resultado e : %d",resultado);
}

int potencia(int k,int n)
{
	int pot;
	
	if(n==0)
	{
		pot=1;
	}else{
		pot=k * potencia(k,n-1);
	}
	return pot;
}
