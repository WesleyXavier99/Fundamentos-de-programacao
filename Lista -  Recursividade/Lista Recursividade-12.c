//Crie um programa que contenha uma func¸ ˜ao recursiva para encontrar o menor elemento
//em um vetor.


//consertar na parte q a funcao pega 1 casa a mais do vetor
#include<stdio.h>
#define CAP 5

void main()
{
	int vetor[CAP]={2,3,1,4,-1};
	int quant=CAP,menor,resultado;
	
	Menor(vetor,quant,&menor);
	
	printf("O menor valor e : %d",menor);
}

int Menor(int v[],int tam,int *menor)
{
	(*menor)=v[0];
	
	if(tam==0)
	{
		if(v[tam]<*menor)
		{
			(*menor)=v[tam];
		}
		printf("%d ultimo",*menor);
	}else{
		Menor(v,tam-1,menor);
		if(v[tam]<*menor)
		{
			(*menor)=v[tam];
		}
		printf("%d ",*menor);
	}
	
	return tam+1;
}
