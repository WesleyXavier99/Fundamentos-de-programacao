//Crie uma funcao recursiva que receba um numero inteiro positivo N e calcule o somatorio
//dos numeros de 1 a N.
#include<stdio.h>

void main()
{
	int n,soma,somaf=0;
	
	printf("Digite um numero : \n");
	scanf("%d",&n);
	
	soma=somatorio(n);
	printf("O somatorio e : %d",soma);
}

int somatorio(int n)
{
	int soma;
	if(n==1)
	{
		soma=1;
	}else{
		soma= n + somatorio(n-1);
	}
	return soma;
}
