/*FPR - Aula de 21/09/2020

  Considere a existência de um vetor no qual cada posição pode armazenar o nome do aluno, 
  as notas de AV1 e AV2, sua média e a situação (aprovado, reprovado ou em AVF). Pede-se:

  1. A declaração do vetor, assim como de todos os tipos de dados necessários, caso existam;
  2. Uma função que leia os dados de todos os alunos da turma;
  3. Uma função que calcule a média de cada aluno (e a armazene no vetor), assim como a sua 
     situação;
  4. Uma função que, dado um número inteiro (1-aprovado;2-reprovado;3-em AVF), exiba todos 
     os alunos que estão nesta situação;
  5. Uma função que determine o aluno de maior média.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//declaração de constantes
#define NUMALUNOS 3

//declaração de tipos
typedef struct {
	char nome[30];
	float av1, av2, media;
	char situacao[10];
} TAluno;

//protótipos das funções
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
	//declaração de variáveis
	TAluno turma[NUMALUNOS];
	int aluno;
	
	//leitura dos dados dos alunos
	leituraDados (turma, NUMALUNOS);

	//calculando a média e a situação de cada aluno	
	calcularMediaSituacao (turma, NUMALUNOS);
	
	//exibindo os dados de todos os alunos
	exibirTurma (turma, NUMALUNOS);
	
	//exibindo os alunos por situação
	exibirPorSituacao (turma, NUMALUNOS, 1);
	exibirPorSituacao (turma, NUMALUNOS, 2);
	exibirPorSituacao (turma, NUMALUNOS, 3);
	
	//exibindo os dados do aluno de maior media
	printf ("\nDados do aluno de maior media:\n");
	aluno = maiorMedia (turma, NUMALUNOS);
	exibirAluno (turma[aluno]);
	
	//exibirAluno (turma[maiorMedia(turma, NUMALUNOS)]);
}

//implementações das funções
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
		
		//determinando a situação do aluno
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

//exibindo os alunos por situação (sit 1: aprovado; 2: reprovado; 3: em AVF)
void exibirPorSituacao (TAluno t[], int quant, int sit)
{
	int i;
	char str[10];
	
	//transformando a "situação inteira" em "situação string"
	determinaSituacao (sit, str);
	
	printf ("Situacao dos alunos: %s\n", str);
	
	//buscando no vetor os alunos com situação igual a 'str'
	for (i=0;i<quant;i++)
	{
		if (strcmp(t[i].situacao, str) == 0)
		{
			exibirAluno (t[i]);
		}
	}	
}

//dado um código (1, 2 ou 3), retorna em 'situacao' aprovado, reprovado ou em AVF, respectivamente
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
