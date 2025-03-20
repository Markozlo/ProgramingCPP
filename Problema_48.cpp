//Programa p48.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <sys\stat.h>
#include <fcntl.h>

typedef struct arvore
{
	char nome[10];
	struct arvore *pai;
	struct arvore *esq;
	struct arvore *dir;
}arvore;

arvore *Raiz;

void incluir_nome(char novo[])
{
	arvore *p,*q,*r;
	
	p = (arvore*)calloc(1,sizeof(arvore));
	
	strcpy(p->nome,novo);
	p->esq = NULL;
	p->dir = NULL;
	
	if(Raiz == NULL)
		Raiz = p;
	else
	{
		q = Raiz;
		while (q != NULL)
		{
			r = q;
			if(strcmp(novo,q->nome)<=0)
				q = q->esq;
			else
				q = q->dir;
		}
		if(strcmp(novo,r->nome)<=0)
			r->esq = p;
		else
			r->dir = p;
		p->pai = r;		
	}	
}

void mostrar_arvore(arvore *p)
{
	if(p == NULL)
		return;
	mostrar_arvore(p->esq);
	printf("%s\n",p->nome);
	mostrar_arvore(p->dir);
}

int main(int args, char * arg[])
{
	char op,novo[10];
	
	Raiz = NULL;
	
	do
	{
		printf("Nome -> ");
		scanf("%s",&novo);
		if(strcmp(novo,"fim") == 0)
			break;
		incluir_nome(novo);
		printf("Relacao de assinantes: \n");
		mostrar_arvore(Raiz);
		printf("\n");
	}
	while(1);
	printf("\n");
	system("Pause");
	return 0;
}

























