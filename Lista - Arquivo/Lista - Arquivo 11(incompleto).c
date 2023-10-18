/*Faca um programa no qual o usuario informa o nome do arquivo e uma palavra, 
e retorne o numero de vezes que aquela palavra aparece no arquivo.*/

#include<stdio.h>
#include<string.h>
void arqStr(char aux[], FILE* file, int tam);

int main(){
	
	char nomeArquivo[20],palavra[20],Arquivo[200];
	int tamPalavra, tamArquivo;
	FILE *file;
	
	
	//pedindo o nome do arquivo e a palavra a ser encontrada
	printf("Digite o nome do arquivo:/n");
	gets(nomeArquivo);
	
	printf("Digite a palavra a ser procurada:/n");
	gets(palavra);
	
	//abrir o arquivo
	file = fopen(nomeArquivo,"r");
	
	//passar conteudo do arquivo para uma string
	arqStr(Arquivo,file,tamArquivo);
	
	//determinar o tamanho das strings
	tamPalavra = strlen(palavra);
	tamArquivo = strlen(Arquivo);
	
	//
}

void arqStr(char aux[], FILE* file, int tam)
{
	while(fgets(aux,tam,file)!=NULL);
}

