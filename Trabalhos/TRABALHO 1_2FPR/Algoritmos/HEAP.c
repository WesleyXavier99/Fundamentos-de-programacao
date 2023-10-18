#include <stdio.h>
#include "stdlib.h"
#include "time.h"
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
 
int main () {
    /*int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int n = sizeof a / sizeof a[0];
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");*/
        int i, tamanho;
printf ("Qual o tamanho do vetor");
scanf ("%d", &tamanho);
int vetor[tamanho];
srand(time(NULL));
for (i=0; i<tamanho; i++)
{
vetor[i]= rand() %tamanho+1;
}
/*for (i=0; i<tamanho; i++)
{
printf ("%d ", vetor[i]);
}*/
printf ("\n");
	heapsort(vetor,tamanho);
    //heapsort(a, n);
   /*for (i=0; i<tamanho; i++)
{
printf ("%d ", vetor[i]);
}*/
    return 0;
}
