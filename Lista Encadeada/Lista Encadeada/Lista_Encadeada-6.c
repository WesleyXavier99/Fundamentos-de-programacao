/*QUESTÃO 06:
Desenvolver uma função que, dada uma lista L1, crie uma nova lista L2, cópia de L1*/
#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1

typedef struct No{
	int valor;
	struct No *prox;
}TNo;

typedef TNo* TLista;

int inserir(TLista *L1,int numero){
	TLista aux =(TLista) malloc(sizeof(TNo));
	
	if(!aux){//aux==NULL
		return FALSE;
	}else{
		//inserindo o valor desejado no campo valor
		aux->valor = numero;
		//colocando o aux pra apontar pro primeiro nó da lista
		aux->prox = *L1;
		//colocando o L1 pra apontar pro novo primeiro item da lista
		*L1 = aux;
	}
	return TRUE;
}

void exibir(TLista L){
	TLista i;
	
	//testar se a lista está vazia
	if(L==NULL){
		printf("\nLISTA VAZIA\n");
	}else{
		
		i = L;
		
		while(i){//(i!=NULL)
			printf("%d ",i->valor);
			
			i = i->prox;
		}
	}
	printf("\n");
}

int criar(TLista L1,TLista *L2){
	
	TLista aux;
	int i,cont=0;
	
	//verificar se a lista ta vazia
	if(!L1){
		printf("\nLista vazia\n");
	}else{
		aux = L1;
		while(aux){
			cont++;
			aux = aux->prox;
		}
		aux = L1;
		int vetor[cont];
		
		i=0;
		while(aux){
			vetor[i]=aux->valor;
			i++;
			
			aux = aux->prox;
		}
		aux=L1;
		
		i=cont;
		while(aux){
			inserir(L2,vetor[i-1]);
			i--;
			aux = aux->prox;
		}
	}
}

void main (){
	int i,res;
	TLista L1 = NULL;
	TLista L2 = NULL;
	
	//preencher as listas
	for(i=0;i<5;i++){
		inserir(&L1,i);		
	}
	
	exibir(L1);
	
	criar(L1,&L2);
	
	exibir(L2);
}
