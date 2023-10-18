#include<Stdio.h>


void main()
{
	FILE *file;
	file = fopen("string.txt","w");
	fprintf(file,"Pao com mortadela\ncoxinha\nhotdog\nmensagem aleatoria");
	fclose(file);
}
