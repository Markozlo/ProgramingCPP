//Programa p45.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <sys\stat.h>
#include <fcntl.h>

#define INFINITO 9e+99

typedef struct pilha
{
	int garrafas;
	struct pilha *prox;
}pilha;

pilha *Topo;

int NaoVenda,		//Numero de vendas nao efetuadas
	TotVenda,		//Total de unidades vendidas
	TamPilha,		//Tamanho da pilha de caixas
	NumGarr;		//Numero de garrafas na pilha
	
int random(int n)
{
	return rand() %n;
}

void empilhar()
{
	pilha *p;
	
	p = (pilha*)calloc(1,sizeof(pilha));
	
	p->garrafas = 12;
	p->prox = Topo;
	Topo = p;
}

void tirar_da_pilha(int ng)
{
	while(Topo != NULL)
	{
		if (ng ==0)
			break;
		ng--;
		NumGarr--;
		TotVenda++;
		Topo->garrafas--;
		if (Topo->garrafas == 0)
		{
			Topo = Topo->prox;
			TamPilha--;
		}
	}
	NaoVenda = NaoVenda + ng;
}

void simular (int horas)
{
	int t,ng;
	
	printf("+----------+----------+-----------------+\n");
	printf("|  Tempo   |  Venda   |  Apos a Venda   |\n");
	printf("|  (min)   |  (uni)   |  Garrafs Pilha  |\n");
	printf("+----------+----------+-----------------+\n");
	
	for (t = 0; t <= 60*horas; t = t +15)
	{
		//Determinar quantas garrafas serao compradas
		ng = random(7);
		
		//Efetuar venda
		tirar_da_pilha(ng);
		printf("|   %5d    |    %2d   |  %4d    %3d   |\n", t, ng, NumGarr,TamPilha);
	}
	printf("+----------+----------+-----------------+\n");
}

int main(int args, char *arg[])
{
	char op;
	int i;
	
	Topo = NULL;
	NaoVenda = 0;
	TotVenda = 0;
	
	//Inicializar gerandor de numeros aleatorios
	srand((unsigned)time(NULL));
	
	//Estoque inicial
	TamPilha = 5;
	NumGarr = 12*TamPilha;
	for (i = 0; i < TamPilha; i++)
		empilhar();
		
		//Simular 6 horas
		simular(6);
		
		printf("\nResultado da SImulacao");
		printf("\nTamanho final de pilha ........%5d", TamPilha);
		printf("\nTotal de unidades vendidas ....%5d", TotVenda);
		printf("\nTotal de unidades nao vendidas .%5d", NaoVenda);
		printf("\nPorcentagem de vendas perdidas .%8.2f\n\n", 100.0*NaoVenda/TotVenda);
		system("Pause");
		return 0;
}



















