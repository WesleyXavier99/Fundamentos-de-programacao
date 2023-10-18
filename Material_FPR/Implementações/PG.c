/*
Questão 04: Pede-se a implementação de uma função recursiva que exiba os n primeiros termos 
de uma PG (Progressão Geométrica), onde a1 é o seu primeiro termo e q a razão.

Observação: uma PG consiste em uma sequência de valores, iniciadas pelo valor a1. Os demais 
elementos são definidos como o anterior multiplicado pela razão.

Exemplo:
	n  = 5
	a1 = 4;					PG: 4  12  36  108  324
	q  = 3
*/

#include <stdio.h>

void PG (int a1, int q, int n)
{
	if (n > 0)  //há ainda elementos a serem exibidos?
	{
		printf ("%d ", a1);
		PG (a1*q,q,n-1);
	}
}

void main ()
{
	PG (2, 4, 10);
}
