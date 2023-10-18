/*Questão 05: Faça uma função que, dado um arquivo A contendo números reais, um por linha, crie um
novo arquivo B contendo os mesmos elementos de A, porém ordenados decrescentemente e sem repetição.*/
#include<stdio.h>
#include<string.h>

void criar(char nome_arq[]){
	
	FILE *arqA = fopen(nome_arq,"r");
	FILE *arqB = fopen("arquivoB.txt","w");
	float aux[100],menor,aux1;
	int tam=0,i,j;
	
	while(!feof(arqA)){
		fscanf(arqA,"%f",&aux[tam]);
		tam++;
	}
	
	for(i=0;i<tam-1;i++){
		for(j=i+1;j<tam-1;j++){
			if(aux[j]<aux[i]){
			aux1 = aux[i];
			aux[i] = aux[j];
			aux[j]=aux1;	
			}
		}
	}
	
	for(i=0;i<tam-1;i++){
		printf("\n%f",aux[i]);
	}
	
	for(i=0;i<tam-1;i++){
		fprintf(arqB,"%.0f\n",aux[i]);
	}
	
	fclose(arqA);
	fclose(arqB);
}

void main(){
	
	char nome_arq[100];
	
	printf("Digite o nome do arquivo:");
	gets(nome_arq);
	
	criar(nome_arq);
}
