#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1

typedef struct No{
	int valor;
	struct No* prox;
}TNo;

typedef TNo *TLista;

int verificar(TLista L,int numero){
	TLista aux = L;
	while(aux){
		if(aux->valor==numero){
			//retorna 1 se achar o valor
			return TRUE;
		}
		aux=aux->prox;
	}
	//retorna 0 se não achar o valor
	return FALSE;
}

int inserir(TLista *L,TLista *topo,int valor){
	//verifica se o valor já foi inserido
	if(verificar(*L,valor)==1){
		return FALSE;
	}else{
		//aloca memoria
		TLista aux = (TLista)malloc(sizeof(TNo));
		
		//se a lista estiver vazia
		if(!(*L)){
			aux->valor = valor;
			aux->prox = *L;
			*L = aux;
			*topo = aux;
			return TRUE;
			
		}else{
			
			if(valor>0){//adicionar os positivos
				aux->valor = valor;
				aux->prox = NULL;
				(*topo)->prox = aux;
				*topo = aux;
				return TRUE;
				
			}else{//adicionar os negativos
				aux->valor = valor;
				aux->prox = *L;
				*L = aux;
				return TRUE;
				
			}	
		}
	}
	
}

int remover(TLista *L,TLista *topo,int valor){
	TLista aux1,aux2,aux3;
	
	//não remove se o valor não existir ou se o valor for 0 ou se a lista estiver vazia
	if(verificar(*L,valor)==0||valor==0||!(*L)){
		return FALSE;
	}else{
		//se o valor a ser removido estiver na primeira posição
		if((*L)&&((*L)->valor==valor)){
			aux1 = (*L)->prox;
			free(*L);
			*L = aux1;
			return TRUE;
		}else{
			//se o valor a ser removido estiver na ultima posição
			aux1 = (*L)->prox->prox;
			aux2 = (*L)->prox;
			aux3 = *L;
			
			while(aux2){
				
				printf("\n\naux2 = %d e aux3 = %d\n\n",aux2->valor,aux3->valor);
				
				if(aux2->valor==valor&&aux2->prox==NULL){
					if((*topo)->valor==aux2->valor&&aux2->prox==NULL){
						aux3->prox = aux2->prox;
						free(aux2);
						*topo=aux3;
						printf("\nremoveu topo\n");
						return TRUE;
					}else{
						aux3 = aux2->prox;
						free(aux2);
						printf("\nremoveu nao topo\n");
						return TRUE;
					}
				}
				if(aux2->valor==valor){
					aux3->prox = aux2->prox;
					free(aux2);
					printf("\nremoveu fora da ultima posicao\n");
					return TRUE;
				}
				aux1=aux1->prox;
				aux2=aux2->prox;
				aux3=aux3->prox;
			}
				
			
		}
	}
}

int exibir(TLista L){
	TLista aux = L;
	if(!aux){
		//retorna 0 se a lista estiver vazia
		return FALSE;
	}
	while(aux){
		printf("%d ",aux->valor);
		aux=aux->prox;
	}
	//retorna 1 se consegue exibir a lista
	return TRUE;	
}

void main(){
	TLista L=NULL,topo=NULL;
	int opcao = 0,valor,res;
	
	while(opcao!=5){
		printf("Digite a opcao desejada:\n1-Inserir\n2-Remover\n3-Alterar\n4-Exibir\n5-Sair\n");
		scanf("%d",&opcao);
		
		switch(opcao){
			
			case 1: printf("Digite o valor a ser inserido:");
					scanf("%d",&valor);
					
					res = inserir(&L,&topo,valor);
					if(res==0){
						printf("\nnao foi possivel inserir!\n");
					}else{
						printf("\ninserido com sucesso!\n");
					}
			break;
			
			case 2: printf("Digite o valor a ser removido:\n");
					scanf("%d",&valor);
					
					res = remover(&L,&topo,valor);
					if(res==0){
						printf("\nNao foi possiver remover!\n");
					}else{
						printf("\nRemovido com sucesso!\n");
					}
			break;
			
			case 3:
				
			break;
			
			case 4: res = exibir(L);
					if(res==0){
						printf("\nLista Vazia!\n");
					}
				
			break;
			
			case 5:
				
			break;
			
			default: printf("\nERRO!Digite um valor valido!\n");
			break;
		}
		printf("\ntopo = %d\n",topo->valor);
	}
}
