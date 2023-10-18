#include<stdio.h>

struct horario teste(struct horario x);

struct horario {
	int horas;
	int minutos;
	int segundos;
	float teste;
	char letra;
};

void main ()
{
	struct horario agora;
	struct horario auxiliar;
//	struct horario depois;
	
	agora.horas=12;
	agora.minutos=20;
	agora.segundos=10;
	
	//printf("%d : %d : %d \n",agora.horas,agora.minutos,agora.segundos);
	
//	depois.horas=agora.horas + 10;
//	depois.minutos=agora.minutos;
//	depois.segundos= agora.segundos * 3;
	
	//printf("%d : %d : %d \n",depois.horas,depois.minutos,depois.segundos);
	
//	depois.teste= 50.55 / 123;
//	depois.letra='a';
//	printf("%d \n%d \n%d \n%f \n%c \n",depois.horas,depois.minutos,depois.segundos,depois.teste,depois.letra);


	auxiliar=teste (agora);
	
	printf("%d : %d : %d",auxiliar.horas,auxiliar.minutos,auxiliar.segundos);

}

struct horario teste (struct horario x)
{
	printf("%d : %d : %d\n",x.horas,x.minutos,x.segundos);
	
	x.horas= 100;
	x.minutos=1000;
	x.segundos=10000;
	
	return x;
}
