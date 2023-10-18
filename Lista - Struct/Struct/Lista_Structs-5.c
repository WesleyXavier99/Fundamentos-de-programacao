/*Questão 05: O histórico de um aluno é representado por um vetor de structs onde cada posição armazena o código da disciplina 
cursada, semestre e ano que a cumpriu e a média final na disciplina. Implementar uma função que exiba o histórico do aluno com 
o seguinte formato:
NomeDisciplina1 (código1) 
MédiaDisciplina1
NomeDisciplina2 (código2) 
MédiaDisciplina2
...
NomeDisciplinaN (códigoN) 
MédiaDisciplinaN
Coeficiente de rendimento: CR
Observações:1. Para obter os dados da disciplina, um outro vetor de structs deve ser consultado. Este, por sua vez, armazena para 
cada disciplina do curso as seguintes informações: código, nome e número de créditos;2. O coeficiente de rendimento consiste em 
uma média ponderada de todos os graus atribuídos às disciplinas cursadas, onde os pesos são representados pelo número de créditos 
da disciplina;3. Todos os dados em negrito apresentados no formato do histórico devem ser obtidos a partir dos vetores.
*/
#include<stdio.h>
#include<string.h>
#define TAM 5

typedef struct{
	int codigo;
	char ano_Semestre[10];
	float media;
}THistorico;

typedef struct{
	int codigo,creditos;
	char nome[100];
}TDisciplina;

void preencher_historico(THistorico historico[]);
void preencher_disciplina(TDisciplina disciplina[]);
float calcular(THistorico historico[],TDisciplina disciplina[]);
void exibir(THistorico historico[],TDisciplina disciplina[],float cr);

void preencher_historico(THistorico historico[]){
	int i;
	
	for(i=0;i<TAM;i++){
		switch(i){
			case 0: historico[i].codigo = 1001;
					strcpy(historico[i].ano_Semestre,"2021.1");
					historico[i].media = 10;
			break;	
			
			case 1: historico[i].codigo = 1002;
					strcpy(historico[i].ano_Semestre,"2021.1");
					historico[i].media = 6;
				
			break;	
			
			case 2: historico[i].codigo = 1003;
					strcpy(historico[i].ano_Semestre,"2021.1");
					historico[i].media = 8;
				
			break;	
			
			case 3: historico[i].codigo = 1004;
					strcpy(historico[i].ano_Semestre,"2021.1");
					historico[i].media = 10;
				
			break;	
			
			case 4: historico[i].codigo = 1005;
					strcpy(historico[i].ano_Semestre,"2021.1");
					historico[i].media = 7;
				
			break;	
		}
	}
	
}

void preencher_disciplina(TDisciplina disciplina[]){
	int i;
	
	for(i=0;i<TAM;i++){
		switch(i){
			case 0: disciplina[i].codigo = 1001;
					strcpy(disciplina[i].nome,"Fundamentos de Algoritmos Computacionais");
					disciplina[i].creditos = 2;
					
			break;	
			
			case 1: disciplina[i].codigo = 1002;
					strcpy(disciplina[i].nome,"Organizacao de computadores");
					disciplina[i].creditos = 2;
				
			break;	
			
			case 2: disciplina[i].codigo = 1003;
					strcpy(disciplina[i].nome,"Matematica para computacao");
					disciplina[i].creditos = 1;
				
			break;	
			
			case 3: disciplina[i].codigo = 1004;
					strcpy(disciplina[i].nome,"Interface homem maquina");
					disciplina[i].creditos = 1;
				
			break;	
			
			case 4: disciplina[i].codigo = 1005;
					strcpy(disciplina[i].nome,"Matematica basica");
					disciplina[i].creditos = 2;
				
			break;	
		}
	}	
}

float calcular(THistorico historico[],TDisciplina disciplina[]){
	int i;
	float somacr=0,cont=0,cr;
	
	for(i=0;i<TAM;i++){
		somacr += historico[i].media*disciplina[i].creditos;
		cont+=disciplina[i].creditos;
	}
	cr = somacr/cont;
	return cr;
}

void exibir(THistorico historico[],TDisciplina disciplina[],float cr){
	int i;
	
	for(i=0;i<TAM;i++){
		printf("\n%s(%d)\nmedia: %.2f\nCR: %.2f\n",disciplina[i].nome,historico[i].codigo,historico[i].media,cr);
	}
}

void main(){
	THistorico historico[TAM];
	TDisciplina disciplina[TAM];
	int i;
	float resultado;
	
	//preencher vetor1
	preencher_historico(historico);
	printf("\ndados aluno\n");
	for(i=0;i<TAM;i++){
		printf("\ncodigo: %d\nsemestre: %s\nmedia: %.2f\n",historico[i].codigo,historico[i].ano_Semestre,historico[i].media);
	}
	
	//preencher vetor2
	preencher_disciplina(disciplina);
	printf("\ndisciplinas\n");
	for(i=0;i<TAM;i++){
		printf("\ncodigo: %d\nome: %s\ncreditos: %d\n",disciplina[i].codigo,disciplina[i].nome,disciplina[i].creditos);
	}
	
	//obter cr
	resultado = calcular(historico,disciplina);
	printf("\nCR: %2.f\n",resultado);
	
	//exibir tudo
	exibir(historico,disciplina,resultado);
}





