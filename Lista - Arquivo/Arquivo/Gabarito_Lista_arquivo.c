/*
Lista V - Arquivos

Quest�o 01:
Desenvolver uma fun��o que, dado um arquivo texto, verifique o n�mero de caracteres no
mesmo.


//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int contaCaracteres (char nomeArq[]);

//main
void main ()
{
//declara��o de vari�veis
char nome[20];
int quant;

//lendo o nome do arquivo
fflush (stdin);
printf ("Entre com o nome do arquivo: ");
gets (nome);

//chamando a fun��o
quant = contaCaracteres (nome);

//exibindo o resultado
if (quant >= 0)
{
printf ("\n\nForam encontrados %d caracteres no arquivo %s", quant, nome);
}
else
{
printf ("Erro na abertura do arquivo!");
}
}

//implementa��o das fun��es
int contaCaracteres (char nomeArq[])
{
FILE *arq;
int cont = 0;
char caracter;

//abrindo o arquivo para leitura
arq = fopen (nomeArq, "r");

//verificando se houve erro na abertura do arquivo
if (arq == NULL)
{
return -1; //erro na abertura do arquivo
}

//lendo e contando os caracteres do arquivo
while (fscanf (arq, "%c", &caracter) != EOF)
{
cont++;
}

//fechando o arquivo
fclose (arq);

//retornando a quantidade de caracteres do arquivo
return cont;
}
*/




/*
Lista V - Arquivos

Quest�o 02:
Desenvolver uma fun��o que, dado um arquivo texto, verifique o n�mero de vezes que um
determinado caracter aparece no arquivo.


//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int contaCaracteres (char nomeArq[], char c);

//main
void main ()
{
//declara��o de vari�veis
char nome[20];
int quant;
char ch;

//lendo o nome do arquivo
fflush (stdin);
printf ("Entre com o nome do arquivo: ");
gets (nome);

//lendo o caracter a ser buscado no arquivo
fflush (stdin);
printf ("Entre com o caracter a ser buscado: ");
scanf ("%c", &ch);

//chamando a fun��o
quant = contaCaracteres (nome, ch);

//exibindo o resultado
if (quant >= 0)
{
printf ("\n\nForam encontrados %d ocorrencias do caracter '%c' no arquivo %s", quant, ch, nome);
}
else
{
printf ("Erro na abertura do arquivo!");
}
}

//implementa��o das fun��es
int contaCaracteres (char nomeArq[], char c)
{
FILE *arq;
int cont = 0;
char caracter;

//abrindo o arquivo para leitura
arq = fopen (nomeArq, "r");

//verificando se houve erro na abertura do arquivo
if (arq == NULL)
{
return -1; //erro na abertura do arquivo
}

//lendo todos os caracteres do arquivo
while (fscanf (arq, "%c", &caracter) != EOF)
{
if (caracter == c) //verificando se � o caracter sendo buscado
{
cont++;
}
}

//fechando o arquivo
fclose (arq);

//retornando a quantidade de caracteres do arquivo
return cont;
}*/


/*	
Lista V - Arquivos

Quest�o 03:
Desenvolver uma fun��o que, dado um arquivo texto, verifique o n�mero de letras
existentes no mesmo (entendendo que no arquivo podem existir letras, algarismos e
s�mbolos).

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int contaLetras (char nomeArq[]);

//main
void main ()
{
//declara��o de vari�veis
char nome[20];
int quant;

//lendo o nome do arquivo
fflush (stdin);
printf ("Entre com o nome do arquivo: ");
gets (nome);

//chamando a fun��o
quant = contaLetras (nome);

//exibindo o resultado
if (quant >= 0)
{
printf ("\n\nForam encontrados %d letras no arquivo %s", quant, nome);
}
else
{
printf ("Erro na abertura do arquivo!");
}
}

//implementa��o das fun��es
int contaLetras (char nomeArq[])
{
FILE *arq;
int cont = 0;
char caracter;

//abrindo o arquivo para leitura
arq = fopen (nomeArq, "r");

//verificando se houve erro na abertura do arquivo
if (arq == NULL)
{
return -1; //erro na abertura do arquivo
}

//lendo todos os caracteres do arquivo
while (fscanf (arq, "%c", &caracter) != EOF)
{
caracter = toupper (caracter);

//verificando se est� no intervalo de A a Z
if ((caracter >= 'A') && (caracter <= 'Z'))
{
cont++;
}
}

//fechando o arquivo
fclose (arq);

//retornando a quantidade de caracteres do arquivo
return cont;
}
*/

