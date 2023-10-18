#include <stdio.h> 
#include <string.h> 

void main ()  
{   
     FILE *arq; 
     char str1[30], str2[30];

     strcpy (str1, "Fundamentos de Programacao");

     arq = fopen ("arquivo.txt", "w+"); 

     fwrite (str1, strlen(str1) + 1, 1, arq); 

     fseek(arq, 0, SEEK_SET);

     fread (str2, strlen(str1)+1, 1, arq); 

     printf ("%s\n", str2); 
     
     fclose(arq);
}

