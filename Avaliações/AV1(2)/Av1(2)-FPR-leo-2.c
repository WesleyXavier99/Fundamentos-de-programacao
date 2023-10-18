#include<stdio.h>
#include<stdlib.h>
//Dada uma matriz M15x10 contendo valores reais, pede-se a implementacao de uma funcao que
//inverta seus elementos

#define LINHAS 15
#define COLUNAS 10
void preencher(int matriz[LINHAS][COLUNAS],int linhas,int colunas);
void inverter(int matriz[LINHAS][COLUNAS],int linhas, int colunas);
void exibir(int matriz[LINHAS][COLUNAS],int linhas,int colunas);

void main()
{
	int matriz[LINHAS][COLUNAS];
	int linhas = LINHAS, colunas = COLUNAS;
	
	preencher(matriz,linhas,colunas);
	exibir(matriz,linhas,colunas);
	
	inverter(matriz,linhas,colunas);
	exibir(matriz,linhas,colunas);
}

void preencher(int matriz[LINHAS][COLUNAS],int linhas,int colunas)
{
	int i,j,l=1;
	
	for(i=0;i<LINHAS;i++)
	{
		for(j=0;j<COLUNAS;j++,l++)
		{
			matriz[i][j] = l;
		}
	}
}

void inverter(int matriz[LINHAS][COLUNAS],int linhas, int colunas)
{
	int aux[linhas][colunas];
	int i2=linhas-1,j2=colunas-1,i,j;
	
	for(i=0;i<linhas;i++,i2--)
	{
		j2 = colunas-1;
		for(j=0;j<colunas;j++,j2--)
		{
			aux[i][j]= matriz[i2][j2];
		}
	}
	
	for(i=0;i<linhas;i++)
	{
		for(j=0;j<colunas;j++)
		{
			matriz[i][j] = aux[i][j];
		}
	}
}

void exibir(int matriz[LINHAS][COLUNAS],int linhas,int colunas)
{
	int i,j;
	
	for(i=0;i<LINHAS;i++)
	{
		for(j=0;j<COLUNAS;j++)
		{
			printf("%d\t",matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
