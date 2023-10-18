/*
   FPR - 2020/1
   Aula de 28/09/2020
   
   Matrizes dinâmicas
*/

//importação de bibliotecas
#include <stdio.h>

//main
void main ()
{
	float **m;
	int i;
	
	m = (float**) malloc (10*sizeof(float*));
	for (i=0;i<10;i++)
	{
		m[i] = (float*) malloc ((i+1)*sizeof(float));
	}	 
}
