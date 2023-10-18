//Fac¸a um programa que armazene em um registro de dados (estrutura composta) os dados
//de um funcion´ ario de uma empresa, compostos de: Nome, Idade, Sexo (M/F), CPF,
//Data de Nascimento, C´odigo do Setor onde trabalha (0-99), Cargo que ocupa (string de
//at ´e 30 caracteres) e Sal´ ario. Os dados devem ser digitados pelo usu´ ario, armazenados
//na estrutura e exibidos na tela.
#include<stdio.h>

struct Funcionario {
	int idade;
	int Cpf;
	int Cod_Setor;
	float Salario;
	char Nome[50];
	char Data_Nascimento[20];
	char Cargo[30];
	char Sexo;
};

void main()
{
	struct Funcionario Dados[10];
	int i;
	
	for(i=0;i<1;++i)
	{
		fflush(stdin);
		printf("Digite o nome :\n");
		gets(Dados[i].Nome);
		
		printf("Digite o cpf :\n");
		scanf("%d",&Dados[i].Cpf);
		
		printf("Digite a idade :\n");
		scanf("%d",&Dados[i].idade);
		
		fflush(stdin);
		printf("Digite o sexo :\n ");
		scanf("%c",&Dados[i].Sexo);
		
		fflush(stdin);
		printf("Digite a data de nascimento :\n");
		gets(Dados[i].Data_Nascimento);
		
		printf("Digite o codigo do setor :\n");
		scanf("%d",&Dados[i].Cod_Setor);
		
		fflush(stdin);
		printf("Digite o cargo :\n");
		gets(Dados[i].Cargo);
		
		printf("Digite o salario :\n");
		scanf("%f",&Dados[i].Salario);
	}
	
	for(i=0;i<1;++i)
	{
		printf("Nome : %s \nIdade : %d \nSexo : %c \nCPF : %d \nData de nascimento : %s \nCodigo do setor : %d \nSalario : %.4f",Dados[i].Nome,Dados[i].idade,Dados[i].Sexo,Dados[i].Cpf,Dados[i].Data_Nascimento,Dados[i].Cod_Setor,Dados[i].Salario);
	}
}
