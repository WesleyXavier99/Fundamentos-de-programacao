#include <stdio.h>
#include "stdlib.h"
#include "time.h"

void quick_sort(int vetor[], int esquerda, int direita);
int max (int *a, int n, int i, int j, int k) ;
void downheap (int *a, int n, int i);
void heapsort (int a[], int n);
void shell_sort(int vetor[], int tamanho);
void shellSort(int vetor[], int tamanho);
void selectionSort (int vetor[], int tamanho);
void bubbleSort (int vetor[], int tamanho);
void merge(int vetor[], int comeco, int meio, int fim);
void mergeSort(int vetor[], int comeco, int fim);
void insertion_sort(int vetor[], int tamanhoVetor);
void printArray(int * array, int size);
int findLargestNum(int array[], int size);
void radixSort(int array[], int size);
int main ()
{
	
int i, tamanho, opcao, continuar;
printf ("Qual o tamanho do vetor");
scanf ("%d", &tamanho);
int vetor[tamanho];
srand(time(NULL));
for (i=0; i<tamanho; i++)
{
vetor[i]= rand() %tamanho+1;
}

do
{
printf ("1- HEAP\n");
printf ("2- QUICK\n");
printf ("3- BUBBLE\n");
printf ("4- SELECTION\n");
printf ("5- SHELL *2\n");
printf ("6- SHELL *3\n");
printf ("7- INSERTION\n");
printf ("8- MERGE\n");
printf ("9- RADIX\n");
printf ("Qual a opcao de ordenacao");
scanf ("%d", &opcao);
printf ("\n");
if (opcao ==1)
	{
		heapsort(vetor,tamanho);
	}
	else
		{ 
			if (opcao ==2)
				{ 
					clock_t hora_inicial = clock();
					quick_sort(vetor, 0, tamanho - 1);
					clock_t hora_final = clock();
					double tempo_gasto = ( (double) (hora_final - hora_inicial) ) / CLOCKS_PER_SEC;
					printf("TEMPO GASTO USANDO QUICK SORT: %lf s\n", tempo_gasto);
				}
			else
			 {
				 if (opcao ==3)
					{
						bubbleSort(vetor, tamanho);
					}
				else
					{
						if (opcao == 4)
						{
							clock_t hora_inicial = clock();
							selectionSort(vetor, tamanho);
							clock_t hora_final = clock();
							double tempo_gasto = ( (double) (hora_final - hora_inicial) ) / CLOCKS_PER_SEC;
							printf("TEMPO GASTO USANDO SELECTION SORT: %lf s\n", tempo_gasto);
						}
					else
						{
							if (opcao == 5)
								{
									shell_sort(vetor, tamanho);
								}
							else
								{
									if (opcao ==6)
										{
											shellSort( vetor, tamanho);
										}
									else 
									{
										if (opcao == 7)
											{
												int meio=tamanho/2;
												clock_t hora_inicial = clock();
												merge(vetor, 0,  meio, tamanho);
												mergeSort( vetor, 0, tamanho);
												clock_t hora_final = clock();
												double tempo_gasto = ( (double) (hora_final - hora_inicial) ) / CLOCKS_PER_SEC;
												printf("TEMPO GASTO USANDO MERGE SORT: %lf s\n", tempo_gasto);
											}
										else 
										{
											if (opcao == 8)
											{
												insertion_sort(vetor, tamanho);
											}
											else
											{
												if (opcao == 9)
												{
													clock_t hora_inicial = clock(); 
													radixSort(vetor, tamanho);
													clock_t hora_final = clock();
													double tempo_gasto = ( (double) (hora_final - hora_inicial) ) / CLOCKS_PER_SEC;
													printf("TEMPO GASTO USANDO RADIX SORT: %lf s\n", tempo_gasto);
												}
												else
												{
													printf ("opcao invalida!");
												}
											}
										}
									}
								}
							}
						}
					}
				}
		printf ("Digite qualquer número diferente de zero para continuar\n");
		scanf ("%d", &continuar);		
    }while (continuar!=0);
	
}
void bubbleSort (int vetor[], int tamanho)
{clock_t hora_inicial = clock();
	int i, aux, continua, fim = tamanho;
	
    do
    {
        continua = 0;        
        for (i = 0; i < fim - 1; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
				continua = i;
            }	
        }
		fim--; 
    }while (continua != 0); 
	clock_t hora_final = clock();
	double tempo_gasto = ( (double) (hora_final - hora_inicial) ) / CLOCKS_PER_SEC;
    printf("TEMPO GASTO USANDO BUBBLE SORT: %lf s\n", tempo_gasto);
}
void selectionSort (int vetor[], int tamanho)
{
	int i, j, menor, troca;
	
    for (i = 0; i < tamanho-1; i++)
    {
    	menor = i;
    	for (j = i+1; j < tamanho; j++)
    	{
    		if (vetor[j] < vetor[menor])
    		{
    			menor = j;
			}
		}
		
		if (i != menor)
		{
				troca = vetor[i];
				vetor[i] = vetor[menor];
				vetor[menor] = troca;
		}
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
void shellSort(int vetor[], int tamanho)
{
   int H = (tamanho - 1) / 2;
   int chave, i, aux;
 clock_t hora_inicial = clock();
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
   clock_t hora_final = clock();
   double tempo_gasto = ( (double) (hora_final - hora_inicial) ) / CLOCKS_PER_SEC;
            printf("TEMPO GASTO USANDO SHELL SORT (par): %lf s\n", tempo_gasto);
}
void shell_sort(int vetor[], int tamanho)
{
 int i , j , aux;
 int H = 1;
  clock_t hora_inicial = clock();
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
 clock_t hora_final = clock();
   double tempo_gasto = ( (double) (hora_final - hora_inicial) ) / CLOCKS_PER_SEC;
            printf("TEMPO GASTO USANDO SHELL SORT (X3): %lf s\n", tempo_gasto);
}
int max (int *a, int n, int i, int j, int k) {
    int m = i;
    if (j < n && a[j] > a[m]) {
        m = j;
    }
    if (k < n && a[k] > a[m]) {
        m = k;
    }
    return m;
}
 
void downheap (int *a, int n, int i) {
    while (1) {
        int j = max(a, n, i, 2 * i + 1, 2 * i + 2);
        if (j == i) {
            break;
        }
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i = j;
    }
}
 
void heapsort (int *a, int n) {
    int i;
    clock_t hora_inicial = clock();
    for (i = (n - 2) / 2; i >= 0; i--) {
        downheap(a, n, i);
    }
    for (i = 0; i < n; i++) {
        int t = a[n - i - 1];
        a[n - i - 1] = a[0];
        a[0] = t;
        downheap(a, n - i - 1, 0);
    }
    clock_t hora_final = clock();
	 double tempo_gasto = ( (double) (hora_final - hora_inicial) ) / CLOCKS_PER_SEC;
            printf("TEMPO GASTO USANDO HEAP SORT: %lf s\n", tempo_gasto);
}
void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}
void insertion_sort(int vetor[], int tamanhoVetor) {
clock_t hora_inicial = clock();
int escolhido, j, i;

    for (i = 1; i < tamanhoVetor; i++) {
		escolhido = vetor[i];
		j = i - 1;
		
		while ((j >= 0) && (vetor[j] > escolhido)) {
			vetor[j + 1] = vetor[j];
			j--;
		}
		
		vetor[j + 1] = escolhido;
	}
	clock_t hora_final = clock();
	double tempo_gasto = ( (double) (hora_final - hora_inicial) ) / CLOCKS_PER_SEC;
    printf("TEMPO GASTO USANDO INSERTION SORT: %lf s\n", tempo_gasto);
}
 int findLargestNum(int array[], int size){
  
  int i;
  int largestNum = -1;
  
  for(i = 0; i < size; i++){
    if(array[i] > largestNum)
      largestNum = array[i];
  }

  return largestNum;
}
void radixSort(int array[], int size){
  
  // Base 10
  int i;
  int semiSorted[size];
  int significantDigit = 1;
  int largestNum = findLargestNum(array, size);
  
  // Repetição até encontrar o LSD
  while (largestNum / significantDigit > 0){
    
    //printf("Posicao %d\t", significantDigit);
    //printArray(array, size);
    
    int bucket[10] = { 0 };
    
    // Pega a quantidade de chaves
    for (i = 0; i < size; i++)
      bucket[(array[i] / significantDigit) % 10]++;
    
    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];
    
    for (i = size - 1; i >= 0; i--)
      semiSorted[--bucket[(array[i] / significantDigit) % 10]] = array[i];
    
    for (i = 0; i < size; i++)
      array[i] = semiSorted[i];
    
       // Anda com o ponto
    significantDigit *= 10;
    
    //printf("\n\tBalde: ");
    //printArray(bucket, 10);
  }
}
