//Função recursiva para o cálculo de x * y, através de sucessivas somas

#include <stdio.h>
#include <stdlib.h>


int multiplicacao (int a, int b);

//main

int main ()
{
	int num1, num2, res;
	
	printf ("Numero 1: ");
	scanf ("%d", &num1);
	
	printf ("Numero 2: ");
	scanf ("%d", &num2);
	
	//chamando a função
	res = multiplicacao (num1, num2);
	printf ("%d * %d = %d\n\n", num1, num2, res);	
}

//implementação da função de multiplicação
int multiplicacao (int a, int b)
{
	if (b == 0)			//caso base
	{
		return 0;
	}
	else				//caso geral
	{
		return a + multiplicacao (a, b-1);
	}
}
