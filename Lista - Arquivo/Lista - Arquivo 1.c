#include<stdio.h>


void main()
{
	FILE *file;
	file = fopen("Arq.txt","w");
	char letra[100];
	char aux[100];
	char letras;
	int i=0;
	
	do{
		//lendo os caracteres
		printf("Digite um caractere: ");
		fflush(stdin);
		scanf("%c",&letras);
		//passar os caracteres pra uma string
		if(letras!= '0')
		{
			letra[i]=letras;
		}
		i++;
	}while(letras!='0');
	
	//copiando da string pro arquivo
	fputs(letra,file);
	
	//exibir string
	//printf("%s",letra);
	
//	while(fgets(aux,100,file) != NULL);
//	fputs(aux,file);
	
}
