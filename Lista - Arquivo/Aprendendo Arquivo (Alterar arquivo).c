#include<stdio.h>


void main()
{
	FILE *file;
	file = fopen("string.txt","a");
	char frase[] = "Segunda linha\n";
	char caractere = 'A';
	
	if(file== NULL)
	{
		printf("Nao foi possivel abrir o arquivo\n");
	}else{
		//adicionar uma string ao arquivo
		fprintf(file,"Primeira linha\n");
		
		//adicionar uma string ao arquivo
		fputs(frase,file);
		
		//adicionar um char ao arquivo
		fputc(caractere,file);
		fclose(file);
	}
}
