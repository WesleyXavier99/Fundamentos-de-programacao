/*QUESTÃO 09:
Implementar uma função que, dada uma lista dinâmica do tipo TLista, verifique se os
elementos da estrutura encontram-se ordenados de forma crescente ou não.*/
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
}

int verificar(TLista L1){
	TLista aux1;
	int aux=-9999999;
	
	if(!L1){
		return FALSE;
	}else{
		aux1 = L1;
		
		while(aux1){
			
			if(aux1->valor<aux){
				return FALSE;
			}
			aux = aux1->valor;
			aux1 = aux1->prox;
		}
	}
	return TRUE;
}

void main (){
	TLista L1 = NULL;
	int res,i;
	
	//preencher as listas
	for(i=4;i>=0;i--){
		inserir(&L1,i);		
	}
	
	exibir(L1);
	
	res = verificar(L1);
	if(res==0){
		printf("\nNao eh crescente\n");
	}else{
		printf("\nEh crescente\n");
	}
}
