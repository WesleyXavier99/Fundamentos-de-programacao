/*QUESTÃO 01:
Faça um função que, dada uma matriz M8×5 de
reais, gere a matriz Mt, sua transposta.*/

//declaração de constantes
#define L 8
#define C 5

//importação de bibliotecas
#include <stdio.h>
#include <time.h>

//funções
void transposta (float m[L][C], float t[C][L]);
void preencher (float m[L][C]);
void exibir_orig (float m[L][C]);
void exibir_transp (float m[C][L]);

void main ()
{
	float mat[L][C], 	//matriz original
	      transp[C][L]; //matriz transposta
	
	preencher (mat);	//preenchendo a matriz original aleatoriamente
	
	transposta (mat, transp);  //gerando a matriz transposta
	

	//exibindo a matriz original
	printf ("Matriz original:\n\n");
	exibir_orig (mat);
	
	//exibindo a matriz transposta
	printf ("\n\nMatriz transposta:\n\n");
	exibir_transp (transp);
}

//implementação das funções
void transposta (float m[L][C], float t[C][L])
{
	int i, j;
	
	for (i=0;i<C;i++)
	{
		for (j=0;j<L;j++)
		{
			t[i][j] = m[j][i];
		}
	}
}

void preencher (float m[L][C])
{
	int i, j;
	
	srand (time(NULL));
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			m[i][j] = 1 + rand () % 10;  //1..10
		}
	}	
}

//exibir a matriz transposta
void exibir_orig (float m[L][C])
{
	int i, j;
	
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			printf ("%.1f ", m[i][j]);
		}
		printf ("\n");
	}
}

void exibir_transp (float m[C][L])
{
	int i, j;
	
	for (i=0;i<C;i++)
	{
		for (j=0;j<L;j++)
		{
			printf ("%.1f ", m[i][j]);
		}
		printf ("\n");
	}
}
