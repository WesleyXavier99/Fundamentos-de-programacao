/*
	FPR - Professor Leonardo Vianna (2020/1)
	
	Manipula��o de arquivos
	
	Exemplo 5: removendo todas as ocorr�ncias de um n�mero em determinado arquivo.

	Obs: o nome do arquivo e o n�mero a ser removido s�o fornecidos pelo usu�rio.
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int copiarArquivo (char origem[], char destino[]);
int remover (char nomeArq[], int numero);

//main
int main ()
{
	//declara��po de vari�veis
	char nome[20];
	int numero, quant;
	
	//lendo o nome do arquivo
	fflush (stdin);
	printf ("Entre com o nome do arquivo: ");
	gets (nome);
	
	//lendo o valor a ser removido do arquivo
	printf ("Entre com o numero a ser removido: ");
	scanf ("%d", &numero);
	
	//chamando a fun��o e testando o retorno
	quant = remover (nome, numero);
	
	if (quant < 0)
	{
		printf ("Erro na abertura do arquivo!");
	}
	else
	{
		printf ("Foram removidas %d ocorr�ncias de %d", quant, numero);
	}
}


//implementa��o das fun��es

/*
 Copia o conte�do do arquivo 'origem' para o arquivo 'destino'
 Retorna 1 se a c�pia for realizada com sucesso e 0, caso contr�rio.
*/
int copiarArquivo (char origem[], char destino[])
{
	FILE *arq1, *arq2; 
	char caracter;

	arq1 = fopen (origem, "r");   
	arq2 = fopen (destino, "w");   
	
	//if ((arq1 == NULL) || (arq2 == NULL))
	if ((!arq1) || (!arq2))
	{
		return 0;
	}
	else
	{
		while (!feof(arq1))
		{
			fscanf (arq1, "%c", &caracter);
			fprintf (arq2, "%c", caracter);
		}
		
		fclose (arq1);	
		fclose (arq2);
		
		return 1;	
	}		
}

/*
 Remove todas as ocorr�ncias de 'numero' no arquivo 'nomeArq'. Al�m disto, retorna a
 quantidade de remo��es realizadas.
*/
int remover (char nomeArq[], int numero)
{
	FILE *arq, *tmp; 		//cria-se um arquico tempor�rio para ajudar na remo��o
	int num, cont=0;

	arq = fopen (nomeArq, "r");   
	tmp = fopen ("temp.txt", "w");
	
	if ((!arq) || (!tmp))
	{
		return -1;
	}
	else
	{
		//copiando para 'temp.txt' todos os n�meros diferentes daquele que se deseja remover
		while (!feof(arq))
		{
			fscanf (arq, "%d\n", &num);
			if (num != numero)
			{
				fprintf (tmp, "%d\n", num);
			}
			else
			{
				cont++;
			}
		}
		
		fclose (arq);	
		fclose (tmp);
		
		//copiando o conte�do de 'temp.txt' para o arquivo original
		copiarArquivo ("temp.txt", nomeArq);
		
		//===> APAGANDO O ARQUIVO TEMPOR�RIO
		remove ("temp.txt");
		
		return cont;	
	}		
}
