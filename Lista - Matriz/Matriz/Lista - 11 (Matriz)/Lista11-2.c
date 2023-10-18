/*QUESTÃO 02:Desenvolver uma função que, dada uma matriz
M15×20, determine se um número X se encontra na linha L da matriz*/
#include<stdio.h>
#define LINHAS 3
#define COLUNAS 4

int Encontrar(int matriz[][]);

int main()
{
	int resposta;
	int i,j,linha,num;
	int matriz[LINHAS][COLUNAS];
	
	for(i=0;i<LINHAS;i++)
	{
		for(j=0;j<COLUNAS;j++)
		{
			printf("digite a posicao [%d][%d]",i,j);
			scanf("%d",&matriz[i][j]);
		}
	}
	printf("Digite o numero que deseja encontrar na matriz:\n");
	scanf("%d",&num);
	
	printf("Digite a linha:\n");
	scanf("%d",&linha);
	
	for(i=0;i<LINHAS;i++)
	{
		for(j=0;j<COLUNAS;j++)
		{
			printf("%d ",matriz[i][j]);
			
		}
		printf("\n");
		
	}
	
	resposta=Encontrar(matriz,num,linha);
	if(resposta==1)
	{
		printf("se encontra");
	}else{
		printf("nao se encontra");
	}
	
	
}


int Encontrar(int matriz[][],int num,int linha)
{
	int i,j;
	for(i=linha;i=linha;i++)
	{
		for(j=0;j<COLUNAS;i++)
		{
			if(matriz[i][j]==num)
			{
				return 1;
			}
		}
	}
	return 0;
}
