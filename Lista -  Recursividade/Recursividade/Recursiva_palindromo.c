/*Quest�o 05:
Dada uma string s, desenvolver uma fun��o
recursiva que determine se s � ou n�o um
pal�ndromo.*/
#include<stdio.h>
#include<string.h>

int palindromo(char palavra[],int i,int j){

	if(palavra[i]!=palavra[j]){
		return 0;
	}else{
		if(j<=i){
			return 1;
		}
		palindromo(palavra,i+1,j-1);
	}
}

void main(){
	//declara��o de variaveis
	char palavra[20];
	int resultado,tam;
	
	//obter dados do usuario
	printf("Digite uma palavra:");
	gets(palavra);
	tam = strlen(palavra)-1;
	
	//chamada da fun�ao
	resultado = palindromo(palavra,0,tam);
	
	if(resultado == 1){
		printf("\neh palindromo\n");
	}else{
		printf("\nNao eh palindromo\n");
	}
	
}
