/*
Quest�o 04: Pede-se a implementa��o de uma fun��o recursiva que exiba os n primeiros termos 
de uma PG (Progress�o Geom�trica), onde a1 � o seu primeiro termo e q a raz�o.

Observa��o: uma PG consiste em uma sequ�ncia de valores, iniciadas pelo valor a1. Os demais 
elementos s�o definidos como o anterior multiplicado pela raz�o.

Exemplo:
	n  = 5
	a1 = 4;					PG: 4  12  36  108  324
	q  = 3
*/

#include <stdio.h>

void PG (int a1, int q, int n)
{
	if (n > 0)  //h� ainda elementos a serem exibidos?
	{
		printf ("%d ", a1);
		PG (a1*q,q,n-1);
	}
}

void main ()
{
	PG (2, 4, 10);
}
