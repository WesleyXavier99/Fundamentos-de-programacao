//Faca um programa que receba do usuario um arquivo texto e um caracter. Mostre na tela
//quantas vezes aquele caractere ocorre dentro do arquivo.

#include<stdio.h>

void main()
{
	//declaração de variaveis
	FILE *file;
	char letras[1000];
	char caractere;
	int i;
	int cont=0;
	
	//arquivo do usuario
	file = fopen("string.txt","r");
	
	//entrada de dados
	printf("Digite uma letra : \n");
	scanf("%c",&caractere);
	
	//passando do arquivo pra string
	while(fgets(letras,1000,file)!=NULL)
	
	//conferindo quantas vezes existe o caracter no arquivo
	for(i=0;letras[i]!=NULL;++i)
	{
		if(letras[i] == caractere)
		{
			cont++;
		}
	}
	
	//mostrando ao usuario
	printf("O numero de vezes que a letra %c aparece no arquivo e : %d",caractere,cont);
}
