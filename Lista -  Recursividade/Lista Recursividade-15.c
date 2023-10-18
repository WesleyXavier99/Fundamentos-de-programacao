//Fac¸a uma func¸ ˜ao recursiva que calcule o valor da s´ erie S descrita a seguir para um valor
//n > 0 a ser fornecido como parˆametro para a mesma.
//S = 2 + 5/2 + 10/3 + ::: + 1 + n2/n
#include<stdio.h>

float Calc_Serie(float n);

void main()
{
	float n,resultado;
	
	printf("Digite um numero :");
	scanf("%f",&n);
	
	resultado=Calc_Serie(n);
	
	printf("O resultado e : %.3f",resultado);
}

float Calc_Serie(float n)
{
	float soma=0;
	
	if(n==1)
	{
		soma=2;
	}else{
		soma=(((n-1)*5)/n) + Calc_Serie(n-1);
	}
	
	return soma;
	
}
