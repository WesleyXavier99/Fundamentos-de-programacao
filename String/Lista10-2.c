/*Questão 02: Dada uma string s, desenvolver uma função que determine se s é ou não um palíndromo. 
Observação: uma string s será um palíndromo quando seus caracteres formarem a mesma sequência,
independente se s é percorrida da esquerda para direita ou vice-versa.*/ 

#include<stdio.h>
#include<string.h>

void main()
{
	int n;
	char palavra[20];
	
	printf("Digite uma palavra:\n");
	gets(palavra);
	
	n=palindromo(palavra);
	if(n==0)
	{
		printf("Nao e palindromo");
	}else{
		printf("e palindromo");
	}
}

int palindromo(char palavra[])
{
	int i,j;
	
	for(i=0,j=strlen(palavra)-1;i<strlen(palavra);i++,j--)
	{
		if(palavra[i]!=palavra[j])
		{
			
			return 0;
		}
	}
	return 1;
}
