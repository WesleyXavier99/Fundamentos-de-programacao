/*QUESTÃO 04:
Fazer uma função que, dada uma matriz M6×6,
determine se ela é simétrica.*/
#include<stdio.h>
#define LINHAS 6
#define COLUNAS 6

void main()
{
	int i,j,l,resposta;
	int matriz[LINHAS][COLUNAS];
	
	for(i=0;i<LINHAS;i++)
	{ 
		for(j=0, l=i+1;j<COLUNAS;j++,l++)
		{
			matriz[i][j]=l;
		}
		
	}
	
	/*for(i=0;i<LINHAS;i++)
	{
		printf("\n");
		for(j=0;j<COLUNAS;j++)
		{
			printf("%d ",matriz[i][j]);
		}
	}*/
	resposta=Simetrica(matriz);
	
	if(resposta==1)
	{
		printf("nao e simetrica");
	}else{
		printf("e simetrica");
	}
}

int Simetrica(int matriz[LINHAS][COLUNAS])
{
	int i,j,cont=0,contSimetria=0;
	for(i=0;i<LINHAS;i++)
	{
		for(j=0;j<COLUNAS;j++)
		{
			if(matriz[i][j]==matriz[j][i])
			{
				cont++;
			}
		}
		if(cont==LINHAS)
		{
			contSimetria++;
			cont=0;
		}else{
			printf("\n");
			return 1;
		}
	}
	printf("\n");
	return 0;
}//if com duas condições;uma fixando linhas e outra fixando coluna;contador pra cada condicao
