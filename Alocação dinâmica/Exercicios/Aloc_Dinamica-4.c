#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Faca um programa que receba do usuario o tamanho de uma string e chame uma
funcao para alocar dinamicamente essa string. Em seguida, o usuario devera informar o
conteudo dessa string. O programa imprime a string sem suas vogais.*/

void main()
{
	int tam,i,j;
	char *string;
	
	printf("Digite o tamanho da string:\n");
	scanf("%d",&tam);
	
	string =(char *)malloc(tam * (sizeof(char)));
	
	printf("Digite o conteudo da string:\n");
	fflush(stdin);
	gets(string);
	printf("\n");
	
	for(i=0;string[i]!='\0';)
	{
		printf("%c",string[i]);
		if(string[i]=='a'||string[i]=='e'||string[i]=='i'||string[i]=='o'||string[i]=='u')
		{
			for(j=i;j<tam-1;j++)
			{
				string[j]=string[j+1];
				tam-1;		
			}
				printf("\nachou\n");
		}else{
			i++;
		}	
	}
	string[i]='\0';
	printf("\n");
	
	for(i=0;string[i]!='\0';i++)
	{
		printf("%c",string[i]);	
	}
	printf("\n");
	puts(string);
}
