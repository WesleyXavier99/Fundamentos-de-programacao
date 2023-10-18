#include<stdio.h>

struct horario {
		int hora;
		int minuto;
		int segundo;
	};

void main()
{
	struct horario agora, *depois;
	depois = &agora;
	
	(*depois).hora = 20;//depois->hora = 20;
	(*depois).minuto = 30;//depois->minuto = 20;
	(*depois).segundo = 50;//depois->segundo = 20;
	
	
	int somatorio = 100;
	
	struct horario antes;
	
	antes.hora = somatorio + depois->segundo;//antes.hora = somatorio + (*depois).segundo;
	antes.minuto = agora.hora + depois->minuto;//antes.minuto = agora.hora + (*depois).minuto;
	antes.segundo = depois->minuto + depois->segundo;//antes.segundo = (*depois).minuto + (*depois).segundo;
	
	printf("%d : %d : %d",antes.hora,antes.minuto,antes.segundo);
}
