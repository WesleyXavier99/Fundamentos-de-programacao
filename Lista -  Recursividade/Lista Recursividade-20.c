#include<stdio.h>

void main()
{
	int n,resp;
	
	printf("Digite um numero : ");
	scanf("%d",&n);
	
	resp=fatorialExponencial(n);
	printf("%d",resp);
}

int fatorialExponencial(int n)
{
	int soma,aux;
	int i;
	
	if(n==2)
	{
		soma =2;
		return soma;
	}else{
		
		aux=fatorialExponencial(n-1);
		soma=n;
		
		for(i=1;i<aux;i++)
		{
			soma*= soma;
		}
	}
	return soma;
}
