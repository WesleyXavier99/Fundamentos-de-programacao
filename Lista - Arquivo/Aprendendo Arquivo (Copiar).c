#include<stdio.h>


int main()
{
	FILE *file1;
	file1 = fopen("string.txt","r");
	FILE *file2;
	file2 = fopen("string2.txt","w");
	
	if(file1 == NULL)
	{
		printf("Nao foi possivel abrir o arquivo\n");
		return 1;
	}
	
	Copiar_Conteudo(file1,file2);
	
	fclose(file1);
	fclose(file2);
	
}

void Copiar_Conteudo (FILE *file1,FILE *file2)
{
	char leitor[1000];
	
	while(fgets(leitor,1000,file1) != NULL)
	//escrever da string pro arquivo
	fputs(leitor,file2);
	
	puts(leitor);
}
