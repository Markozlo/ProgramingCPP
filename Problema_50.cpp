//Programa p50.c
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
	int menor, maior;
	char acao[3];
	struct arvore *pai;
	struct arvore *filho;
	struct arvore *irmao;
}arvore;

//Variaveis Globais
arvore *raiz;
int cap_menor,		//capacidade menor do balde
	cap_maior,		//capacidade maior do balde
	qtd_solucao,	//quantidade desejada no balde maior 
	solucao_ok,		//quantidade se uma solucao foi encontrada
	num_nodes;		//tamanho da arvore gerada

int existe_node(arvore *p, int c_menor, int c_maior)
{
	while (p != NULL)
	{
		if ((p->menor == c_menor) && (p->maior == c_maior))
			return 1;
		p = p->pai;
	}
	return 0;
}

void mostrar_solucao(arvore *p)
{
	if (p == NULL)
		return;
	mostrar_solucao(p->pai);
	printf("%s ", p->acao);
}

void verifica_solucao(arvore *p)
{
	if (p->maior == qtd_solucao)
	{
		printf("\nSequencia de acoes:\n");
		mostrar_solucao(p);
		printf("\nTamanho da arvore gerada = %d nos", num_nodes);
		solucao_ok = 1;
	}
}

void novo_node(arvore *p, int c_menor, int c_maior, char acao[])
{
	arvore *novo;
	
	//Verifica se ja existe, no caminho até a raiz, o novo no
	if (existe_node(p,c_menor,c_maior) == 1)
		return;
		
		num_nodes++;
		
		novo = (arvore*)calloc(1,sizeof(arvore));
		novo->menor = c_menor;
		novo->maior = c_maior;
		strcpy(novo->acao,acao);
		novo->pai = p;
		novo->filho = NULL;
		novo->irmao = NULL;
		if (p->filho == NULL)
			p->filho = novo;
		else
		{
			p = p->filho;
			while (p->irmao != NULL)
				p = p->irmao;
			p->irmao = novo;
		}
		//Verifica se o novo no e solucao do problema
		verifica_solucao(novo);
}

void expande_node(arvore *p)
{
	int falta;
	
	//Acao E1
	if (p->menor < cap_menor)
		novo_node(p,cap_menor,p->maior,"E1");
	
	//Acao E2
	if (p->maior < cap_maior)
		novo_node(p,p->menor,cap_maior,"E2");
	
	//Acao V1
	if (p->menor > 0)
		novo_node(p,0,p->maior,"V1");
	
	//Acao V2
	if (p->maior > 0)
		novo_node(p,p->menor,0,"V2");
		
	//Acao T12
	if ((p->menor > 0) && (p->maior < cap_maior))
	{
		falta = cap_maior - p->maior;
		if (p->menor >= falta)
			novo_node(p,p->menor-falta,cap_maior,"T12");
		else
			novo_node(p,0,p->maior+p->menor,"T12");		
	}
	//Acao T21
	if ((p->maior > 0) && (p->menor < cap_menor))
	{
		falta = cap_menor - p->menor;
		if (p->maior >= falta)
			novo_node(p,cap_menor,p->maior-falta,"T21");
		else 
			novo_node(p,p->menor+p->maior,0,"T21");
	}	
}

void procura_cega(arvore *p)
{
	if ((p == NULL) || (solucao_ok == 1))
		return;
	expande_node(p);
	procura_cega(p->irmao);
	procura_cega(p->filho);	
}

int main(int args, char *arg[])
{
	//Arvore inicial
	raiz = (arvore*)calloc(1,sizeof(arvore));
	raiz->menor = 0;
	raiz->maior = 0;
	raiz->pai = NULL;
	raiz->irmao = NULL;
	
	//Numero de nos na arvore
	num_nodes = 1;
	solucao_ok = 0;
	
	printf("Capacidade dos baldes: ");
	scanf("%d %d", &cap_menor,&cap_maior);
	printf("Quantos litros deseja no balde maior: ");
	scanf("%d", &qtd_solucao);
	
	//Algoritimo de procura cega
	procura_cega(raiz);
	
	printf("\n\n");
	system("Pause");
	return 0;
}














