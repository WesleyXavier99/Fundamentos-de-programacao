#include<stdio.h>
#include<stdlib.h>
//Implementar uma função que, dada um arquivo texto A contendo números inteiros,
//crie dois novos arquivos:
//i. Um contendo todos os pares de A;
//ii. Um contendo todos os ímpares de A.
//Nota: os arquivos de pares e ímpares não podem conter valores repetidos.
#define TAM 10


void main()
{
	int tam = TAM;
	FILE *arq = fopen("arquivoQ3.txt","r");
	FILE *impar = fopen("arquivoimpar","w+");
	FILE *par = fopen("arquivopar","w+");
	int i;
	
	if(arq == NULL)
	{
		printf("nao foi possivel abrir o arquivo");
	}else{
		separar(arq,tam,impar,par);
	}
	
	
}

void separar(FILE *arq,int tam,FILE *impar,FILE *par)
{
	int i, aux[1000],Par[1000],TamPar = 0,Impar[1000],TamImpar = 0;
	
	if(impar == NULL || par == NULL)
	{
		printf("nao foi possivel abrir o arquivo");
	}else{
		for(i=0;i<tam;i++)
		{
			fscanf(arq,"%d",&aux[i]);
		}
		
		for(i=0;i<tam;i++)
		{
			printf("aux[%d] = %d\n",i,aux[i]);
		}
		
		for(i=0;i<tam;i++)
		{
			if(aux[i]%2 == 0)
			{
				Par[TamPar] = aux[i];
				TamPar++;
			}else{
				Impar[TamImpar] = aux[i];
				TamImpar++;
			}
		}
		
		for(i=0;i<TamPar;i++)
		{
			printf("Par[%d] = %d\n",i,Par[i]);
		}
		
		for(i=0;i<TamImpar;i++)
		{
			printf("Impar[%d] = %d\n",i,Impar[i]);
		}	
	}
	
	for(i=0;i<TamPar;i++)
	{
		fprintf(par,"%d ",Par[i]);
	}

	for(i=0;i<TamImpar;i++)
	{
		fprintf(impar,"%d ",Impar[i]);
	}	
}

