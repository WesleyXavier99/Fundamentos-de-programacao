/*QUEST�O 02:
Desenvolver uma fun��o que, dada uma matriz
M15�20, determine se um n�mero X se encontra
na linha L da matriz.*/

//declara��o de constantes
#define L 15
#define C 20

//importa��o de bibliotecas
#include <stdio.h>
#include <time.h>

//fun��es
int buscar (float m[L][C], float valor, int linha);
void preencher (float m[L][C]);
void exibir (float m[L][C]);

void main ()
{
	float mat[L][C], numero;
	int lin, ret; 
	
	
	preencher (mat);	//preenchendo a matriz aleatoriamente
	
	//exibindo a matriz 
	printf ("Matriz:\n\n");
	exibir (mat);

	
	//obtendo os dados de entrada
	printf ("\n\nEntre com o numero a ser buscado: ");
	scanf ("%f", &numero);
	
	printf ("Em que linha deseja buscar? ");
	scanf ("%d", &lin);
	
	//chamando a fun��o de busca
	ret = buscar (mat, numero, lin);
	
	//verifixando o retorno da fun��o
	if (ret == 1)
	{
		printf ("O valor %.1f foi encontrado na linha %d da matriz", numero, lin);
	}
	else
	{
		printf ("O valor %.1f nao foi encontrado na linha %d da matriz", numero, lin);
	}
}

//implementa��o das fun��es
int buscar (float m[L][C], float valor, int linha)
{
/*	int i, j;
	
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			if (i == linha)
			{
				if (m[i][j] == valor)
				{
					return 1;
				}
			}
		}
	}
	
	return 0;*/

	int j;
	
	for (j=0;j<C;j++)
	{
		if (m[linha][j] == valor)
		{
			return 1;
		}
	}
	
	return 0;
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

//exibir a matriz 
void exibir (float m[L][C])
{
	int i, j;
	
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			printf ("%.1f  ", m[i][j]);
		}
		printf ("\n");
	}
}
