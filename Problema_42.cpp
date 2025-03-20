//Programa p42.c
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

typedef struct lista
{
	int cli;
	float val;
	struct lista *prox;
}lista;

lista *plista;

int cliente;
float valor;

char opcao_menu()
{
	system("cls");
	printf("LISTA COM LIST HEAD\n");
	printf(" (I)ncluir pedido\n");
	printf(" (E)xckuir pedido\n");
	printf(" (L)istar pedido\n");
	printf(" (F)im\n");
	printf("> ");
	return (toupper(getche()));
}

void ler_pedido()
{
	printf("\nNumero do Cliente .....");
	scanf("%d",&cliente);
	printf("Valor do pedido......");
	scanf("%f",&valor);
}

void incluir_pedido()
{
	lista *p, *q, *r;
	
	ler_pedido();
	
	p = (lista*)calloc(1,sizeof(lista));
	
	p->cli = cliente;
	p->val = valor;
	p->prox = NULL;
	
	/*Incluir pedido na lista */
	
	r = NULL;
	q = plista;
	while ((q != NULL) && (q->val > valor))
	{
		r = q;
		q = q->prox;
	}
	r->prox = p;
	q->prox = q;	
}

void excluir_pedido()
{
	lista *p, *q;
	
	ler_pedido();
	
	q = NULL;
	p = plista;
	while((p != NULL) && ((p->cli != cliente) || (p->val != valor)))
	{
		q = p;
		p = p->prox;
	}
	if (p == NULL)
		printf("Esse pedido nao existe!\n");
	else
	{
		q->prox = p->prox;
		free(p);
		printf("Pedido cancelado!\n");
	}
}

void listar_pedidos()
{
	lista *p;
	
	p = plista->prox;
	
	printf("\nLista de Pedidos\n");
	printf("--------------+----------------\n");
	printf("    CLIENTE   |     VALOR      \n");
	printf("--------------+----------------\n");
	while(p != NULL)
	{
		printf("  %04d    | %10.2f\n",p->cli,p->val);
		p = p->prox;
	}
}

int main(int args,char *arg[])
{
	char op;
	
	/* Criacao do LIST HEAD */
	
	plista = (lista*)calloc(1,sizeof(lista));
	plista->cli = 0;
	plista->val = INFINITO;
	plista->prox = NULL;
	
	do
	{
		op = opcao_menu();
		switch (op)
		{
			case 'I' : incluir_pedido();break;
			case 'E' : excluir_pedido();break;
			case 'L' : listar_pedidos();break;
		}		
	
		printf("\n");
		system("pause");
	}
	while (op != 'F');
	return 0;
}





