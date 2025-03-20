	//Programa p46.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <sys\stat.h>
#include <fcntl.h>

#define NUM_CAB 3
#define MAX(x,y) (((x) > (y))? (x) : (y))

typedef struct fila
{
	int numero;
	int atende;
	int tsaida;
	struct fila *prox;
	struct fila *prev;
}fila;

int Agora,NumVeiculo;
float TamMedio;
fila *Inic[NUM_CAB], *Fim[NUM_CAB];
	
int random(int n)
{
	return rand() %n;
}

void entrar_na_fila(int n)
{
	fila *p;
	NumVeiculo++;
	
	p = (fila *)calloc(1,sizeof(fila));
	
	p->numero = NumVeiculo;
	p->atende = 3 + random(6);
	
	if (Inic[n] == NULL)
		Inic[n] = p;
	if (Fim[n] != NULL)
		Fim[n]->prox = p;
	p->prev = Fim[n];
	p->prox = NULL;
	Fim[n] = p;
	
	//Calculo do tempo de saida
	if (p->prev != NULL)
		p->tsaida = MAX(Agora,p->prev->tsaida) + p->atende;
	else
		p->tsaida = Agora + p->atende;
}

void sair_da_fila(int n)
{
	Inic[n] = Inic[n]->prox;	
}

int tamanho_fila(int n)
{
	int t;
	fila *p;
	
	t = 0;
	p = Inic[n];
	while (p != NULL)
	{
		t++;
		p = p->prox;
	}
	return t;
}

int menor_fila()
{
	int i,t,nfila,tfila;
	
	nfila = 0;
	tfila = tamanho_fila(0);
	
	for (i = 1; i < NUM_CAB; i++)
	{
		t = tamanho_fila(i);
		if (t < tfila)
		{
			nfila = i;
			tfila = t;			
		}
		
	}
	return nfila;
}

void simular(int minutos)
{
	int i, nf, linha, chegada;
	
	chegada = 0;
	
	printf("+-------+---------+-----+------+--------+-------+\n");
	printf("| Tempo | Veiculo | E/S | Fila | Atend. | Saida |\n");
	printf("+-------+---------+-----+------+--------+-------+\n");
	
	for (Agora = 1; Agora <= minutos; Agora++)
	{
		linha = 0;
		printf("|  %3d  ",Agora);
		
		//Chegada de veiculos
		chegada++;
		if (chegada == 2)
		{
			nf = menor_fila();
			entrar_na_fila(nf);
			printf("|  %3d  |  %c  |  %2d  |  %2d  |  %3d  |\n",
					NumVeiculo,'E',nf,Fim[nf]->atende,Fim[nf]->tsaida);
			linha = 1;
			chegada = 0;
		}
		//Verificar a partida de veiculos
		for (i = 0; i < NUM_CAB; i++)
		{
			if (Inic[i] != NULL)
				if (Agora == Inic[i]->tsaida)
				{
					if (linha ==1)
						printf("|   ");
						printf("|  %3d  |  %c  |  %2d  |       |       |\n",
								Inic[i]->numero,'S',i);
						linha = 1;
						sair_da_fila(i);
				}
		}
		if (linha ==0)
			printf("|       |      |       |       |       |\n");
			for (i = 0; i < NUM_CAB; i++)
				TamMedio = TamMedio + tamanho_fila(i);
	}
	printf("+-------+---------+-----+------+--------+-------+\n");
	TamMedio = TamMedio / (NUM_CAB*minutos);	
}

int main(int args, char *arg[])
{
	char op;
	int i;
	
	for (i = 0; i < NUM_CAB; i++)
	{
		Inic[i] = NULL;
		Fim[i] = NULL;
	}
	
	//Inicializar gerador de numeros aleatorios
	srand((unsigned)time(NULL));
	
	//Simular 20 minutos
	simular(20);
	
	printf("\nResultado da Simulacao");
	printf("\n-------------");
	for (i = 0; i < NUM_CAB; i++)
		printf("\nTamanho final da fila %d = %d ", i, tamanho_fila(i));
		printf("\nTamanho medio das filas = %.1f\n\n", TamMedio);
	system("Pause");
	return 0;
}




