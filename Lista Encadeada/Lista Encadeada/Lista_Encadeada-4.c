/*QUEST�O 04:
Implementar uma fun��o que, dadas duas listas din�micas do tipo TLista, verifique se estas s�o
iguais; isto �, cont�m os mesmos elementos, na mesma ordem.*/
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
		//colocando o aux pra apontar pro primeiro n� da lista
		aux->prox = *L1;
		//colocando o L1 pra apontar pro novo primeiro item da lista
		*L1 = aux;
	}
	return TRUE;
}

void exibir(TLista L){
	TLista i;
	
	//testar se a lista est� vazia
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

int verificar(TLista L1,TLista L2){
	TLista aux1,aux2;
	
	if((!L1)||(!L2)){
		return FALSE;
	}else{
		aux1 = L1;
		aux2 = L2;
		
		while((aux1)||(aux2)){
			
			if(aux1->valor!=aux2->valor){
				return FALSE;
			}
			
			aux1 = aux1->prox;
			aux2 = aux2->prox;
		}
	}
	return TRUE;
}

void main (){
	int i,res;
	TLista L1 = NULL;
	TLista L2 = NULL;
	
	//preencher as listas
	for(i=0;i<5;i++){
		inserir(&L1,i);		
	}
	for(i=0;i<5;i++){
		inserir(&L2,i+10);		
	}
	
	exibir(L1);
	exibir(L2);
	
	res = verificar(L1,L2);
	if(res==0){
		printf("\nNao sao iguais\n");
	}else{
		printf("\nSao iguais\n");
	}
}
