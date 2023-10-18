/*Questão 05: Implementar uma função que, dado um vetor contendo números
reais, determine o maior e o segundo maior elementos.
Nota: considerar que não há repetição de elementos no vetor.*/

#include<stdio.h>
#define QUANT 10


int main()
{
	int MaiorMenor(float vetor[]);
	int i;
	float vetor[QUANT];
	
	printf("Digite 10 valores para preencher o vetor:\n");
	for(i=0;i<QUANT;i++)
	{
		scanf("%f",&vetor[i]);
	}
	
	MaiorMenor(vetor);
	
}

int MaiorMenor(float vetor[])
{
	int i;
	float maior=vetor[0], segundomaior=vetor[0];
	
	for(i=0;i<QUANT;i++)//for pra varrer o vetor e procurar o maior numero dentro dele
	{
		if(vetor[i]>maior)//if pra achar um maior
		{
			maior=vetor[i];//depois de achar, a variavel maior q é quem vai ficar guardando o maior valor vai salvar esse numero
		}
		
	}
	
	for(i=0;i<QUANT;i++)//for pra varrer o vetor e achar o segundo maior
	{
		if((vetor[i]>segundomaior)&& (vetor[i]<maior))//if pra achar um numero menor q o maior e maior q o segundomaior(variavel responsavel por salvar o segundo maior)
		{
			segundomaior=vetor[i];
		}
	}
	printf("primeiro maior %f\n",maior);
	printf("segundo maior %f\n",segundomaior);
	
}
