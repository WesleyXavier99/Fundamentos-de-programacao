#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void bubbleSort (int V[], int N);
void imprimir(int numero[], int N);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    printf("\n--------------------------------------------");
    printf("\nEXEMPLO BUBBLE SORT CRESCENTE");
    printf("\n--------------------------------------------");
    
    int i, numero[7];
    
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
    
    bubbleSort(numero, 7);
    
}

void bubbleSort (int V[], int N)
{
	int i, aux, continua, fim = N;
	
    do
    {
        continua = 0;        
        for (i = 0; i < fim - 1; i++)
        {
            if (V[i] > V[i + 1])
            {
                aux = V[i];
                V[i] = V[i + 1];
                V[i + 1] = aux;
				continua = i;
            }	
        }
		fim--; 
    }while (continua != 0); 
	
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

