#include<stdio.h>


void main()
{
	FILE *file;
	file = fopen("string.txt","r");
	char frase[1000];
	int cont=0;
	
	if(file == NULL)
	{
		printf("nao foi possivel abrir o arquivo\n");
	}else{
		while(fgets(frase,1000,file)!=NULL)
		{
			cont++;
		}
	}
	printf("\nO arquivo possui %d linhas",cont);
}
