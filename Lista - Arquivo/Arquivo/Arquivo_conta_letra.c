/*Desenvolver uma função que, dado um arquivo texto, verifique o número de letras existentes
no mesmo (entendendo que no arquivo podem existir letras, algarismos e símbolos).*/
#include<stdio.h>
#include<string.h>

void preencher(char alfabeto[],int tam){
	int maiusculas = 65,minusculas = 97,i;
	for(i=0;i<tam;i++,maiusculas++){
		if(i>=0&&i<=25){
			alfabeto[i]=maiusculas;
		}else{
			if(i>25&&i<=51){
				alfabeto[i]=minusculas;
				minusculas++;
			}else{
				alfabeto[i]='\0';
			}
		}
	}
}

int verificar(char nome_arq[],char alfabeto[]){
	int i,j,cont=0;
	FILE *arq = fopen(nome_arq,"r");
	char aux[1000];
	
	while(fgets(aux,1000,arq)!=NULL);
	
	for(i=0;aux[i]!='\0';i++){
		
		for(j=0;alfabeto[j]!='\0';j++){
			if(aux[i]==alfabeto[j]){
				cont++;
			}
		}
	}
	
	return cont;
}

void main(){
	int resultado,tam = 27+26;
	char nome_arq[100],alfabeto[tam];
	
	preencher(alfabeto,tam);
	
	printf("digite o nome do arquivo:\n");
	gets(nome_arq);
	
	resultado = verificar(nome_arq,alfabeto);
	
	printf("\nO arquivo tem %d letras\n",resultado);
}
