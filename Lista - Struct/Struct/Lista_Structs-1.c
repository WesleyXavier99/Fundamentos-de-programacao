/*Questão 01:
Determinada zona eleitoral possui N eleitores inscritos que poderão votar, uma única vez, em
um dos C candidatos para o único cargo a ser definido. Pede-se:
a. A declaração do vetor de structs, assim como de todos os tipos de dados necessários, que represente os resultados
da votação;
b. Uma função que leia o voto de cada eleitor, considerando que o processo terminará quando os N eleitores votarem ou quando o
número -1 for digitado como voto;
c. Uma função que exiba:
i. O total de votos para cada candidato, assim com a quantidade de votos brancos (código 0) e de nulos (código
sem candidato associado);
ii. A quantidade de abstenções (eleitores que não votaram);
iii. O nome do candidato vencedor (caso tenha mais de 50% dos votos válidos) dos que irão para o segundo turno (os
dois mais votados).
Nota: o número do candidato deve conter dois algarismos apenas.*/
#include<stdio.h>
#include<string.h>
#define TAM 10

typedef struct {
	int voto;
}Teleitores;

void ler_Votos(Teleitores voto[],int *tam){
	int i,opcao=0;
	for(i=0;i<*tam;i++){
		voto[i].voto = -1;
	}
	
	i=0;
	while(i<*tam&&opcao!=-1){
		printf("Voto(Lula : 40/Bozo 2: 75/Ciro: 89):\n");
		scanf("%d",&opcao);
		voto[i].voto = opcao;
		i++;
	}
}
void exibir_resultados(Teleitores voto[], int *tam){
	int i,cand1=0,cand2=0,cand3=0,branco=0,nulo=0,abstencoes=0,total_Votos=0;
	char vencedor[40],lula[10],bozo[10],ciro[10];
	strcpy(lula,"Lula");
	strcpy(bozo,"Bozo");
	strcpy(ciro,"Ciro");
	
	for(i=0;i<*tam;i++){
		switch(voto[i].voto)
		{
			case 40:
				cand1++;
				total_Votos++;
			break;
			case 75:
				cand2++;
				total_Votos++;
			break;
			case 89:
				cand3++;
				total_Votos++;
			break;
			case 0:
				branco++;
				total_Votos++;
			break;
			case -1:
				abstencoes++;
			break;
			default :
				nulo++;
				total_Votos++;
			break;
		}
	}
	
	printf("Lula: %d\nBozo: %d\nCiro: %d\nbrancos: %d\nnulos: %d\nabstencoes: %d\n",cand1,cand2,cand3,branco,nulo,abstencoes);
	printf("votos totais: %d\n",total_Votos);
	printf("Resultado:\n");
	
	if(cand1 > (total_Votos/2)){
		strcpy(vencedor,"Lula");
	}else{
		if(cand2 > (total_Votos/2)){
		strcpy(vencedor,"Bozo");
		puts(vencedor);			
		}else{
			if(cand3 > (total_Votos/2)){
				strcpy(vencedor,"Ciro");
				puts(vencedor);
			}else{
				printf("Segundo turno com os seguintes candidatos:\n");
				if(cand1>cand3 && cand2>cand3){
					puts(lula);
					puts(bozo);
				}else{
					if(cand1>cand2 && cand3>cand2){
						puts(lula);
						puts(ciro);
					}else{
						if(cand3>cand1 && cand2>cand1){
							puts(ciro);
							puts(bozo);
						}
					}
				}
			}
		}
	}
}

void main(){
	Teleitores voto_Eleitor[TAM];
	int tam=TAM;
	
	ler_Votos(voto_Eleitor,&tam);
	exibir_resultados(voto_Eleitor,&tam);
}
