#include<stdio.h>
typedef struct Lista {
	char cpf[15];
	char nome[30];
	char sexo[2];
	char estado[4];
	char municipio[30];
	struct Lista *prox;
}Lista;

Lista *Topo = NULL;

int carregar(FILE *arq)
{
	char aux[1000],cpf[15],nome[100],sexo[2],estado[5],municipio[30];
	int cont = 0,i,j=0;
	
	//passar do arquivo pra string
	while (fgets(aux,1000,arq) != NULL);
	
	printf("%s",aux);
	
	
	//passando da string pra substring
	for(i=0;aux[i]!='\0';i++)
	{
		if(aux[i]==';')
		{
			cont++;
			j=0;
		}else{
			switch(cont)
			{
				case 0 : cpf[j] = aux[i];j++;
				break;
				
				case 1 : nome[j] = aux[i];j++;
				break;
				
				case 2 : sexo[j] = aux[i];j++;
				break;
				
				case 3 : estado[j] = aux[i];j++;
				break;
				
				case 4 : municipio[j] = aux[i];j++;
			}
		}
			
	}
	
//	printf("\n");
//		puts(cpf);
//		puts(nome);
//		puts(sexo);
//		puts(estado);
//		puts(municipio);
	
	
	
	
	//passando da string pra struct
//	for(i=0;aux[i]!=NULL;i++)
//	{
//		Lista *nova = malloc(sizeof(Lista));
//		nova->cpf = 
//	}
}

void main()
{
	FILE *arq = fopen("arqQ4.txt","r+");
	int N_Linhas;
	
	N_Linhas = carregar(arq);
}
