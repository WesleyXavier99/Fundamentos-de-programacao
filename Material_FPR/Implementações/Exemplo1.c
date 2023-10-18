/*
	FPR - Professor Leonardo Vianna (2020/1)
	
	Manipulação de arquivos
	
	Exemplo 1: criando um arquivo e armazenando no mesmo os números de 1 a N.
	
	Obs: o nome do arquivo e o valor de N são fornecidos pelo usuário.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int criaArquivo (char nome[], int n);

//main
void main ()
{
	//declaração de variáveis
	char nomeArq[50];
	int numero, retorno;
	
	//lendo o nome do arquivo
	fflush (stdin);
	printf ("Entre com o nome do arquivo: ");
	gets (nomeArq);
	
	//lendo o valor de N
	printf ("Entre com o limite superior do intervalo a ser inserido no arquivo: ");
	scanf ("%d", &numero);
	
	//chamando a função e testando o retorno
	retorno = criaArquivo (nomeArq, numero);
	
	if (retorno == 0)
	{
		printf ("Erro na criacao do arquivo!");
	}
	else
	{
		printf ("Arquivo criado com sucesso!");
	}
}

//implementação das funções

/*
 Cria um arquivo chamado 'nome' com os valores de 1 a 'N'
 Retorna 1 se conseguir criar o arquivo e 0, caso contrário.
*/
int criaArquivo (char nome[], int n)
{
	FILE *arq;  	//declarando o arquivo
	int i;
	
	//abrindo o arquivo para escrita
	arq = fopen (nome, "w"); 
	
	//testando se houve sucesso na abertura do arquivo
	if (arq == NULL)
	{
		return 0;
	}
	else
	{
		for (i=1;i<=n;i++)
		{
			fprintf (arq, "%d\n", i);
		}
		
		fclose (arq);		
		
		return 1;
	}
}
