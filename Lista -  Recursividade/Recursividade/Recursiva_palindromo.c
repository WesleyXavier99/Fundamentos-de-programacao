/*Questão 05:
Dada uma string s, desenvolver uma função
recursiva que determine se s é ou não um
palíndromo.*/
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
	//declaração de variaveis
	char palavra[20];
	int resultado,tam;
	
	//obter dados do usuario
	printf("Digite uma palavra:");
	gets(palavra);
	tam = strlen(palavra)-1;
	
	//chamada da funçao
	resultado = palindromo(palavra,0,tam);
	
	if(resultado == 1){
		printf("\neh palindromo\n");
	}else{
		printf("\nNao eh palindromo\n");
	}
	
}
