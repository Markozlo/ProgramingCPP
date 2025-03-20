//Programa p28.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>

#define TAM_MAX 50

void mostrar_polinomio(int n, float *c, char p)
{
	int i;
	printf("\n%c(x) = ",p);
	for (i = 0; i <= n; i++)
		if (i == 0)
			printf("%.1f ",c[i]);
		else
		{
			if (c[i] > 0)
				printf("+");
			if (i == 1)
				printf("%.1f*x ",c[i],i);
			else 
				printf("%.1f*x^%d ",c[1],i);
		}
	printf("\n");
}

int main(int args, char*arg[])
{
	int i,n;
	float *c;
	char p;
	printf("Nome do polinomio: ");
	scanf("%c", &p);
	printf("Grau do polinomio: ");
	scanf("%d",&n);
	c = (float *)calloc(n+1,sizeof(float));
	printf("COeficiente do polinomio: ");
	for (i = 0; i <= n; i++)
		scanf("%f",&c[i]);
	mostrar_polinomio(n,c,p);
	system("pause");
	return 0;
}




