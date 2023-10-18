//Em aula, implementamos em conjunto as funções de
//manipulação de uma lista encadeada simples.
//Com base neste programa e pensando que cada função
//deve ter o seu desenvolvimento otimizado, pede-se a
//implementação de uma lista encadeada com as
//seguintes características:
//	

//inserir no inicio e no fim
int inserir(TLista *L,int valor){
	if(verificar(L,valor)==1){
		return 0;
	}else{
		TLista aux = (TLista)malloc(sizeof(*No));
		if(listaVazia(L)){
			aux->valor = valor;
			aux->prox = *L;
			*L = aux;
			*topo = aux;
		}else{
			if(valor>0){
				aux->valor = valor;
				aux->prox = *L;
				*topo = aux;
			}else{
				aux->valor = valor;
				aux->prox = *L;
				*L = aux;
			}
			
		}
		
	}
	
}

//funcao pra verificar se a lista ta vazia

int verificar(TLista L,int numero){
	TLista aux = L;
	
	while(aux){
		
		if(numero == aux->valor){
			return 1;
		}
		aux=aux->prox;
	}
	return 0;
}


//FUNÇÃO PARA VERIFICAÇÃO DO ELEMENTO DENTRO DA LISTA

//? Não é permitida a repetição de elementos;
typedef struct No{
	int valor;
	struct No* prox;
}TNo;

typedef TNo *TLista;

void inserir(){
 	TLista *ultimo;//pomteiro pro ultimo no da lista
 	
}

//remover vai ter q atualizar o ultimo
int remover(TLista *L,int numero){
	if(verificar(L,valor)==0){
		return 0;
	}else{
		TLista aux = *L;
		while(aux){
			if(valor==aux->valor){
				
			}
			aux=aux->prox;
		}
	}
}

 //? Os números negativos devem estar no início da lista
 
//e os positivos ao seu final;

//? O elemento 0 não pode ser inserido na lista.


