//Programa datahora.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <sys\stat.h>
#include <fcntl.h>

#define MAX 80
			
int main(int args, char *argv[])
{			
	time_t agora;
	int arq;
	
	_fmode = O_BINARY;
	arq = creat("datahora.bin", S_IWRITE);
	if (arq == -1)			
	{			
	printf("Erro ao criar arquivo\n");			
	system("pause");
	return 0;
	}
		
	/* Obter data e hora atuais */			
	agora = time(NULL);			
	
	/* Gravar data e hora no arquivo */			
	write (arq,&agora,sizeof(agora));			
	close (arq);			
	printf("Arquivo gravado! \n"); 
	system("pause");
	return 0;			
}			

