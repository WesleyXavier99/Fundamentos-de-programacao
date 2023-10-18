//Escreva um trecho de c´odigo para fazer a criac¸ ˜ao dos novos tipos de dados conforme
//solicitado abaixo:
// Hor´ ario: composto de hora, minutos e segundos.
// Data: composto de dia, mˆes e ano.
// Compromisso: composto de uma data, hor´ ario e texto que descreve o compromisso.

#include<stdio.h>

struct Horario{
	int horas;
	int minutos;
	int segundos;
};

struct Data{
	int dia;
	int mes;
	int ano;
};

struct Compromisso{
	struct Data;
	struct Horario;
	char texto[100];
};
