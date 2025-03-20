#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>

typedef struct frac
{
	int num;
	int den;
}	frac;

void obter_fracoes(frac*, frac*);
void somar_fracoes(frac, frac);
void subtrair_fracoes(frac, frac);
void multiplicar_fracoes(frac, frac);
void dividir_fracoes(frac, frac);
void simplificar_fracao(frac);

int main(int args, char* arg[])
{
	char r;
	frac a,b;
	
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
		obter_fracoes(&a, &b);
		switch (r)
		{
			case '1': somar_fracoes(a,b); break;
			case '2': subtrair_fracoes(a,b); break;
			case '3': multiplicar_fracoes(a,b); break;
			case '4': dividir_fracoes(a,b); break;
		}
	}
	return 0;
}

void obter_fracoes(frac *a, frac *b)
{
	printf("\n1a fracao: ");
	scanf("%d %d", &((*a).num), &((*a).den));
	printf("2a fracao: ");
	scanf("%d %d", &((*b).num), &((*b).den));
	return;
}

void somar_fracoes(frac x, frac y)
{
	frac f;
	f.num = x.num*y.den + y.num*x.den;
	f.den = x.den*y.den;
	simplificar_fracao(f);
}

void subtrair_fracoes(frac x, frac y)
{
	frac f;
	f.num = x.num*y.den - y.num*x.den;
	f.den = x.den*y.den; 
	simplificar_fracao(f);
}

void multiplicar_fracoes(frac x, frac y)
{
	frac f;
	f.num = x.num*y.num;
	f.den = x.den*y.den;
	simplificar_fracao(f);
}

void dividir_fracoes(frac x, frac y)
{
	frac f;
	f.num = x.num*y.den;
	f.den = x.den*y.num;
	simplificar_fracao(f);
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

void simplificar_fracao(frac f)
{
	int m;
	m = mdc(f.num, f.den);
	f.num = f.num/m;
	f.den = f.den/m;
	printf("Resultado: %d / %d\n", f.num, f.den);
	system("PAUSE");
}
