#include <stdio.h>
#include "stdlib.h"
#include "time.h"

void quick_sort(int vetor[], int esquerda, int direita);

int main()
{

	int i, tamanho;
	
	printf ("Qual o tamanho do vetor: ");
	scanf ("%d", &tamanho);
	
	int vetor[tamanho];
	
	srand(time(NULL));
	
	for (i=0; i<tamanho; i++)
	{
		vetor[i]= rand() %tamanho+1;
	}
	
	for (i=0; i<tamanho; i++)
	{
		printf ("%d ", vetor[i]);
	}
	
	printf ("\n\n");
	 
	quick_sort(vetor, 0, tamanho - 1);
	
	for (i=0; i<tamanho; i++)
	{
		printf ("%d ", vetor[i]);
	}
}

void quick_sort(int vetor[], int esquerda, int direita) {
    int i, j, x, y;
     
    i = esquerda;
    j = direita;
    x = vetor[(esquerda + direita) / 2];
     
    while(i <= j) {
        while(vetor[i] < x && i < direita) {
            i++;
        }
        while(vetor[j] > x && j > esquerda) {
            j--;
        }
        if(i <= j) {
            y = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > esquerda) {
        quick_sort(vetor, esquerda, j);
    }
    if(i < direita) 
    {
        quick_sort(vetor, i, direita);
    }
}
