/*
   FPR - 2020/1
   Aula de 28/09/2020
   
   Vetores dinâmicos
*/

//importação de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declarando o vetor v, porém sem alocar memória para as suas posições
	float *v;
	int quant;
	
	printf ("Qual o tamanho do vetor? ");
	scanf ("%d", &quant);
	
	//alocando 'quant' posições de memória para 'v'
	v = (*float) malloc (quant*sizeof(float));    //memory allocation
  	
	if (v == NULL)
	{
		printf ("Erro! Nao há memoria livre para v!\n");
	}
	else
	{
		for (i=0;i<quant;i++)
		{
			printf ("Entre com um numero: ");
			scanf ("%d", &v[i]);
		}
	}	
}
