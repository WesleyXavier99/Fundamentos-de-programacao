//Implemente um programa que leia o nome, a idade e o enderec¸o de uma pessoa e
//armazene os dados em uma estrutura.
#include<stdio.h>

struct Dados{
	char Nome[30];
	int Idade;
	char Endereco[50];
};

void main()
{
	struct Dados nome;
	struct Dados idade;
	struct Dados endereco;
	
	printf("Digite o nome\n");
	gets(nome.Nome);
	
	fflush(stdin);
	printf("Digite a idade\n");
	scanf("%d",&idade.Idade);
	
	fflush(stdin);
	printf("Digite o endereco\n");
	gets(endereco.Endereco);
	
	printf("Nome : %s",nome.Nome);
	printf("\nIdade : %d",idade.Idade);
	printf("\nEndereco : %s",endereco.Endereco);
}
