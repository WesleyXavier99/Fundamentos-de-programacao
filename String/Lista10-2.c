/*Quest�o 02: Dada uma string s, desenvolver uma fun��o que determine se s � ou n�o um pal�ndromo. 
Observa��o: uma string s ser� um pal�ndromo quando seus caracteres formarem a mesma sequ�ncia,
independente se s � percorrida da esquerda para direita ou vice-versa.*/ 

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
