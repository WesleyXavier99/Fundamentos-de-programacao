//Questão 04: Implementar uma função que remova todas as ocorrências de determinado caracter em uma string.

#include<stdio.h>
#include<string.h>

void RemoverCaracter(char palavra[],char caracter);
void main()
{
	char palavra[30];
	char caracter;
	printf("Digite uma string :\n");
	gets(palavra);
	
	printf("Digite o caracter a ser removido:\n");
	scanf("%c",&caracter);
	
	RemoverCaracter(palavra,caracter);
}

void RemoverCaracter(char palavra[],char caracter)
{
	int i,j;
	
	for(i=0;i<strlen(palavra);i++)
	{
		if(palavra[i]==caracter)
		{
			for(j=i;palavra[j]!='\0';j++)
			{
				palavra[j]=palavra[j+1];
			}
		}
	}
	printf("%s",palavra);
}
