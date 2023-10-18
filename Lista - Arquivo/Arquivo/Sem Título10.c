/*Questão 06:
Desenvolver uma função que, dados dois arquivos textos arqA e arqB, crie um novo arquivo arqC, considerando que:
? arqA e arqB contém números reais, um por linha, ordenados crescentemente e sem repetição no arquivo;
? arqC deve conter todos os números dos dois arquivos originais;
? Assim como arqA e arqB, arqC também não possuirá repetições e seus valores estão em ordem crescente*/
#include<stdio.h>
#include<string.h>

void criar(char nome_arq1[],char nome_arq2[]){
	FILE *arq1 = fopen(nome_arq1,"r");
	FILE *arq2 = fopen(nome_arq2,"r");
	float aux1[10],aux2[10],aux3[20];
	int tam1=0,tam2=0,tam3=0,i;
	
	while(!feof(arq1)){
		fscanf(arq1,"%f",&aux1[tam1]);
		tam1++;
	}
	
	while(!feof(arq2)){
		fscanf(arq2,"%f",&aux2[tam2]);
		tam2++;
	}
	
	for(i=0;i<tam1;i++){
		printf("%f ",aux1[i]);
	}
	
	for(i=0;i<tam1;i++){
		printf("%f ",aux2[i]);
	}
	
	fclose(arq1);
	fclose(arq2);
	
}

void main(){
	
	char nome_arq1[20],nome_arq2[20];
	
	strcpy(nome_arq1,"q2.txt");
	strcpy(nome_arq2,"q3.txt");
	
	criar(nome_arq1,nome_arq2);
}
