//Faca um programa que receba do usu´ ario um arquivo texto. Crie outro arquivo texto
//contendo o texto do arquivo de entrada, mas com as vogais substitu´ýdas por ‘*’.
#include<stdio.h>
#define TAM 1000

void Passar_Conteudo_String(char aux[],FILE *file1,int tam);
void Trocar_Vogais(char aux[]);
void Passar_Conteudo_Arquivo(char aux[],FILE *file2);

void main()
{
	//declaração de variaveis
	FILE *file1,*file2;
	char aux[TAM];
	int tam=TAM;
	
	//abrindo arquivos
	file1 = fopen("Questao7.txt","r");
	file2 = fopen("Novo7","w");
	
	//passar do arquivo do usuario para string
	Passar_Conteudo_String(aux,file1,tam);
	
	//trocar as vogais por "*"
	Trocar_Vogais(aux);
	
	//passar da string pro novo arquivo
	Passar_Conteudo_Arquivo(aux,file2);
	
	//fechar os arquivos
	fclose(file1);
	fclose(file2);
}

void Passar_Conteudo_String(char aux[],FILE *file1,int tam)
{
	while(fgets(aux,tam,file1)!= NULL);
}

void Trocar_Vogais(char aux[])
{
	int i;
	
	for(i=0;aux[i]!=NULL;i++)
	{
		switch(aux[i])
		{
			case 'a' : aux[i]='*';
			break;
			
			case 'e' : aux[i]='*';
			break;
			
			case 'i' : aux[i]='*';
			break;
			
			case 'o' : aux[i]='*';
			break;
			
			case 'u' : aux[i]='*';
			break;
			
			case 'A' : aux[i]='*';
			break;
			
			case 'E' : aux[i]='*';
			break;
			
			case 'I' : aux[i]='*';
			break;
			
			case 'O' : aux[i]='*';
			break;
			
			case 'U' : aux[i]='*';
			break;
		}
	}
}

void Passar_Conteudo_Arquivo(char aux[],FILE *file2)
{
	fputs(aux,file2);
}
