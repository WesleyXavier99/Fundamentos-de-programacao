#include<stdio.h>

void main()
{
	struct horario{
		int *pHora;
		int *pMinuto;
		int *pSegundo;
	};
	
	struct horario hoje;
	
	int hora = 200;
	int minuto = 300;
	int segundo = 400;
	
	hoje.pHora = &hora;
	hoje.pMinuto = &minuto;
	hoje.pSegundo = &segundo;
	
	printf("Hora : %d\n",*hoje.pHora);
	printf("Minuto : %d\n",*hoje.pMinuto);
	printf("Segundo : %d\n\n",*hoje.pSegundo);
	
	*hoje.pHora = 1000;
	*hoje.pMinuto = 2000;
	*hoje.pSegundo = 3000;	
	
	printf("Hora : %d\n",*hoje.pHora);
	printf("Minuto : %d\n",*hoje.pMinuto);
	printf("Segundo : %d\n",*hoje.pSegundo);
	
}
