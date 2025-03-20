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

char ler_opcao();
frac obter_fracao();
void realizar_operacao(char, frac);
frac simplificar_fracao(frac);
char mostrar_resultado(frac);

int main(int args, char * arg[])
{
	char r;
	frac a;
	while (1)
	{
		r = ler_opcao();
		a = obter_fracao();
		realizar_operacao(r, a);
	}
	return 0;
}

char ler_opcao()
{
	char r;
	system("CLS");
	printf("[+] Somar\n");
	printf("[-] Subtrair\n");
	printf("[*] Multiplicar\n");
	printf("[/] Dividir\n");
	printf("[f] Fim\n");
	printf("O que deseja fazer? ");
	r = getche();
	if (r == 'f')
		exit (0);
	return r;
}

frac obter_fracao()
{
	frac a;
	printf("\nFracao: ");
	scanf(" %d %d", &(a.num), &(a.den));
	return a;
}

void realizar_operacao(char r,frac x)
{
	static frac f = {0,1};
	
	switch (r)
	{
	case '+': f.num = f.num*x.den + x.num*f.den;break;
	case '-': f.num = f.num*x.den - x.num*f.den;break;
	case '*': f.num = f.num*x.num;break;
	case '/': f.num = f.num*x.den;break;
	}
	
	switch (r)
	{
	case '+':;
	case '-':;
	case '*': f.den = f.den*x.den;break;
	case '/': f.den = f.den*x.num;break;
	}
	
	mostrar_resultado(f);
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

frac simplificar_fracao(frac f)
{
	int m;
	m= mdc(f.num,f.den);
	f.num = f.num/m;
	f.den = f.den/m;
	return f;
}

char mostrar_resultado(frac f)
{
	f = simplificar_fracao(f);
	printf("Reultado: %d / %d\n", f.num,f.den);
	system("PAUSE");
}
