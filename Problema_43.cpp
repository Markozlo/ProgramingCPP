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
	int dig;
	struct lista *prox;
	struct lista *prev;
}lista;

lista *ini[3], *fim[3];

char opcao_menu()
{
	system("cls");
	printf(" (L)er numero\n");
	printf(" (M)ostrar soma\n");
	printf(" (F)im\n");
	printf("> ");
	return (toupper(getche()));
}

void zerar_numeros()
{
	int i;
	
	for (i = 0; i < 3; i++)
	{
		ini[i] = NULL;
		fim[i] = NULL;
	}
}

void incluir_inicio(int index, int digito)
{
	lista *p;
	
	p = (lista *)calloc(1,sizeof(lista));
	
	p->dig = digito;
	p->prox = NULL;
	p->prev = NULL;
	
	if (ini[index]  == NULL)
		fim[index] ->prev = p;
	else
	{
		ini[index] ->prev = p;
		p->prox = ini[index];
	}
	ini[index] = p;
}

void incluir_final(int index, int digito)
{
	lista *p;
	
	p = (lista *)calloc(1,sizeof(lista));
	
	p->dig = digito;
	p->prox = NULL;
	p->prev = NULL;
	
	if (fim[index] == NULL)
		ini[index] = p;
	else
	{
		fim[index]->prox = p;
		p->prev = fim[index];
	}
	fim[index] = p;
}

void digitos_numero(int n)
{
	int d;
	
	printf("\nDigitos de Num %d (-1, para termonas) : \n", n+1);
	while (1)
	{
		scanf("%d",&d);
		if (d == 1) break;
		incluir_final(n,d);
	}
}

void ler_numeros()
{
	zerar_numeros();
	digitos_numero(0);
	digitos_numero(1);
}

void mostra_numero(char *s, lista *p)
{
	printf("\n%s = ",s);
	while (p != NULL)
	{
		printf("%d",p->dig);
		p = p->prox;	
	}	
}

void somar_numeros()
{
	lista *p1,*p2;
	int soma,vai1;
	
	ini[2] = fim[2] = NULL;
	
	p1 = fim[0];
	p2 = fim[1];
	
	vai1 = 0;
	while ((p1 != NULL) && (p2 != NULL))
	{
		soma = vai1 +  (p1->dig + p2->dig);
		vai1 = ((soma >= 10)? 1 : 0);
		soma = soma %10;
		incluir_inicio(2,soma);
		p1 = p1->prev;
		p2 = p2->prev;		
	}
	if (p1 == NULL)
		while (p2 != NULL)
		{
			soma = vai1 + p2->dig;
			vai1 = soma % 10;
			incluir_inicio(2,soma);
			p2 = p2->prev;
		}
		if (p2 == NULL)
		while (p1 != NULL)
		{
			soma = vai1 + p1->dig;
			vai1 = ((soma >= 10)? 1:0);
			soma = soma % 10;
			incluir_inicio(2,soma);
			p1 = p1->prev;
		}
}

void mostrar_soma()
{
	mostra_numero("Num1", ini[0]);
	mostra_numero("Num2", ini[1]);
	somar_numeros();
	mostra_numero("Soma", ini[2]);
}

int main (int args,char *arg[])
{
	char op;
	
	zerar_numeros();
	
	do
	{
		op = opcao_menu();
		switch (op)
		{
			case 'L' : ler_numeros(); break;
			case 'M' : mostrar_soma(); break;
		}
		printf("\n");
		system("pause");
	}
	while (op != 'F');
	return 0;
}








