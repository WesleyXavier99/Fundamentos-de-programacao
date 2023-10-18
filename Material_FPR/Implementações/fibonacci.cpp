//Calcular o n-ésimo termo da sequência de Fibonacci (1,1,2,3,5,8,...)

#include <stdio.h>
#include <stdlib.h>

int fibonacciI (int n);
int fibonacciR (int n);

//main

int main ()
{
	int n, fib;
	
	printf ("Entre com o valor de n: ");
	scanf ("%d", &n);
	
	//chamando a função iterativa
	fib = fibonacciI (n);
	printf ("%dº termo: %d\n\n", n, fib);
	
	system ("pause");
	
	//chamando a função recursiva
	fib = fibonacciR (n);
	printf ("%dº termo: %d\n\n", n, fib);
}

//implementação da função iterativa
int fibonacciI (int n)
{
	int i, a, b, c;
	
	//if ((n==1) || (n==2))
	if (n <= 2)
	{
		return 1;
	}
	else   // se for do terceiro em diante ...
	{
		a = b = 1;
		
		for (i=3;i<=n;i++)
		{
			c = a+b;			
			a = b;
			b = c;
		}
		
		return c;
	}
}

//implementação da função recursiva
int fibonacciR (int n)
{
	//if ((n==1) || (n==2))
    if (n <=2)
     {
          return 1;
     }
     else
     {
          return fibonacciR (n-2) + fibonacciR (n-1);
     }
}

