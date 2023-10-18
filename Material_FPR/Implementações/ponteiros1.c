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
	int a = 10, 
	    b = 20;
	    
	int *p, *q;
	.
	.
	.
	
	a = b;	//OK
	p = q;	//OK
	
	a = p;	//Não - pois os tipos são incompatíveis
	q = b;	//Não - pois os tipos são incompatíveis
	
	a = *p;	//Agora está OK		
	q = &b;	//Agora está OK		
}
