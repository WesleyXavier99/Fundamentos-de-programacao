#include<Stdio.h>
#define CAP 5
//Escreva uma func¸ ˜ao recursiva que exibe todos os elementos em um array de inteiros,
//separados por espac¸o.

//consertar na parte q a funcao pega 1 casa a mais do vetor

void main()
{
	int vetor[CAP]={1,2,3,4,5};
	int quant=CAP;
	
	Exibir_Vetor(vetor,quant);
}

int Exibir_Vetor(int v[],int tam)
{
	
	if(tam==0)
	{
		printf("%d ",v[tam]);
	}else{
		Exibir_Vetor(v,tam-1);
		printf("%d ",v[tam]);
	}
	return tam+1;
}
