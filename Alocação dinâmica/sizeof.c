#include<stdio.h>
#include<stdlib.h>

struct x{
	int a;
	int b;
	int c;
};

void main()
{
	struct x estrutura;
	
	printf("%li",sizeof(estrutura));//sizeof recebe uma variavel/um tipo de dados ex: estrutura/double
}
//short 2 byts
//int 4 byts
//double 8byts

