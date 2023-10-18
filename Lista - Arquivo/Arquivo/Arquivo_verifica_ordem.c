/*Questão 04: Desenvolver uma função que, dado um arquivo texto contendo números, determine se estes
encontram-se ordenados crescentemente.*/

#include<stdio.h>

int verificar(char nome_arq[]){
	FILE *arq = fopen(nome_arq,"r");
	int aux=-9999999,c;
	
	while(!feof(arq)){
		fscanf(arq,"%d",&c);
		if(c<aux){
			fclose(arq);
			return 1;
		}
		aux=c;
	}
	fclose(arq);
	return 0;
}

void main(){
	int resultado;
	char nome_arq[100];
	
	printf("digite o nome do arquivo:\n");
	gets(nome_arq);
	
	resultado = verificar(nome_arq);
	
	if(resultado==0){
		printf("\nEstao ordenados crescentemente");
	}else{
		printf("\nNao estao ordenados crescentemente");
	}
	
	
}
