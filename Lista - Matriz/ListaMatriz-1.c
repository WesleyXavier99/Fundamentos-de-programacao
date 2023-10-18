#include<stdio.h>
#define TAM 3
//Leia uma matriz 4 x 4, conte e escreva quantos valores maiores que 10 ela possui.

void main()
{
	int M[TAM][TAM]={1,2,3,11,22,33,1,22,3};
	int V[10];
	int resp,i,j;
	
//	for(i=0;i<TAM;i++)
//	{
//		printf("\n");
//		for(j=0;j<TAM;j++)
//		{
//			printf("%d ",M[i][j]);
//		}
//	}	
//	printf("\n");
	
	resp=Contar(M,V);
	printf("numero de maiores que 10 : %d\n",resp);
	for(i=0;i<resp;i++)
	{
		printf("%d ",V[i]);
	}
	
}

int Contar(int M[TAM][TAM],int V[])
{
	int i,j,cont=0;
	
	for(i=0;i<TAM;i++)
	{
		for(j=0;j<TAM;j++)
		{
			if(M[i][j]>10)
			{
				V[cont]=M[i][j];
				cont++;
			}
		}
	}
	return cont;
}
