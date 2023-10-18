#include<stdio.h>


void main()
{
	FILE *file;
	file = fopen("string.txt","r");
	char frase[100];
	
	if( file==NULL )
	{
		printf("Nao foi possivel abrir o arquivo");
	}else{
		while(fgets(frase,100,file) != NULL)
		{
			printf("%s",frase);
		}
	}
	fclose(file);
	
	//printf("%s",frase);
}