/*
Lista V - Arquivos

Quest�o 04:
Desenvolver uma fun��o que, dado um arquivo texto contendo n�meros, determine se estes
encontram-se ordenados crescentemente.


//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos das fun��es
int verificaArquivo (char nomeArq[]);

//main
void main ()
{
//declara��o de vari�veis
char nome[20];
int resp;

//lendo o nome do arquivo
fflush (stdin);
printf ("Entre com o nome do arquivo: ");
gets (nome);

//chamando a fun��o
resp = verificaArquivo (nome);

//exibindo o resultado
switch (resp)
{
case TRUE: printf ("\n\nOs elementos do arquivo %s encontram-se ordenados crescentemente", nome);
break;

case FALSE: printf ("\n\nOs elementos do arquivo %s nao encontram-se ordenados crescentemente", nome);
break;

default: printf ("\n\nErro na abertura do arquivo!");
}
}

//implementa��o das fun��es
int verificaArquivo (char nomeArq[])
{
FILE *arq;
float anterior, proximo;

//abrindo o arquivo para leitura
arq = fopen (nomeArq, "r");

//verificando se houve erro na abertura do arquivo
if (arq == NULL)
{
return -1; //erro na abertura do arquivo
}

//lendo o primeiro valor do arquivo
if (fscanf (arq, "%f", &anterior) != EOF)
{
//lendo os demais caracteres do arquivo
while (fscanf (arq, "%f", &proximo) != EOF)
{
//verificando se o anterior � maior do que o pr�ximo. Se for, o arquivo
//n�o est� ordenado
if (anterior > proximo)
{
return FALSE;
}

anterior = proximo;
}
}

//fechando o arquivo
fclose (arq);

return TRUE;
}*/


/*
Lista V - Arquivos

Quest�o 05:
Fa�a uma fun��o que, dado um arquivo A contendo n�meros reais, um por linha, crie um
novo arquivo B contendo os mesmos elementos de A, por�m ordenados decrescentemente e
sem repeti��o.


//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos das fun��es
int eliminaRepeticaoArquivo (char arqOriginal[], char arqNovo[]);
int pesquisar (float valor, char nomeArq[]);
int buscarMenorElemento (char nomeArq[], float *menor, float base);

//main
void main ()
{
//declara��o de vari�veis
char original[20], novo[20];
int resp;

//lendo os nomes dos dois arquivos
fflush (stdin);
printf ("Arquivo original: ");
gets (original);

fflush (stdin);
printf ("Arquivo novo: ");
gets (novo);

//chamando a fun��o
resp = eliminaRepeticaoArquivo (original, novo);

//exibindo o resultado
if (resp == FALSE)
{
printf ("\nErro na abertura do arquivo!\n");
}
else
{
printf ("\nNovo arquivo gerado com sucesso!\n");
}
}

//implementa��o das fun��es
int eliminaRepeticaoArquivo (char arqOriginal[], char arqNovo[])
{
//declara��o de vari�veis
FILE *arqA, *arqB;
float valorA, menor, base = -9999;
int continuar;

//abrindo o arquivo original para que seus elementos sejam lidos
arqA = fopen (arqOriginal, "r");

//abrindo o arquivo novo para escrita; caso n�o exista, o mesmo ser� criado
//esta abertura servir� apenas para testar se houve algum tipo de erro na abertura deste
//arquivo e garantir que o mesmo seja criado, caso ainda n�o exista
arqB = fopen (arqNovo, "w");

//verificando se houve erro na abertura de algum arquivo
if ((arqA == NULL) || (arqB == NULL))
{
return FALSE; //erro na abertura
}

//fechando o arquivo novo, para que seja em seguida manipulado de forma distinta (leitura ou append)
fclose (arqB);

//buscando o menor elemento do arquivo (que seja maior do que a base)
continuar = buscarMenorElemento (arqOriginal, &menor, base);

while (continuar == TRUE)
{
//verificando se o elemento do arquivo A j� foi inserido no arquivo B
if (pesquisar (menor, arqNovo) == FALSE)
{
arqB = fopen (arqNovo, "a");
fprintf (arqB, "%.1f\n", menor);
fclose (arqB);
}

//buscando o menor elemento do arquivo (que seja maior do que o �ltimo encontrado)
continuar = buscarMenorElemento (arqOriginal, &menor, menor);
}

fclose (arqA);

return TRUE;
}

//verificar se 'valor' encontra-se no arquivo de nome 'nomeArq', retornando TRUE ou FALSE
int pesquisar (float valor, char nomeArq[])
{
//declara��o de vari�veis
FILE *arq;
float numero;

//abrindo o arquivo para leitura
arq = fopen (nomeArq, "r");

//testando se houve erro na abertura do arquivo
if (arq == NULL)
{
return FALSE;
}

//lendo os n�meros do arquivo em busca de 'valor'
while (fscanf (arq, "%f", &numero) != EOF)
{
if (numero == valor)
{
return TRUE; //'valor' encontrado no arquivo
}
}

//fechando o arquivo
fclose (arq);

//elemento n�o foi encontrado no arquivo
return FALSE;
}

//Dentre os valores do arquivo que sejam maior do que 'base', a fun��o armazenar�
//o menor deles no par�metro 'menor'. Al�m disto, retornar� FALSE se nenhum valor maior do
//que 'base' for encontrado.
int buscarMenorElemento (char nomeArq[], float *menor, float base)
{
//declara��o de vari�veis
FILE *arq;
float valor;
int alterou = FALSE;

//inicializa��o *menor com um valor alto
*menor = 99999;

//abrindo o arquivo para leitura
arq = fopen (nomeArq, "r");

//lendo todos os elementos do arquivo
while (fscanf (arq, "%f", &valor) != EOF)
{
if ((valor > base) && (valor < *menor))
{
*menor = valor;
alterou = TRUE;
}
}

//fechando o arquivo
fclose (arq);

return alterou;
}*/


