/*Quest�o 03: Desenvolver uma fun��o que, dada uma string s, crie uma substring que inicie na posi��o p de s  e contenha n caracteres. 
Observa��es: se p e/ou n forem inv�lidos, a substring ser� vazia; 
ii) se s n�o possuir n caracteres al�m de p, a substring a ser criada come�ar� em p e terminar� no final de s.*/

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
