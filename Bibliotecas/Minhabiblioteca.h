/*  CABEÇALHO!  */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*Somar dois valores*/
int soma(int a, int b){
	return a + b;
}

/*subtrair dois valores*/
int subtracao(int a, int b){
	return a - b;
}

/*passar conteudo do arquivo para uma string*/
void arqStr (char aux[], FILE* arquivo,int tam){
	while(fgets(aux,tam,arquivo)!=NULL);
}
#endif /*  BIBLIOTECA  */