/*
Lista V - Arquivos

Quest�o 06:
Desenvolver uma fun��o que, dados dois arquivos textos arqA e arqB, crie um novo
arquivo arqC, considerando que:

- arqA e arqB cont�m n�meros reais, um por linha, ordenados crescentemente e sem
repeti��o no arquivo;
- arqC deve conter todos os n�meros dos dois arquivos originais;
- Assim como arqA e arqB, arqC tamb�m n�o possuir� repeti��es de elementos e estes
dever�o estar ordenados de forma crescente.


//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos das fun��es
int uniao (char arquivo1[], char arquivo2[], char arqUniao[]);

//main
void main ()
{
//declara��o de vari�veis
char A[20], B[20], C[20];
int resp;

//lendo os nomes dos arquivos
fflush (stdin);
printf ("Nome do arquivo A: ");
gets (A);

fflush (stdin);
printf ("Nome do arquivo B: ");
gets (B);

fflush (stdin);
printf ("Nome do arquivo que armazenara a uniao dos dois arquivos: ");
gets (C);

//chamando a fun��o
resp = uniao (A, B, C);

//exibindo o resultado
if (resp == FALSE)
{
printf ("\nErro na abertura dos arquivos!\n");
}
else
{
printf ("\nArquivo '%s' gerado com sucesso!\n", C);
}
}

//implementa��o das fun��es
int uniao (char arquivo1[], char arquivo2[], char arqUniao[])
{
//declara��o de vari�veis
FILE *arqA, *arqB, *arqC;
float valorA, valorB;
int controleA, controleB;

//abrindo os tr�s arquivos
arqA = fopen (arquivo1, "r");
arqB = fopen (arquivo2, "r");
arqC = fopen (arqUniao, "w");

//verificando se houve erro na abertura de algum arquivo
if ((arqA == NULL) || (arqB == NULL) || (arqC == NULL))
{
return FALSE; //erro na abertura
}

//as vari�veis controle verificar�o se algum arquivo (ou os dois) chegou ao final
controleA = fscanf (arqA, "%f", &valorA);
controleB = fscanf (arqB, "%f", &valorB);

//verificando se algum arquivo chegou ao final
while ((controleA != EOF) && (controleB != EOF))
{
//verificando se o �ltimo valor lido do primeiro arquivo � menor do que o �ltimo
//lido do segundo
if (valorA < valorB)
{
//guarda-se o menor no arquivo uni�o
fprintf (arqC, "%.1f\n", valorA);

//lendo o pr�ximo valor do arquivo A
controleA = fscanf (arqA, "%f", &valorA);
}
else
{
//verificando se o �ltimo valor lido do segundo arquivo � menor do que o
//�ltimo lido do primeiro
if (valorB < valorA)
{
//guarda-se o menor no arquivo uni�o
fprintf (arqC, "%.1f\n", valorB);

//lendo o pr�ximo valor do arquivo B
controleB = fscanf (arqB, "%f", &valorB);
}
else
{
//se chegou aqui, os dois valores s�o iguais. Ent�o, apenas um deles ser�
//escrito no arquivo uni�o, eliminando, assim, a repeti��o
fprintf (arqC, "%.1f\n", valorA);

//lendo os pr�ximos valores dos dois arquivos
controleA = fscanf (arqA, "%f", &valorA);
controleB = fscanf (arqB, "%f", &valorB);
}
}
}

//se saiu do while, um dos arquivos (ou os dois) terminou. Ent�o, � necess�rio
//transferir para o arquivo uni�o os elementos do arquivo que ainda n�o foi totalmente
//lido

//primeiro, verificando se pelo menos um dos arquivos ainda possui elementos
if ((controleA != EOF) || (controleB != EOF))
{
//se o arquivo A terminou, copiar para C os elementos pendentes de B
if (controleA == EOF)
{
fprintf (arqC, "%.1f\n", valorB);

while (fscanf (arqB, "%f", &valorB) != EOF)
{
fprintf (arqC, "%.1f\n", valorB);
}
}
else
{
//se o arquivo B terminou, copiar para C os elementos pendentes de A
fprintf (arqC, "%.1f\n", valorA);

while (fscanf (arqA, "%f", &valorA) != EOF)
{
fprintf (arqC, "%.1f\n", valorA);
}
}
}

//fechando os arquivos
fclose (arqA);
fclose (arqB);
fclose (arqC);

return TRUE;
}*/


