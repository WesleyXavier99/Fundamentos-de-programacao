/*Questão 03: Fazer uma função recursiva que, dado um número inteiro N, exiba o mesmo na
base 2 (binária).*/

#include <stdio.h>

void binario (int n)
{
	if (n > 0)   //caso geral
	{
		binario (n/2);
		printf ("%d", n%2);		
	}
	else
	{
		printf ("0");
	}
}

void main ()
{
	binario (20);
}
