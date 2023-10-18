//pilha estatica
#include<stdio.h>
#define MAXTAM 1000

int Pilha[MAXTAM];
int Topo;

void Pilha_Construtor ()
{
	Topo = -1;
}

int Pilha_Vazia()
{
	if(Topo==-1)
	{
		return 1;
	}else{
		return 0;
	}
	//return Topo==-1;
}

int Pilha_Cheia()
{
	if(Topo==MAXTAM-1)
	{
		return 1;
	}else{
		return 0;
	}
}

int Pilha_Push(int valor)//empilhar
{
	if(Pilha_Cheia()==1)
	{
		return 1;
	}else{
		Topo++;
		Pilha[Topo]=valor;
		return 0;
	}
}

int Pilha_Pop(int *valor)//desempilhar
{
	if(Pilha_Vazia()==1)
	{
		return 1;
	}else{
		*(valor) = Pilha[Topo];
		Topo--;
		return 0;
	}
}

int Pilha_Consulta(int *valor)//get = consulta o valor que esta no topo
{
	if(Pilha_Vazia()==1)
	{
		return 1;
	}else{
		*(valor) = Pilha[Topo];
		return 0;
	}
}

int Pilha_Tamanho()
{
	return Topo+1;
}

void main()
{
	int valor;
	
	Pilha_Construtor();
	Pilha_Push(1);
	Pilha_Push(2);
	Pilha_Push(3);
	Pilha_Push(4);
	Pilha_Push(5);
	
	printf("Quant itens na pilha: %d",Pilha_Tamanho());
	
	while(Pilha_Pop(&valor)==0)
	{
		printf("\n %d \n",valor);
	}
	
	printf("Quant itens na pilha: %d",Pilha_Tamanho());
	
	Pilha_Push(5);
	Pilha_Consulta(&valor);
	printf("\n %d \n",valor);
}

