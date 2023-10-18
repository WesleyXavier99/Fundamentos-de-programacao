//Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve
//conter a matr´ýcula do aluno, nome, nota da primeira prova, nota da segunda prova e nota
//da terceira prova.
//(a) Permita ao usu´ ario entrar com os dados de 5 alunos.
//(b) Encontre o aluno com maior nota da primeira prova.
//(c) Encontre o aluno com maior m´edia geral.
//(d) Encontre o aluno com menor m´edia geral
//(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para
//aprovac¸ ˜ao.

#include<stdio.h>
#include<string.h>

struct Dados_Aluno {
	int Matricula;
	char Nome[40];
	float nota1;
	float nota2;
	float nota3;
	float media;
};

void main()
{
	int i;
	struct Dados_Aluno informacoes[5];
	float Maior_Nota1=0;
	float Maior_Media=0;
	float Menor_Media=9999999;
	char Aluno_Maior_Nota1[40];
	char Aluno_Maior_Media[40];
	char Aluno_Menor_Media[40];
	
	for(i=0;i<3;i++)
	{
		printf("Digite a Matricula \n");
		scanf("%d",&informacoes[i].Matricula);
		
		fflush(stdin);
		printf("Digite o Nome do aluno : \n");
		gets(informacoes[i].Nome);
		
		fflush(stdin);
		printf("Digite a primeira nota: \n");
		scanf("%f",&informacoes[i].nota1);
		
		printf("Digite a segunda nota: \n");
		scanf("%f",&informacoes[i].nota2);
		
		printf("Digite a terceira nota : \n");
		scanf("%f",&informacoes[i].nota3);
		
		informacoes[i].media=(informacoes[i].nota1 + informacoes[i].nota2 +  informacoes[i].nota1)/3;
	}
	
	for(i=0;i<3;i++)
	{
		if(informacoes[i].nota1 > Maior_Nota1)
		{
			Maior_Nota1 = informacoes[i].nota1;
			strcpy(Aluno_Maior_Nota1,informacoes[i].Nome);
		}
		
		if(informacoes[i].media > Maior_Media)
		{
			Maior_Media= informacoes[i].media;
			strcpy(Aluno_Maior_Media,informacoes[i].Nome);
		}
		
		if(informacoes[i].media < Menor_Media)
		{
			Menor_Media= informacoes[i].media;
			strcpy(Aluno_Menor_Media,informacoes[i].Nome);
		}
		
		if(informacoes[i].media>=6)
		{
			printf("\nAluno(a) %s esta aprovado",informacoes[i].Nome);
		}else{
			printf("\nAluno(a) %s esta reprovado",informacoes[i].Nome);
		}
	}
	
	printf("\nO aluno com maior nota da primeira prova e : %s",Aluno_Maior_Nota1);
	
	printf("\nO aluno com maior media geral e : %s",Aluno_Maior_Media);
	
	printf("\nO aluno com menor media geral e : %s",Aluno_Menor_Media);
	
	for(i=0;i<3;i++)
	{
		printf("\nAluno : %s, media : %.3f",informacoes[i].Nome,informacoes[i].media);
	}
	
}
