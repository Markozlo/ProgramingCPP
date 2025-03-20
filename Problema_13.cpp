#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>

int bissexto(int ano)
{
	if ( ( (ano %100 != 0) && (ano % 4 == 0) ) ||
		 ( (ano %100 == 0) && (ano % 400 == 0)))
		return 1;
	else
		return 0;
}

int data_juliana(int dia, int mes, int ano)
{
	int ndias;
	
	ndias = dia;
	switch (mes-1)
	{
		case 12: ndias += 31;
		case 11: ndias += 30;
		case 10: ndias += 31;
		case  9: ndias += 30;
		case  8: ndias += 31;
		case  7: ndias += 31;
		case  6: ndias += 30;
		case  5: ndias += 31;
		case  4: ndias += 30;
		case  3: ndias += 31;
		case  2: ndias += 28 + bissexto(ano);
		case  1: ndias += 31;		
	}
	return ndias;
}

int main(int args, char * arg[])
{
	char optei;
	int dia,mes,ano;
	int ndias;
	
	do
	{
		system ("CLS");
		printf("Entre com os valores de");
		printf("dia, mes, ano de uma data: ");
		scanf("%d %d %d", &dia, &mes, &ano);
		ndias = data_juliana(dia,mes,ano);
		printf("De 01/01/%04d a %02d/%02d/%04d\n", ano, dia, mes, ano);
		printf("trsncorreram-se %d dias\n", ndias);
		printf("Continua? (S/N): ");
		optei = toupper(getche());
	}
	while (optei == 'S');
	printf("\n");
	system("PAUSE");
	return 0;
}
