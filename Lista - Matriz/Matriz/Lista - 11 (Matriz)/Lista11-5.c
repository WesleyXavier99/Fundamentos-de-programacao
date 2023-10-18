/*QUESTÃO 05:Implementar uma função que, dada uma matriz M10×8, 
gere um vetor V de tamanho 8, onde cada elemento do vetor consiste na soma
dos elementos de uma coluna de M. Ou seja, 
o elemento V[1] consiste na soma dos elementos da primeira coluna de M, 
o elemento V[2] consiste na soma dos elementos da segunda coluna de M, 
e assim por diante.*/
#include<stdio.h>
#define LINHAS 10
#define COLUNAS 8

void SomaElementos(int matriz[LINHAS][COLUNAS]);

void main()
{
	int i,j,l;
	int matriz[LINHAS][COLUNAS];
	
	for(i=0;i<LINHAS;i++)
	{
		for(j=0,l=i+1;j<COLUNAS;j++,l++)
		{
			matriz[i][j]=l;
		}
	}
	
	for(i=0;i<LINHAS;i++)
	{
		printf("\n");
		for(j=0;j<COLUNAS;j++)
		{
			printf("%d\t",matriz[i][j]);
		}
	}
	printf("\n");
	printf("\n");
	
	SomaElementos(matriz);
	
}

void SomaElementos(int matriz[LINHAS][COLUNAS])
{
	int i,j,soma=0;
	int vetor[COLUNAS];
	
	for(i=0;i<COLUNAS;i++)
	{
		for(j=0;j<LINHAS;j++)
		{
			soma+=matriz[j][i];
			
		}
		vetor[i]=soma;
		soma=0;
	}
	
	for(i=0;i<COLUNAS;i++)
	{
		printf("%d\t",vetor[i]);
	}
	
}
