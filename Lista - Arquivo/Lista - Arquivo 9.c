//Faca um programa que receba dois arquivos do usuario, e crie um terceiro arquivo com
//o conteudo dos dois primeiros juntos (o conteudo do primeiro seguido do conteudo do
//segundo).
#include<stdio.h>
#define TAM 1000

void Passar_Conteudo_String(char aux[],FILE *file,int tam);
void Passar_String(char aux1[],char aux2[],char aux3[]);
void Passar_Conteudo_Arquivo (FILE *file,char aux[]);

void main()
{
	//declaração de variaveis
	FILE *file1,*file2,*file3;
	char Aux1[TAM];
	char Aux2[TAM];
	char Aux3[TAM];
	int tam=TAM;
	
	puts(Aux3);
	
	//abrir arquivos
	file1 = fopen("Arq1_9.txt","r");
	file2 = fopen("Arq2_9.txt","r");
	file3 = fopen("Novo9","w");
	
	//passar conteudo dos arquivos para as strings
	Passar_Conteudo_String(Aux1,file1,tam);
	puts(Aux3);
	Passar_Conteudo_String(Aux2,file2,tam);
	puts(Aux3);
	
	
	//juntar as duas strings
	Passar_String(Aux1,Aux2,Aux3);
	puts(Aux3);
	
	//passar da string pro arquivo novo
	Passar_Conteudo_Arquivo(file3,Aux3);
	
}

void Passar_Conteudo_String(char aux[],FILE *file,int tam)
{
	while(fgets(aux,tam,file)!=NULL);
}

void Passar_String(char aux1[],char aux2[],char aux3[])
{
	int i,j,k;
	int tam;
	
	for(i=0;aux1[i]!=NULL;i++)
	{
		aux3[i]=aux1[i];
		tam=i;
	}
	
	aux3[i+1]='\n';
	
	for(j=i+2,k=0;aux2[i]!=NULL;j++)
	{
		aux3[j]=aux2[k];
	}
	aux3[j]='\0';
	
}

void Passar_Conteudo_Arquivo (FILE *file,char aux[])
{
	fputs(aux,file);
}
