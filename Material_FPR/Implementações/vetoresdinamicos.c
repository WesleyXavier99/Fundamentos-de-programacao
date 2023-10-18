/*
   FPR - 2020/1
   Aula de 28/09/2020
   
   Vetores din�micos
*/

//importa��o de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declarando o vetor v, por�m sem alocar mem�ria para as suas posi��es
	float *v;
	int quant;
	
	printf ("Qual o tamanho do vetor? ");
	scanf ("%d", &quant);
	
	//alocando 'quant' posi��es de mem�ria para 'v'
	v = (*float) malloc (quant*sizeof(float));    //memory allocation
  	
	if (v == NULL)
	{
		printf ("Erro! Nao h� memoria livre para v!\n");
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
