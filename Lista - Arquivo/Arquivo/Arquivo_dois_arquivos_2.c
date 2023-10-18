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
	FILE *arq3 = fopen("arqC2.txt","w");
	float aux1[10],aux2[10],aux3[20];
	int tam1=0,tam2=0,tam3=0,i,l,j,aux;
	
	
	while(!feof(arq1)){
		fscanf(arq1,"%f",&aux1[tam1]);
		tam1++;
	}
	
	while(!feof(arq2)){
		fscanf(arq2,"%f",&aux2[tam2]);
		tam2++;
	}
	
	for(i=0;i<tam1;i++){
		printf("%.0f ",aux1[i]);
	}
	
	
	
	for(i=0;i<tam2;i++){
		printf("%.0f ",aux2[i]);
	}
	
	
	for(i=0;i<tam1;i++){
		for(j=0;j<tam2;j++){
			if(aux1[i]==aux2[j]){
				aux3[tam3]=aux1[i];
				tam3++;
			}
		}
	}
	
	printf("\nchegou");
	for(i=0;i<tam3;i++){
		printf("%.0f ",aux3[i]);
	}
	
	fclose(arq1);
	fclose(arq2);
	fclose(arq3);
		
	//funcao para ordenar o vetor
//	for(i=0;i<tam3-1;i++){
//		for(j=i+1;j<tam3;j++){
//			if(aux3[j]<aux3[i]){
//				aux = aux3[i];
//				aux3[i]=aux3[j];
//				aux3[j]=aux;
//			}
//		}
//	}
	
	//funcao pra eliminar repeticoes
//	for(i=0;i<tam3-1;i++){
//		if(aux3[i]==aux3[i+1]){
//			for(j=i+1;j<tam3;j++){
//				aux3[j]=aux3[j+1];
//			}
//			tam3--;
//		}	
//	}
	
	
	
}

void main(){
	
	char nome_arq1[20],nome_arq2[20];
	
	strcpy(nome_arq1,"q2.txt");
	strcpy(nome_arq2,"q3.txt");
	
	criar(nome_arq1,nome_arq2);
}
