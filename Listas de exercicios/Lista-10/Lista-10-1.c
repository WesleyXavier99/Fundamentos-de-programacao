/*Questão 01: Suponha que não existissem as funções strlen, strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o mesmo objetivo daquelas.*/

#include<stdio.h>
#include<string.h>

int Strlen2(char palavra[]);
int Strcpy2(char palavra[],char auxpalavra[]);
int Strcat2(char palavra[],char palavra2[],char palavra3[]);
int Strcmp2(char palavra[],char palavra2[]);

int main()
{
	char palavra[30];
	char palavra2[30];
	char palavra3[30];
	char auxpalavra[30];
	int exibir;
	int aux;
	
	printf("Digite uma palavra:\n");
	gets(palavra);
	
	printf("Digite uma palavra:\n");
	gets(palavra2);
	
	exibir=Strlen2(palavra);
	printf("Strlen : %d\n", exibir);
	
	Strcpy2(palavra,auxpalavra);
	printf("Strcpy = %s\n",auxpalavra);
	
	aux=Strcmp2(palavra,palavra2);
	printf("Strcmp = %d\n", aux);
	
	Strcat2(palavra,palavra2,palavra3);
}

int Strlen2(char palavra[])
{
	int i,cont=0;
	
	for(i=0;palavra[i]!='\0';i++)
	{
		cont++;
	}
	
	return cont;
}

int Strcpy2(char palavra[],char auxpalavra[])
{
	int i;
	
	for(i=0;palavra[i]!='\0';i++)
	{
		auxpalavra[i]=palavra[i];
	}
	 auxpalavra[i]='\0';
}

int Strcat2(char palavra[],char palavra2[],char palavra3[])
{
	int i,j;
	
	for(i=0;i<strlen(palavra);i++)
	{
		palavra3[i]=palavra[i];
	}
	
	for(i=strlen(palavra),j=0;i<strlen(palavra)+strlen(palavra2);i++,j++)
	{
		palavra3[i]=palavra2[j];
	}
	
	palavra3[i]='\0';
	printf("%s\n",palavra3);
}

int Strcmp2(char palavra[],char palavra2[])
{
	int i;
	
	for(i=0;i<strlen(palavra) && i<strlen(palavra2);i++)
	{
		if(palavra[i]>palavra2[i])
		{
			return 1;
		}else{
			if(palavra[i]<palavra2[i])
			{
				return -1;
			}
		}
	}
	if(strlen(palavra)>strlen(palavra2))
	{
		return 1;
	}else{
		if(strlen(palavra)<strlen(palavra2))
		{
			return -1;
		}
	}
	return 0;
}



