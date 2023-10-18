#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void selectionSort (int V[], int N);
void imprimir(int numero[], int N);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    printf("\n--------------------------------------------");
    printf("\nEXEMPLO SELECTION SORT CRESCENTE");
    printf("\n--------------------------------------------");
    
    int i, numero[7];
    
    clock_t t;
    
    for(i=0; i<7; i++)
    {
        numero[i] = 0;
    }
    
    printf("\n--------------------------------------------");
    printf("\nInserindo valores no Array\n");
    for(i=0; i<7; i++)
    {
        printf("\n|Posição %d |Digite um número: \t", i);
        scanf("%d",&numero[i]);
    }
    
    t = clock();
    
    selectionSort(numero, 7);
    
    t = clock() - t;
    
    printf("\n\nCalculando tempo de execução...\n");
    printf("\n\nO tempo de execução foi de: %f.\n", ((float)t)/CLOCKS_PER_SEC);
    
}

void selectionSort (int V[], int N)
{
	int i, j, menor, troca;
	
    for (i = 0; i < N-1; i++)
    {
    	menor = i;
    	for (j = i+1; j < N; j++)
    	{
    		if (V[j] < V[menor])
    		{
    			menor = j;
			}
		}
		
		if (i != menor)
		{
				troca = V[i];
				V[i] = V[menor];
				V[menor] = troca;
		}
	}
	imprimir(V, N);	
}
	 
void imprimir(int numero[], int N)
{
    int i;
	printf("\n--------------------------------------------");
    for (i=0; i<N; i++)
    {
        printf("\n|Posição: %d | Número: %d ", i, numero[i]);
    }
} 

