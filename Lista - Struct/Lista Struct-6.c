//Fac¸a um programa que realize a leitura dos seguintes dados relativos a um conjunto de
//alunos: Matricula, Nome, C´odigo da Disciplina, Nota1 e Nota2. Considere uma turma de
//at ´e 10 alunos. Ap´os ler todos os dados digitados, e depois de armazen´ a-los em um vetor
//de estrutura, exibir na tela a listagem final dos alunos com as suas respectivas m´edias
//finais (use uma m´edia ponderada: Nota1 com peso=1.0 e Nota2 com peso=2.0).
#include<stdio.h>

struct Dados_Alunos {
	int Matricula;
	char Nome[50];
	int Codigo_Disciplina;
	float Nota1;
	float Nota2;
	float Media;
};

void main()
{
	struct Dados_Alunos informacoes[3];
	int i;
	
	for(i=0;i<3;++i)
	{
		printf("Digite a Matricula \n");
		scanf("%d",&informacoes[i].Matricula);
		
		fflush(stdin);
		printf("Digite o Nome do aluno : \n");
		gets(informacoes[i].Nome);
		
		printf("Digite o Codigo da disciplina : \n");
		scanf("%d",&informacoes[i].Codigo_Disciplina);
		
		printf("Digite a primeira nota: \n");
		scanf("%f",&informacoes[i].Nota1);
		
		printf("Digite a segunda nota: \n");
		scanf("%f",&informacoes[i].Nota2);
		
		informacoes[i].Media= ((informacoes[i].Nota1 * 1) + (informacoes[i].Nota2 * 2))/ (1 + 2);
	}
	
	for(i=0;i<3;++i)
	{
		printf("Aluno(a): %s\nMedia: %f",informacoes[i].Nome,informacoes[i].Media);
	}
}
