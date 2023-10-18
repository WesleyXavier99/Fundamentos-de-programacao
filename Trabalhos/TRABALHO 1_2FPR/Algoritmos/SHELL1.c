#include <stdio.h>
#include "stdlib.h"
#include "time.h"

void shell_sort(int vetor[], int tamanho);
void shellSort(int vetor[], int tamanho);

int main ()
{
	int i, tamanho;
	
	printf ("Qual o tamanho do vetor");
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
	
	printf ("\n");
	shellSort(vetor, tamanho);
	
	for (i=0; i<tamanho; i++)
	{
		printf ("%d ", vetor[i]);
	}
	
	shell_sort(vetor, tamanho);
	printf ("\n");
	
	for (i=0; i<tamanho; i++)
	{
		printf ("%d ", vetor[i]);
	}
}


void shellSort(int vetor[], int tamanho)
{
   int H = (tamanho - 1) / 2;
   int chave, i, aux;
 
   while(H != 0)
   {
      do
      {
         chave = 1;
         for(i = 0; i < tamanho - H; ++i)
         {
            if(vetor[i] > vetor[i + H])
            {
               aux = vetor[i];
               vetor[i] = vetor[i + H];
               vetor[i + H] = aux;
               chave = 0;
            }
         }
      }while(chave == 0);
      H = H / 2;
   }
}
void shell_sort(int vetor[], int tamanho)
{
 int i , j , aux;
 int H = 1;
  
 do {
  H = 3*H+1;
 } while(H < tamanho);
  
 do {
  H/= 3;
  for(i = H; i < tamanho; i++) 
  {
   aux = vetor[i];
   j = i - H;
    
   while (j >= 0 && aux < vetor[j]) 
   {
    vetor[j + H] = vetor[j];
    j -= H;
   }
   vetor[j + H] = aux;
  }
 }while(H > 1);
}

