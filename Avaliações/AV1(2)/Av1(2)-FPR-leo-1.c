//Desenvolver uma função recursiva que, dado um vetor
//contendo Q números reais, determine se tais
//elementos encontram-se ordenados crescentemente.
#include<stdio.h>

void main()
{
	int V[10]={0,1,2,-1,4,5,6,7,8,9};
	int Q = 10;
	int resp,i=10,p;
	
	resp = funcao(V,Q,0,&p);
	
	if(p==0)
	{
		printf("\nesta crescente ");
	}else{
		printf("\nnao esta crescente");
	}
	
}

int funcao(int vetor[],int quant,int i,int *p)
{
	int resp;
	
	if(i==quant-2)
	{
		if(vetor[i]>vetor[i+1])
		{
			*(p)+=1;
		}
		return 0;
	}else{
		if(vetor[i]>vetor[i+1])
		{
			*(p)+=1;
		}
		funcao(vetor,quant,i+1,p);
	}
}
