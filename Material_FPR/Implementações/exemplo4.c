/*
	FPR - Professor Leonardo Vianna (2020/1)
	
	Manipula��o de arquivos
	
	Exemplo 4: copiando o conte�do de um arquivo para outro

	Obs: os nomes dos arquivos de origem e de destino s�o fornecidos pelo usu�rio.
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int copiarArquivo (char origem[], char destino[]);

//main
void main ()
{
	//declara��o de vari�veis
	char nome1[20], nome2[20];
	
	//lendo os nomes dos dois arquivos
	fflush (stdin);
	printf ("Entre com o nome do arquivo a ser copiado: ");
	gets (nome1);
	
	fflush (stdin);
	printf ("Entre com o nome do novo arquivo: ");
	gets (nome2);
	
	//chamando a fun��o e testando o retorno
	if (copiarArquivo (nome1, nome2) == 0)
	{
		printf ("Erro na abertura de algum arquivo!");
	}
	else
	{
		printf ("Copia realizada com sucesso!");
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
		while (fscanf (arq1, "%c", &caracter) != EOF)
		{
			fprintf (arq2, "%c", caracter);
		}
		
		fclose (arq1);	
		fclose (arq2);
		
		return 1;	
	}		
}

