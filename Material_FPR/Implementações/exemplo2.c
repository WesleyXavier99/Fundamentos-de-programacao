/*
	FPR - Professor Leonardo Vianna (2020/1)
	
	Manipula��o de arquivos
	
	Exemplo 2: lendo o conte�do de um arquivo, sabendo que o mesmo possui n�meros 
	           inteiros, um por linha, e exibindo-o na tela

	Obs: o nome do arquivo � fornecido pelo usu�rio.
*/
//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int exibeArquivo (char nome[]);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeArq[50];
	int retorno;
	
	//lendo o nome do arquivo
	fflush (stdin);
	printf ("Entre com o nome do arquivo: ");
	gets (nomeArq);
		
	//chamando a fun��o e testando o retorno
	retorno = exibeArquivo (nomeArq);
	
	if (retorno == 0)
	{
		printf ("Erro na leitura do arquivo!");
	}
	else
	{
		printf ("\n\nOperacao realizada com sucesso!");
	}
}

//implementa��o das fun��es

/*
 Exibe o conte�do do arquivo 'nome'
 Caso algum erro ocorra, retorna 0; caso contr�rio, 1.
*/
int exibeArquivo (char nome[])
{
	FILE *arq;  //declarando o arquivo
	int numero;
	
	arq = fopen (nome, "r");   //abrindo o arquivo para leitura
	
	if (arq == NULL)
	{
		return 0;
	}
	else
	{
		//lendo o arquivo at� se chegar ao final do arquivo
		while (fscanf(arq, "%d", &numero) != EOF)
		{
			printf ("%d\t", numero);
		}
		
		fclose (arq);
		
		return 1;		
	}
}
