/*Questão 04: Suponha a existência de um vetor de tamanho TAM, cada posição armazenando o nome da pessoa e a sua data de aniversário 
(representada por um struct do tipo TData, contendo os campos dia e mes). 
Pede-se o desenvolvimento das seguintes funções:? Determinar a quantidade de pessoas que fazem aniversário no mês M;? 
Exibir os nomes de todas pessoas que fazem aniversário entre as datas d1 e d2, ambas do tipo Tdata.*/
#include<stdio.h>
#include<string.h>

#define TAM 5

typedef struct{
	int dia;
	int mes;
}TData;

typedef struct{
	char nome[100];
	TData data;
}TPessoa;

void preencher(TPessoa aniversariantes[],int tam){
	int i;
	
	for(i=0;i<tam;i++){
		switch(i){
			case 0: strcpy(aniversariantes[i].nome,"Wesley Xavier");
					aniversariantes[i].data.dia = 15;
					aniversariantes[i].data.mes = 12;
			break;	
			
			case 1: strcpy(aniversariantes[i].nome,"Abebe Bikila");
					aniversariantes[i].data.dia = 20;
					aniversariantes[i].data.mes = 12;
				
			break;	
			
			case 2: strcpy(aniversariantes[i].nome,"Djonga");
					aniversariantes[i].data.dia = 7;
					aniversariantes[i].data.mes = 4;
				
			break;	
			
			case 3: strcpy(aniversariantes[i].nome,"Baco Exu");
					aniversariantes[i].data.dia = 21;
					aniversariantes[i].data.mes = 3;
				
			break;	
			
			case 4: strcpy(aniversariantes[i].nome,"Sant");
					aniversariantes[i].data.dia = 10;
					aniversariantes[i].data.mes = 16;
				
			break;	
		}
	}
}

void exibir(TPessoa aniversariantes[],int tam){
	int i;
	
	for(i=0;i<tam;i++){
		printf("\n%s\n",aniversariantes[i].nome);
		printf("%d/%d\n",aniversariantes[i].data.dia,aniversariantes[i].data.mes);
	}
}

int mes_aniversarios(TPessoa aniversariantes[],int mes, int tam){
	int i,cont=0;
	
	for(i=0;i<tam;i++){
		if(mes==aniversariantes[i].data.mes){
			cont++;
		}
	}
	return cont;
}

void intervalo(TPessoa aniversariantes[],int dia1,int mes1,int dia2,int mes2, int tam){
	int i;
	
	for(i=0;i<tam;i++){
		if(aniversariantes[i].data.mes>=mes1 && aniversariantes[i].data.mes<=mes2){
			if(aniversariantes[i].data.dia>=dia1 && aniversariantes[i].data.dia<=dia2){
				puts(aniversariantes[i].nome);
			}
		}
	}	
}


void main(){
	TPessoa aniversariante[5];
	int dia,mes,dia2,mes2,resultado;
	
	//preencher
	preencher(aniversariante,TAM);
	
	//exibe todas informações
	exibir(aniversariante,TAM);
	
	//determina aniversariantes do mês
	printf("Mes:");
	scanf("%d",&mes);
	resultado = mes_aniversarios(aniversariante,mes,TAM);
	printf("\n%d pessoas fazem aniversarios no mes %d\n",resultado,mes);
	
	//aniversário entre as datas
	printf("data 1:\n");
	scanf("%d %d",&dia,&mes);
	
	printf("\ndata2:\n");
	scanf("%d %d",&dia2,&mes2);
	
	intervalo(aniversariante,dia,mes,dia2,mes2,TAM);
}



