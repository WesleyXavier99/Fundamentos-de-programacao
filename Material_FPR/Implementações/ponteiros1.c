/*
   FPR - 2020/1
   Aula de 28/09/2020
   
   Ponteiros
*/

//importa��o de bibliotecas
#include <stdio.h>

//main
void main ()
{
	int a = 10, 
	    b = 20;
	    
	int *p, *q;
	.
	.
	.
	
	a = b;	//OK
	p = q;	//OK
	
	a = p;	//N�o - pois os tipos s�o incompat�veis
	q = b;	//N�o - pois os tipos s�o incompat�veis
	
	a = *p;	//Agora est� OK		
	q = &b;	//Agora est� OK		
}
