/*Exercício:

Considere a existência de um vetor no qual cada posição pode armazenar o nome do aluno,
as notas de AV1 e AV2, sua média e a situação (aprovado, reprovado ou em AVF). Pede-se:

A declaração do vetor, assim como de todos os tipos de dados necessários, caso
existam;

Uma função que leia os dados de todos os alunos da turma;

Uma função que calcule a média de cada aluno (e a armazene no vetor), assim como a
sua situação;

Uma função que, dado um número inteiro (1-aprovado;2-reprovado;3-em AVF), exiba
todos os alunos que estão nesta situação.*/
#include<stdio.h>
#include<string.h>
#define TAM 3

/*Definição da struct*/
typedef struct{
	char aluno[50];
	float av1;
	float av2;
	float media;
	char situacao[10];
}Taluno;

/*Função para ler os dados do aluno*/
void ler_Dados(Taluno dados[],int *tam){
	
	while(*tam<TAM){
		printf("Nome do aluno:\n");
		fflush(stdin);
		gets(dados[*tam].aluno);
		printf("Nota AV1:\n");
		scanf("%f",&dados[*tam].av1);
		printf("Nota AV2:\n");
		scanf("%f",&dados[*tam].av2);
		*tam+=1;
	}
}

/*Função para calcular a media e determinar a situação do aluno*/
void Calcular_Media_Situacao(Taluno dados[],int *tam){
	int i;
	
	for(i=0;i<*tam;i++){
		dados[i].media= (dados[i].av1 + dados[i].av2) /2;
		if(dados[i].media>=6.0){
			strcpy(dados[i].situacao,"aprovado");
		}else{
			if(dados[i].media>=4.0){
				strcpy(dados[i].situacao,"em AVF");
			}else{
				strcpy(dados[i].situacao,"reprovado");
			}
		}
	}
}

/*Função para exibir os resultados*/
void Exibir_Resultados(Taluno dados[],int *tam,int opcao){
	int i;
	
	if(opcao==1){
		printf("Aprovados:\n");
		for(i=0;i<*tam;i++){
			if(strcmp(dados[i].situacao,"aprovado")==0){
				puts(dados[i].aluno);
			}	
		}
	}else{
		if(opcao==2){
			printf("Em AVF:\n");
			for(i=0;i<*tam;i++){
				if(strcmp(dados[i].situacao,"em AVF")==0){
					puts(dados[i].aluno);
				}
			}
		}else{
			printf("Reprovados:\n");
			for(i=0;i<*tam;i++){
				if(strcmp(dados[i].situacao,"reprovado")==0){
					puts(dados[i].aluno);
				}
			}
		}
	}
	
}

void main(){
	
	int tam_Dados=0,opcao;
	Taluno dados[TAM];
	
	ler_Dados(dados,&tam_Dados);
	
	Calcular_Media_Situacao(dados,&tam_Dados);
		
	printf("Digite uma opcao para exibir(1-aprovados/2-Em AVF/3-Reprovados)\n");
	scanf("%d",&opcao);
	Exibir_Resultados(dados,&tam_Dados,opcao);
}

