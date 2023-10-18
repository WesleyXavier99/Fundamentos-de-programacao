/*QUESTÃO 01:Faça um função que, dada uma matriz M8×5 de
reais, gere a matriz Mt, sua transposta*/

#include<stdio.h>
#define LINHA 4
#define COLUNA 2

int Transposta(float matriz[][]);

void main()
{
	int i,j;
	int matrizPrincipal[LINHA][COLUNA];
	
	for(i=0;i<LINHA;i++)
	{
		for(j=0;j<COLUNA;j++)
		{
			printf("Digite a posicao [%d][%d] da matriz:\n",i,j);
			scanf("%d", &matrizPrincipal[i][j]);
		}
	}
	
	Transposta(matrizPrincipal);
}

int Transposta(int matrizPrincipal[][])
{
	int i,j,l;
	float matrizTransposta[LINHA][COLUNA];
	
	for(i=0;i<LINHA;i++)
	{
		for(l=0,j=COLUNA-1;j>=0;j--,l++)
		{
			matrizTransposta[j]=matrizPrincipal[l];
		}
	}
	
	for(i=0;i<LINHA;i++)
	{
		for(j=0;j<COLUNA;j++)
		{
			printf("%f\n",matrizPrincipal[i][j]);
		}
	}
	printf("\n");
	for(i=0;i<LINHA;i++)
	{
		for(j=0;j<COLUNA;j++)
		{
			printf("%f\n",matrizTransposta[i][j]);
		}
	}
	
	
}
