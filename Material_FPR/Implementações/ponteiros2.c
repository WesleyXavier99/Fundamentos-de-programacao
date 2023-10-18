/*
   FPR - 2020/1
   Aula de 28/09/2020
   
   Ponteiros
*/

//importação de bibliotecas
#include <stdio.h>

//main
void main ()
{
	int v[10] = {5,1,8,0,2,6,9,7,3,4};
	int i;
	
	for (i=0;i<10;i++)
	{
		printf ("%d (%p)\n", v[i], &v[i]);
		printf ("%d (%p)\n\n", v[i], v+i);
	}
}
