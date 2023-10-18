/*Questão 02:Desenvolver uma função que, dado um arquivo texto, verifique o número de vezes que um
determinado caracter aparece no arquivo.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int verificar(char nome_arq[],char caracter){
	int cont=0,i;
	FILE *arq = fopen(nome_arq,"r");
	char aux[1000];
	
	while(fgets(aux,1000,arq)!=NULL)
	
	for(i=0;aux[i]!='\0';i++){
		if(aux[i]==caracter){
			cont++;
		}
	}
	fclose(arq);
	return cont;
}

void main(){
	char nome_arq[100],caracter;
	int resultado;
	
	printf("Digite o nome do arquivo:\n");
	gets(nome_arq);
	fflush(stdin);
	
	printf("Digite o caracter a ser procurado:\n");
	scanf("%c",&caracter);
	
	resultado = verificar(nome_arq,caracter);
	
	printf("\nO caracter %c aparece %d vezes no arquivo",caracter,resultado);
	
}
