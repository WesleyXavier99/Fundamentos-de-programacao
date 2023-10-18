#include<stdio.h>
//A multiplicac¸ ˜ao de dois n´umeros inteiros pode ser feita atrav´es de somas sucessivas.
//Proponha um algoritmo recursivo Multip Rec(n1,n2) que calcule a multiplicacao de dois
//inteiros.
void main()
{
	int n1,n2,resultado;
	
	printf("Digite um numero : ");
	scanf("%d",&n1);
	
	printf("Digite um numero : ");
	scanf("%d",&n2);
	
	resultado=Mult_Rec(n1,n2);
	
	printf("O resultado e : %d",resultado);
}

int Mult_Rec(int n1,int n2)
{
	int soma;
	
	if(n2==0)
	{
		soma=0;
	}else{
		soma= n1 + Mult_Rec(n1,n2-1);
	}
	return soma;
}
