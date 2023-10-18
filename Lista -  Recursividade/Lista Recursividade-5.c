#include<stdio.h>
//Fac¸a uma func¸ ˜ao recursiva que calcule e retorne o N-´esimo termo da sequˆencia Fibonacci.
//Alguns n´umeros desta sequˆencia s˜ao: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...
void main()
{
	int ant1,ant2,n,resultado;
	
	printf("Digite uma numero : ");
	scanf("%d",&n);
	
	resultado=fibonacci(n,&ant1,&ant2);
	
	printf("O resultado e : %d",resultado);
}

int fibonacci(int n, int *ant1, int *ant2)
{
	int fn;
	
	if(n==1)
	{
		(*ant1)=0;
		(*ant2)=1;
		fn=(*ant1) + (*ant2);
	}else{
		fibonacci(n-1,ant1,ant2);
		fn=(*ant1) + (*ant2);
		(*ant1)=(*ant2);
		(*ant2)=fn;
	}
	return fn;
}
