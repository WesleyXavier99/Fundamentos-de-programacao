/*
	FPR - Professor Leonardo Vianna (2020/1)
	
	Manipulação de arquivos
	
	Exemplo 3: lendo o conteúdo de um arquivo (sem saber a sua estrutura interna) e 
	           exibindo-o na tela

	Obs: o nome do arquivo é fornecido pelo usuário.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int exibeArquivo (char nome[]);

//main
void main ()
{
	//declaração de variáveis
	char nomeArq[50];
	int retorno;
	
	//lendo o nome do arquivo
	fflush (stdin);
	printf ("Entre com o nome do arquivo: ");
	gets (nomeArq);
		
	//chamando a função e testando o retorno
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

//implementação das funções

/*
 Exibe o conteúdo do arquivo 'nome'
 Caso algum erro ocorra, retorna 0; caso contrário, 1.
*/
int exibeArquivo (char nome[])
{
	FILE *arq;  //declarando o arquivo
	char caracter;
	
	arq = fopen (nome, "r");   //abrindo o arquivo para leitura
	
	if (arq == NULL)
	{
		return 0;
	}
	else
	{
		while (fscanf(arq, "%c", &caracter) != EOF)
		{
			printf ("%c", caracter);
		}
		
		fclose (arq);
		
		return 1;		
	}
}
