//Programa p49.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <sys\stat.h>
#include <fcntl.h>

typedef struct arvexp
{
	char info;
	struct arvexp *esq;
	struct arvexp *dir;
}arvexp;

typedef struct pilha
{
	arvexp *node;
	struct pilha *prox;
}pilha;

//Variaveis Globais
int e = -1;
char dado[100],simb;
arvexp *raiz;
pilha *topo;

//Prototipo de funcao
void expressao();

void empilha(arvexp *p)
{
	pilha *novo;
	
	novo = (pilha*)calloc(1,sizeof(pilha));
	novo->node = p;
	novo->prox = topo;
	topo = novo;
}

arvexp * desempilha()
{
	arvexp *p;
	
	if(topo == NULL)
		printf(">>> Erro: Pilha vazia");
	p = topo->node;
	topo = topo->prox;
	return p;
}

arvexp * cria_node(char c)
{
	arvexp *novo;
	
	novo = (arvexp *)calloc(1,sizeof(arvexp));
	novo->info = c;
	novo->esq = NULL;
	novo->dir = NULL;
	return novo;
}

void prox_simb()
{
	e++;
	while (dado[e] == ' ')
		e++;
	simb = dado[e];	
}

void fator()
{
	arvexp *p;
	
	if(simb == '(')
	{
		prox_simb();
		expressao();
		if(simb != ')')
			printf("Expressao incorreta\n");
	}
	else
	{
		p = cria_node(simb);
		empilha(p);
	}
	prox_simb();
}

void termo()
{
	char op;
	arvexp *p;
	
	fator();
	while((simb == '*') || (simb == '/'))
	{
		op = simb;
		prox_simb();
		fator();
		p = cria_node(op);
		p->dir = desempilha();
		p->esq = desempilha();
		empilha(p);
	}
}

void expressao()
{
	char op;
	arvexp *p;
	
	if (simb == '-')
	{
		prox_simb();
		termo();
		p = cria_node('-');
		p->dir= desempilha();
		empilha(p);
	}
	termo();
	while((simb == '+') || (simb == '-'))
	{
		op = simb;
		prox_simb();
		termo();
		p = cria_node(op);
		p->dir = desempilha();
		p->esq = desempilha();
		empilha(p);
	}
}

void travessia_preordem(arvexp *p)
{
	if(p == NULL)
		return;
	printf("%c ",p->info);
	travessia_preordem(p->esq);
	travessia_preordem(p->dir);
} 

void travessia_emordem(arvexp *p)
{
	if(p == NULL)
		return;
	travessia_emordem(p->esq);
	printf("%c ",p->info);
	travessia_emordem(p->dir);
}

void travessia_posordem(arvexp *p)
{
	if(p == NULL)
		return;
	travessia_posordem(p->esq);
	travessia_posordem(p->dir);
	printf("%c ",p->info);
}

int main(int args, char * arg[])
{
	topo = NULL;
	
	printf("Expressao: ");
	gets(dado);
	prox_simb();
	expressao();
	raiz = desempilha();
	
	printf("\nTravessia pre_ordem: ");
	travessia_preordem(raiz);
	
	printf("\nTravessia em_ordem: ");
	travessia_emordem(raiz);
	
	printf("\nTravessia pos_ordem: ");
	travessia_posordem(raiz);
	
	printf("\n\n");
	system("Pause");
	return 0;
}




















