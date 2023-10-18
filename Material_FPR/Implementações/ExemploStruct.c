/*FPR - Aula de 21/09/2020

  Considere a exist�ncia de um vetor no qual cada posi��o pode armazenar o nome do aluno, 
  as notas de AV1 e AV2, sua m�dia e a situa��o (aprovado, reprovado ou em AVF). Pede-se:

  1. A declara��o do vetor, assim como de todos os tipos de dados necess�rios, caso existam;
  2. Uma fun��o que leia os dados de todos os alunos da turma;
  3. Uma fun��o que calcule a m�dia de cada aluno (e a armazene no vetor), assim como a sua 
     situa��o;
  4. Uma fun��o que, dado um n�mero inteiro (1-aprovado;2-reprovado;3-em AVF), exiba todos 
     os alunos que est�o nesta situa��o;
  5. Uma fun��o que determine o aluno de maior m�dia.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//declara��o de constantes
#define NUMALUNOS 3

//declara��o de tipos
typedef struct {
	char nome[30];
	float av1, av2, media;
	char situacao[10];
} TAluno;

//prot�tipos das fun��es
void leituraDados (TAluno t[], int quant);
void calcularMediaSituacao (TAluno t[], int quant);
void exibirAluno (TAluno a);
void exibirTurma (TAluno t[], int quant);
void exibirPorSituacao (TAluno t[], int quant, int sit);
void determinaSituacao (int cod, char situacao[]);
int maiorMedia (TAluno t[], int quant);

//main
void main ()
{
	//declara��o de vari�veis
	TAluno turma[NUMALUNOS];
	int aluno;
	
	//leitura dos dados dos alunos
	leituraDados (turma, NUMALUNOS);

	//calculando a m�dia e a situa��o de cada aluno	
	calcularMediaSituacao (turma, NUMALUNOS);
	
	//exibindo os dados de todos os alunos
	exibirTurma (turma, NUMALUNOS);
	
	//exibindo os alunos por situa��o
	exibirPorSituacao (turma, NUMALUNOS, 1);
	exibirPorSituacao (turma, NUMALUNOS, 2);
	exibirPorSituacao (turma, NUMALUNOS, 3);
	
	//exibindo os dados do aluno de maior media
	printf ("\nDados do aluno de maior media:\n");
	aluno = maiorMedia (turma, NUMALUNOS);
	exibirAluno (turma[aluno]);
	
	//exibirAluno (turma[maiorMedia(turma, NUMALUNOS)]);
}

//implementa��es das fun��es
void leituraDados (TAluno t[], int quant)
{
	int i;
	
	for (i=0;i<quant;i++)
	{
		printf ("Dados do %do. aluno:\n", i+1);
		
		fflush (stdin);
		printf ("\tNome: ");
		gets (t[i].nome);
		
		printf ("\tAV1: ");
		scanf ("%f", &t[i].av1);
				
		printf ("\tAV2: ");
		scanf ("%f", &t[i].av2);
		
		printf ("\n");		
	}
}

void calcularMediaSituacao (TAluno t[], int quant)
{
	int i;
	
	for (i=0;i<quant;i++)
	{
		t[i].media = (t[i].av1+t[i].av2)/2;
		
		//determinando a situa��o do aluno
		if (t[i].media >= 6)
		{
			strcpy (t[i].situacao, "APROVADO");
		}
		else
		{
			if (t[i].media < 4)
			{
				strcpy (t[i].situacao, "REPROVADO");
			}
			else
			{
				strcpy (t[i].situacao, "AVF");
			}
		}
	}
}

//exibe os dados de um aluno
void exibirAluno (TAluno a)
{
	printf ("Nome: %s\n", a.nome);
	printf ("AV1 = %.1f - AV2 = %.1f  -->  Media = %.1f (%s)\n\n", a.av1, a.av2, a.media, a.situacao);
}

//exibe os dados de uma turma inteira
void exibirTurma (TAluno t[], int quant)
{
	int i;
	
	for (i=0;i<quant;i++)
	{
		exibirAluno (t[i]);
	}
}

//exibindo os alunos por situa��o (sit 1: aprovado; 2: reprovado; 3: em AVF)
void exibirPorSituacao (TAluno t[], int quant, int sit)
{
	int i;
	char str[10];
	
	//transformando a "situa��o inteira" em "situa��o string"
	determinaSituacao (sit, str);
	
	printf ("Situacao dos alunos: %s\n", str);
	
	//buscando no vetor os alunos com situa��o igual a 'str'
	for (i=0;i<quant;i++)
	{
		if (strcmp(t[i].situacao, str) == 0)
		{
			exibirAluno (t[i]);
		}
	}	
}

//dado um c�digo (1, 2 ou 3), retorna em 'situacao' aprovado, reprovado ou em AVF, respectivamente
void determinaSituacao (int cod, char situacao[])
{
	switch (cod)
	{
		case 1: strcpy (situacao, "APROVADO");
		        break;
		        
		case 2: strcpy (situacao, "REPROVADO");
		        break;
		        
		case 3: strcpy (situacao, "AVF");
		        break;
	}
	
	
/*	if (cod == 1)
	{
		strcpy (situacao, "APROVADO");
	}
	else
	{
		if (cod == 2)
		{
			strcpy (situacao, "REPROVADO");
		}
		else
		{
			strcpy (situacao, "AVF");
		}
	}
*/
}

int maiorMedia (TAluno t[], int quant)
{
	float maior = t[0].media;
	int i, aluno = 0;
	
	for (i=1;i<quant;i++)
	{
		if (t[i].media > maior)
		{
			maior = t[i].media;
			aluno = i;
		}
	}
	
	return aluno;
}
