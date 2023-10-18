#include<stdio.h>

void main()
{
	FILE *file;
	file = fopen("AprendendoArquivo2.txt","w");
	fprintf(file,"Texto a ser digitado no meu arquivo.");
	fclose(file);
}
