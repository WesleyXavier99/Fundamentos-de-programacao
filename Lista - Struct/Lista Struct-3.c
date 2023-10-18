//Construa uma estrutura aluno com nome, n´umero de matr´ýcula e curso. Leia do usu´ ario
//a informac¸ ˜ao de 5 alunos, armazene em vetor dessa estrutura e imprima os dados na
//tela.
#include<stdio.h>

struct Aluno{
	char Nome[30];
	int Matricula;
	char Curso[20];
};

void main ()
{
	struct Aluno informacoes[5];
	int i;
	
	for(i=0;i<5;++i)
	{
		printf("Digite o nome : \n");
		gets(informacoes[i].Nome);
		
		fflush(stdin);
		printf("Digite a matricula : \n");
		scanf("%d",&informacoes[i].Matricula);
		
		fflush(stdin);
		printf("Digite o curso : \n");
		gets(informacoes[i].Curso);	
	}
	
	for(i=0;i<5;++i)
	{
		printf("\naluno : %s\nmatricula : %d \ncurso: %s\n\n",informacoes[i].Nome,informacoes[i].Matricula,informacoes[i].Curso);
	}
}
