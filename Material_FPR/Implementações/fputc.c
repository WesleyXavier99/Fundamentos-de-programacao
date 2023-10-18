#include <stdio.h>

void main () 
{ 
     FILE *fp; 
     int ch; 

     fp = fopen("fputc.txt", "w");

     for (ch=33; ch<=100; ch++) 
     { 
          fputc(ch, fp); 
     } 
     fclose(fp);
}

