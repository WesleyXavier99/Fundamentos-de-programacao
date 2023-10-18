/*Questão 03: Determinada instituição de ensino armazena, sob a forma de vetores (de structs), as seguintes informações:? 
Alunos: nome, matrícula;? 
Disciplinas do curso: nome, código;? 
Inscrições realizadas: matrícula do aluno, código da disciplina, semestre da inscrição (semestre/ano).
Pede-se o desenvolvimento de funções que realizem as seguintes operações:
i. Exibir, para cada aluno, o total de inscrições já realizadas;
ii. Dado um semestre, informar para cada disciplina o número de alunos inscritos.
*/
#include<stdio.h>
#include<string.h>
#define TAM 5
#define TAMANHO 3

typedef struct{
	char nome[60];
	int matricula;
}TAluno;

typedef struct{
	char nome_Disciplina[50];
	int codigo_Disciplina;
}TDisciplina;

typedef struct{
	TAluno aluno;
	TDisciplina disciplina;
	char semestre_Inscricao[20];
}TInscricao;

void preencher(TInscricao inscricoes[], int tam){
	int i;
	
	for(i=0;i<tam;i++){
		switch(i){
			case 0:
				//nome do aluno
				strcpy(inscricoes[i].aluno.nome,"Djonga Gustavo");
				//matricula do aluno
				inscricoes[i].aluno.matricula = 20200001;
				//nome da disciplina
				strcpy(inscricoes[i].disciplina.nome_Disciplina,"Sistemas operacionais");
				//codigo da disciplina
				inscricoes[i].disciplina.codigo_Disciplina = 5531;
				//semestre da inscricao
				strcpy(inscricoes[i].semestre_Inscricao,"2020.1");
			break;
			
			case 1:
				//nome do aluno
				strcpy(inscricoes[i].aluno.nome,"Wesley Xavier");
				//matricula do aluno
				inscricoes[i].aluno.matricula = 20200002;
				//nome da disciplina
				strcpy(inscricoes[i].disciplina.nome_Disciplina,"Sistemas operacionais");
				//codigo da disciplina
				inscricoes[i].disciplina.codigo_Disciplina = 5531;
				//semestre da inscricao
				strcpy(inscricoes[i].semestre_Inscricao,"2020.1");
				
			break;
			
			case 2:
				//nome do aluno
				strcpy(inscricoes[i].aluno.nome,"Djonga gustavo");
				//matricula do aluno
				inscricoes[i].aluno.matricula = 20200001;
				//nome da disciplina
				strcpy(inscricoes[i].disciplina.nome_Disciplina,"Fundamentos de Algoritmos de Computacao");
				//codigo da disciplina
				inscricoes[i].disciplina.codigo_Disciplina = 5532;
				//semestre da inscricao
				strcpy(inscricoes[i].semestre_Inscricao,"2020.1");
				
			break;
			
			case 3:
				//nome do aluno
				strcpy(inscricoes[i].aluno.nome,"Abebe bikila");
				//matricula do aluno
				inscricoes[i].aluno.matricula = 20200004;
				//nome da disciplina
				strcpy(inscricoes[i].disciplina.nome_Disciplina,"Construcao de aplicativos web");
				//codigo da disciplina
				inscricoes[i].disciplina.codigo_Disciplina = 5533;
				//semestre da inscricao
				strcpy(inscricoes[i].semestre_Inscricao,"2020.1");
			break;
			
			case 4:
				//nome do aluno
				strcpy(inscricoes[i].aluno.nome,"Abebe bikila");
				//matricula do aluno
				inscricoes[i].aluno.matricula = 20200004;
				//nome da disciplina
				strcpy(inscricoes[i].disciplina.nome_Disciplina,"Fundamentos de Algoritmos de Computacao");
				//codigo da disciplina
				inscricoes[i].disciplina.codigo_Disciplina = 5532;
				//semestre da inscricao
				strcpy(inscricoes[i].semestre_Inscricao,"2020.1");
			break;
		}
	}
}

void preencher_dis(TDisciplina disciplinas[],int TAMA){
	int i;
	
	for(i=0;i<TAMA;i++){
		switch(i){
			case 0: strcpy(disciplinas[i].nome_Disciplina,"Fundamentos de Algoritmos de Computacao");
					disciplinas[i].codigo_Disciplina = 5532;
				
				break;
			
			case 1: strcpy(disciplinas[i].nome_Disciplina,"Sistemas operacionais");
					disciplinas[i].codigo_Disciplina = 5531;
				
				break;
				
			case 2: strcpy(disciplinas[i].nome_Disciplina,"Construcao de aplicativos web");
					disciplinas[i].codigo_Disciplina =5533 ;
				
				break;
		}
	}
}

void exibir(TInscricao inscricoes[], int tam){
	int i,matricula_aluno;
	
	printf("\nDigite a matricula do aluno desejado:\n");
	scanf("%d",&matricula_aluno);
	
	for(i=0;i<tam;i++){
		if(matricula_aluno==inscricoes[i].aluno.matricula){
			puts(inscricoes[i].disciplina.nome_Disciplina);
			printf("%d\n",inscricoes[i].disciplina.codigo_Disciplina);
			puts(inscricoes[i].semestre_Inscricao);
		}
	}
}

void semestre(TInscricao inscricoes[],TDisciplina disciplinas[], int tam,int TAMAA){
	int i,cont1=0,cont2=0,cont3=0;
	char semestre_desejado[10];
	
	printf("\nDigite o semestre desejado:\n");
	gets(semestre_desejado);
	
	for(i=0;i<tam;i++){
		if(strcmp(semestre_desejado,inscricoes[i].semestre_Inscricao)==0){
			if(inscricoes[i].disciplina.codigo_Disciplina== disciplinas[0].codigo_Disciplina){
				cont1++;
			}else{
				if(inscricoes[i].disciplina.codigo_Disciplina == disciplinas[1].codigo_Disciplina){
					cont2++;
				}else{
					if(inscricoes[i].disciplina.codigo_Disciplina == disciplinas[2].codigo_Disciplina){
						cont3++;
					}
				}
			}
		}
	}
	
	printf("Disciplina: %s\ninscritos: %d\n\n",disciplinas[0].nome_Disciplina,cont1);
	printf("Disciplina: %s\ninscritos: %d\n\n",disciplinas[1].nome_Disciplina,cont2);
	printf("Disciplina: %s\ninscritos: %d\n\n",disciplinas[2].nome_Disciplina,cont3);
}

void main(){
	TInscricao inscricoes[TAM];
	TDisciplina disciplinas[TAMANHO];
	int tam = TAM,i;
	
	//preencher
	preencher(inscricoes,tam);
		
	//preencher
	preencher_dis(disciplinas,TAMANHO);

	//exibir
	exibir(inscricoes,tam);
	
	//alunos inscritos em tal semestre
	semestre(inscricoes,disciplinas,tam,TAMANHO);
	
}

