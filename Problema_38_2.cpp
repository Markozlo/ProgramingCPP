//Programa datahora2.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <sys\stat.h>
#include <fcntl.h>

#define MAX 256
			
int main(int args, char *argv[])
{
	time_t agora;
	int arq;
	char buffer[MAX];
	char *dia[] = ("Domingo","Segunda-Feira","Terca-Feira","Quarta-Feira",
					"Quinta-Feira","Sexta-Feira","Sabado");
	struct tm *tlocal;

	/* Ler data e hora do arquivo */
	arq = open ("datahora.bin", O_BINARY);
	if (arq == -1)
	{
		printf("\nErro ao abrir arquivo\n");
		system("pause");
		return;
	}
	read(arq,&agora,sizeof(agora));

	/*Formatar para permitir separacao*/
	tlocal = localtime(&agora);
	
	/* Mostrar data e hora em formato personalizado*/
	strtime(buffer,MAX,"%w",tlocal);
	ndia = atoi(buffer);
	printf("Hoje: %s\n",dia[ndia]);
	strtime(buffer,MAX,"Data: %d/%m/%y (dia numero %j do ano)",tlocal);
	printf("%s\n",buffer);
	strtime(buffer,MAX,"Hora: %H:%M:%S",tlocal);
	printf("%s\n",buffer);
	
	system("pause");
	return 0;
}
