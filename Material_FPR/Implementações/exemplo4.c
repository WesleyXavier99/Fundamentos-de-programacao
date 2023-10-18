/*
	FPR - Professor Leonardo Vianna (2020/1)
	
	Manipulação de arquivos
	
	Exemplo 4: copiando o conteúdo de um arquivo para outro

	Obs: os nomes dos arquivos de origem e de destino são fornecidos pelo usuário.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int copiarArquivo (char origem[], char destino[]);

//main
void main ()
{
	//declaração de variáveis
	char nome1[20], nome2[20];
	
	//lendo os nomes dos dois arquivos
	fflush (stdin);
	printf ("Entre com o nome do arquivo a ser copiado: ");
	gets (nome1);
	
	fflush (stdin);
	printf ("Entre com o nome do novo arquivo: ");
	gets (nome2);
	
	//chamando a função e testando o retorno
	if (copiarArquivo (nome1, nome2) == 0)
	{
		printf ("Erro na abertura de algum arquivo!");
	}
	else
	{
		printf ("Copia realizada com sucesso!");
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
		while (fscanf (arq1, "%c", &caracter) != EOF)
		{
			fprintf (arq2, "%c", caracter);
		}
		
		fclose (arq1);	
		fclose (arq2);
		
		return 1;	
	}		
}

