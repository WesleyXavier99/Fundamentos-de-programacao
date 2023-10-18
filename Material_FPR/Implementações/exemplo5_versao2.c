/*
	FPR - Professor Leonardo Vianna (2020/1)
	
	Manipulação de arquivos
	
	Exemplo 5: removendo todas as ocorrências de um número em determinado arquivo.

	Obs: o nome do arquivo e o número a ser removido são fornecidos pelo usuário.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int copiarArquivo (char origem[], char destino[]);
int remover (char nomeArq[], int numero);

//main
int main ()
{
	//declaraçãpo de variáveis
	char nome[20];
	int numero, quant;
	
	//lendo o nome do arquivo
	fflush (stdin);
	printf ("Entre com o nome do arquivo: ");
	gets (nome);
	
	//lendo o valor a ser removido do arquivo
	printf ("Entre com o numero a ser removido: ");
	scanf ("%d", &numero);
	
	//chamando a função e testando o retorno
	quant = remover (nome, numero);
	
	if (quant < 0)
	{
		printf ("Erro na abertura do arquivo!");
	}
	else
	{
		printf ("Foram removidas %d ocorrências de %d", quant, numero);
	}
}


//implementação das funções

/*
 Copia o conteúdo do arquivo 'origem' para o arquivo 'destino'
 Retorna 1 se a cópia for realizada com sucesso e 0, caso contrário.
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
 Remove todas as ocorrências de 'numero' no arquivo 'nomeArq'. Além disto, retorna a
 quantidade de remoções realizadas.
*/
int remover (char nomeArq[], int numero)
{
	FILE *arq, *tmp; 		//cria-se um arquico temporário para ajudar na remoção
	int num, cont=0;

	arq = fopen (nomeArq, "r");   
	tmp = fopen ("temp.txt", "w");
	
	if ((!arq) || (!tmp))
	{
		return -1;
	}
	else
	{
		//copiando para 'temp.txt' todos os números diferentes daquele que se deseja remover
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
		
		//copiando o conteúdo de 'temp.txt' para o arquivo original
		copiarArquivo ("temp.txt", nomeArq);
		
		//===> APAGANDO O ARQUIVO TEMPORÁRIO
		remove ("temp.txt");
		
		return cont;	
	}		
}
