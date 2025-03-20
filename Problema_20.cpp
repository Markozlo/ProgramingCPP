#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>

void obter_fracoes();
void somar_fracoes(int x, int y, int u, int v);
void subtrair_fracoes(int x, int y, int u, int v);
void multiplicar_fracoes(int x, int y, int u, int v);
void dividir_fracoes(int x, int y, int u, int v);
void simplificar_fracao(int x, int y);

int a,b,c,d;

int main(int args, char* arg[])
{
	char r;
	
	while (1)
	{
		system("CLS");
		printf("1. Somar\n");
		printf("2. Substrair\n");
		printf("3. Multiplicar\n");
		printf("4. Dividir\n");
		printf("9. Fim\n");
		printf("O que deseja? ");
		r = getche();
		if(r == '9')
			break;
		obter_fracoes();
		switch (r)
		{
			case '1': somar_fracoes(a,b,c,d); break;
			case '2': subtrair_fracoes(a,b,c,d); break;
			case '3': multiplicar_fracoes(a,b,c,d); break;
			case '4': dividir_fracoes(a,b,c,d); break;
		}
	}
	return 0;
}

void obter_fracoes()
{
	printf("\n1a fracao: ");
	scanf("%d %d", &a, &b);
	printf("2a fracao: ");
	scanf("%d %d", &c, &d);
	return;
}

void somar_fracoes(int x, int y, int u, int v)
{
	int n,d;
	n = x*v + u*y;
	d = y*v;
	simplificar_fracao(n, d);
}

void subtrair_fracoes(int x, int y, int u, int v)
{
	int n,d;
	n = x*v - u*y;
	d = y*v;
	simplificar_fracao(n,d);
}

void multiplicar_fracoes(int x, int y, int u, int v)
{
	int n,d;
	n = x*u;
	d = y*v;
	simplificar_fracao(n,d);
}

void dividir_fracoes(int x, int y, int u, int v)
{
	int n,d;
	n = x*v;
	d = y*u;
	simplificar_fracao(n,d);
}

int mdc(int x, int y)
{
	int r;
	while (r != 0)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

void simplificar_fracao(int x, int y)
{
	int m,n,d;
	m = mdc(x, y);
	n = x/m;
	d = y/m;
	printf("Resultado: %d / %d\n", n, d);
	system("PAUSE");
}
