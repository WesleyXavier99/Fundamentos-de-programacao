/*Questão 03: Desenvolver uma função que, dada uma string s, crie uma substring que inicie na posição p de s  e contenha n caracteres. 
Observações: se p e/ou n forem inválidos, a substring será vazia; 
ii) se s não possuir n caracteres além de p, a substring a ser criada começará em p e terminará no final de s.*/

#include<stdio.h>
#include<string.h>

void CriarSubstring(char palavra[],int p,int n);
void main()
{
	int p,n;
	char palavra[30];
	
	printf("Digite uma string:\n");
	gets(palavra);
	
	printf("Digite um numero para iniciar a nova substring:\n");
	scanf("%d",&p);
	
	printf("Digite um numero para fnalizar a substring:\n");
	scanf("%d",&n);
	
	CriarSubstring(palavra,p,n);
	
} 

void CriarSubstring(char palavra[],int p,int n)
{
	int i,j;
	char substring[30];
	
	if(p>strlen(palavra-1)){
		printf("String invalida\n");
	}else{
		for(i=p,j=0;i<strlen(palavra)-1,j<n;i++,j++)
		{
			substring[j]=palavra[i];
			
		}
		substring[j]='\0';
		
		printf("%s",substring);
		}
		
	
}
