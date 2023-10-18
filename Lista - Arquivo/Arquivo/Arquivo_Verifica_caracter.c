/*Questão 01:Desenvolver uma função que, dado um arquivo texto, verifique o número de caracteres no mesmo.*/
#include<stdio.h>
#include<string.h>

int verificar(char nome_arq[]){
	int cont=0,i;
	char aux[1000];
	FILE *arq = fopen(nome_arq,"r");
	
	while(fgets(aux,1000,arq)!=NULL);
	
	for(i=0;aux[i]!='\0';i++){
		if(aux[i]!=' '){
			cont++;
		}
		
	}
	return cont;
}

void main(){
	
	int resultado;
	char nome_arq[100];
	
	printf("digite o nome do arquivo:\n");
	gets(nome_arq);
	
	resultado = verificar(nome_arq);
	
	printf("\nO arquivo tem %d caracteres\n",resultado);
}
