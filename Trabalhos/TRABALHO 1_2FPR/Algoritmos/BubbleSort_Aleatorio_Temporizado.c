#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void GeraAleatorios(int numeros[],int quantNumeros,int Limite);
void bubbleSort (int V[], int N);
void imprimir(int numero[], int N);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    printf("\n--------------------------------------------");
    printf("\nEXEMPLO BUBBLE SORT CRESCENTE");
    printf("\n--------------------------------------------\n\n");
    
    
	int n, limite;
	
	printf("Deseja gerar quantos n�meros: ");
	scanf("%d", &n);
	
	printf("\nQual o limite: ");
	scanf("%d", &limite);
	
	int i, numero[n];
    
    clock_t t;
    
    for(i=0; i<n; i++)
    {
        numero[i] = 0;
    }
    
    
    t = clock();
    
    GeraAleatorios(numero,n,limite);
    
	t = clock() - t;
    
    printf("\n\nCalculando tempo de execu��o...\n");
    printf("\n\nO tempo de execu��o foi de: %f.\n", ((float)t)/CLOCKS_PER_SEC);
    
}

void GeraAleatorios(int numeros[],int quantNumeros,int Limite)
{
    srand(time(NULL));

    int i;
    for(i=0;i<quantNumeros;i++){
        numeros[i] = rand() % Limite;
    }
    
    bubbleSort(numeros, quantNumeros);

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
        printf("\n|Posi��o: %d | N�mero: %d ", i, numero[i]);
    }
} 

