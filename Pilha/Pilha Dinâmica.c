//Pilha Dinâmica
#include<stdio.h>

struct TipoCelula {
	int item;
	TipoCelula *prox;
};

int Pilha_Contador;
TipoCelula *Topo;


int Pilha_Construtor()
{
	Topo = NULL;
	Pilha_Contador = 0;
}

int Pilha_Destrutor()
{
	TipoCelula *Temp;
	
	if(Pilha_Vazia()==0)
	{
		return 0;
	}else{
		while(Topo!=NULL)//Pilha_Pop(aux)==0
		{
			Temp=Topo;
			Temp->prox = NULL;
			
			Topo=Topo->prox;
			
			free(Temp);
		}
		Pilha_Contador=0;
		return 1;
	}
	
}

int Pilha_Vazia()
{
	if(Topo==NULL)
	{
		return 0;
	}else{
		return 1;
	}
}

int Pilha_Tamanho()
{
	return Pilha_Contador;
}

int Pilha_Push(int valor)
{
	TipoCelula *Nova_Celula = (TipoCelula*)malloc(sizeof(TipoCelula));
	
	if(Nova_Celula==NULL)
	{
		return 0;
	}else{
		Nova_Celula->item = valor;
		Nova_Celula->prox = Topo;
		
		Topo = Nova_Celula;
		Pilha_Contador++;
		return 1;
	}
}

int Pilha_Pop(int *valor)[]
{
	TipoCelula *Temp;
	
	if(Pilha_Vazia()==0)
	{
		return 0;
	}else{
		*(valor) = Topo->item;
		Temp = Topo;
		Topo = Topo->prox;
		
		Temp->prox = NULL;
		
		free(Temp);
		Pilha_Contador--;
		return 1;
	}
}

int Pilha_Get(int *valor)
{
	if(Pilha_Vazia()==0)
	{
		return 0;
	}else{
		*(valor) = Topo->item;
		return 1;
	}
	
}

void main()
{
	
}


