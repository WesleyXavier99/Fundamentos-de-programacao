/*
   FPR - 2020/1
   Aula de 28/09/2020
   
   Matrizes din�micas
*/

//importa��o de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declarando a matriz sem especificar as suas dimens�es
	float **m;
	int l, c;
	
	//lendo as dimens�es da matriz
	printf ("Entre com a quantidade de linhas e colunas da matriz: ");
	scanf ("%d %d", &l, &c);
	
	//alocando a matriz dinamicamente
	m = (float**) malloc (l*sizeof(float*));
	for (i=0;i<l;i++)
	{
		m[i] = (float*) malloc (c*sizeof(float));
	}	 
}
