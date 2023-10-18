//Escreva uma funcao recursiva que calcule a soma dos primeiros n cubos: S(n) = 1^3 +
//2^3 + ::: + n^3
#include<stdio.h>

void main()
{
	int resultado,numero;
	
	printf("Digite um numero : ");
	scanf("%d",&numero);
	
	resultado=cubos(numero);
	
	printf("A soma dos cubos e : %d",resultado);
}

int cubos(int n)
{
	int somacubos,cubo=n,i;
	
	if(n==1)
	{
		somacubos=1;
	}else{
		
		for(i=1;i<3;i++)
		{
			cubo*=n;
		}
		somacubos=cubo+ cubos(n-1);
	}
	printf("\nsomacubos %d",somacubos);
	return somacubos;
}
