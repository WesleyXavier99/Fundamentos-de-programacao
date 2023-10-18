#include<stdio.h>


void main()
{
	FILE *file;
	file = fopen("string.txt","r");
	char letras[1000];
	int cont=0;
	int contC=0;
	int i;

	while(fgets(letras,1000,file) != NULL)
	
	for(i=0;letras[i]!= NULL;i++)
	{
		switch(letras[i])
		{
			//vogais
			case 'a' : cont++;
			break;
			
			case 'e' : cont++;
			break;
			
			case 'i' : cont++;
			break;
			
			case 'o' : cont++;
			break;
			
			case 'u' : cont++;
			break;
			
			case 'A' : cont++;
			break;
			
			case 'E' : cont++;
			break;
			
			case 'I' : cont++;
			break;
			
			case 'O' : cont++;
			break;
			
			case 'U' : cont++;
			break;
			
			case ' ' : contC--;
			break;
			
			default : contC++;
		}
	}
	
	printf("\no arquivo tem %d vogais", cont);
	printf("\no arquivo tem %d consoantes", contC);

}
