//Fac¸a uma func¸ ˜ao recursiva que receba um n´umero inteiro positivo impar N e retorne
//o fatorial duplo desse n´umero. O fatorial duplo ´e definido como o produto de todos os
//n´umeros naturais ´ýmpares de 1 at ´e algum n´umero natural ´ýmpar N. Assim, o fatorial duplo
//de 5 ´e
//5!! = 1  3  5 = 15
#include<stdio.h>

void main()
{
	int n,resultado;
	
	printf("Digite um numero impar : ");
	scanf("%d",&n);
	
	resultado=Fatorial_Duplo(n);
	
	printf("O resultado e : %d",resultado);
}

int Fatorial_Duplo(int n)
{
	int soma;
	
	if(n==1)
	{
		soma=1;
	}else{
		soma= n * Fatorial_Duplo(n-2);
	}
	return soma;
}