/*
Lista V - Arquivos

Quest�o 07:
Desenvolver uma fun��o que, dados dois arquivos textos arqA e arqB, crie um novo
arquivo arqC, considerando que:

- arqA e arqB cont�m n�meros reais, um por linha, ordenados crescentemente e sem
repeti��o no arquivo;
- arqC deve conter apenas os n�meros comuns aos dois arquivos originais;
- Assim como arqA e arqB, arqC tamb�m n�o possuir� repeti��es de elementos e estes
dever�o estar ordenados de forma crescente.


//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos das fun��es
int interseccao (char arquivo1[], char arquivo2[], char arqInterseccao[]);

//main
void main ()
{
//declara��o de vari�veis
char A[20], B[20], C[20];
int resp;

//lendo os nomes dos arquivos
fflush (stdin);
printf ("Nome do arquivo A: ");
gets (A);

fflush (stdin);
printf ("Nome do arquivo B: ");
gets (B);

fflush (stdin);
printf ("Nome do arquivo que armazenara a interseccao dos dois arquivos: ");
gets (C);

//chamando a fun��o
resp = interseccao (A, B, C);

//exibindo o resultado
if (resp == FALSE)
{
printf ("\nErro na abertura dos arquivos!\n");
}
else
{
printf ("\nArquivo '%s' gerado com sucesso!\n", C);
}
}

//implementa��o das fun��es
int interseccao (char arquivo1[], char arquivo2[], char arqInterseccao[])
{
//declara��o de vari�veis
FILE *arqA, *arqB, *arqC;
float valorA, valorB;
int controleA, controleB;

//abrindo os tr�s arquivos
arqA = fopen (arquivo1, "r");
arqB = fopen (arquivo2, "r");
arqC = fopen (arqInterseccao, "w");

//verificando se houve erro na abertura de algum arquivo
if ((arqA == NULL) || (arqB == NULL) || (arqC == NULL))
{
return FALSE; //erro na abertura
}

//as vari�veis controle verificar�o se algum arquivo (ou os dois) chegou ao final
controleA = fscanf (arqA, "%f", &valorA);
controleB = fscanf (arqB, "%f", &valorB);

//verificando se algum arquivo chegou ao final
while ((controleA != EOF) && (controleB != EOF))
{
//verificando se o �ltimo valor lido do primeiro arquivo � menor do que o �ltimo
//lido do segundo
if (valorA < valorB)
{
//lendo o pr�ximo valor do arquivo A
controleA = fscanf (arqA, "%f", &valorA);
}
else
{
//verificando se o �ltimo valor lido do segundo arquivo � menor do que o
//�ltimo lido do primeiro
if (valorB < valorA)
{
//lendo o pr�ximo valor do arquivo B
controleB = fscanf (arqB, "%f", &valorB);
}
else
{
//se chegou aqui, os dois valores s�o iguais. Ent�o, este valor deve ser
//inserido na interseccao (uma �nica vez)
fprintf (arqC, "%.1f\n", valorA);

//lendo os pr�ximos valores dos dois arquivos
controleA = fscanf (arqA, "%f", &valorA);
controleB = fscanf (arqB, "%f", &valorB);
}
}
}

//se saiu do while, um dos arquivos (ou os dois) terminou. Ent�o, �n�o h� mais
//nada a fazer necess�rio, al�m de fechar os arquivos

//fechando os arquivos
fclose (arqA);
fclose (arqB);
fclose (arqC);

return TRUE;
}*/
