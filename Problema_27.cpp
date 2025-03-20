//Programa p27.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>

#define TAM_MAX 50

void mover (int n, int a, int b, int c);

int main (int args, char * arg[])
{
	int n;
	printf("Numero de discos: ");
	scanf("%d ",&n);
	printf("Solucao da Torre de Hanoi com %d discos:\n",n);
	mover(n,0,2,1);
	system("PAUSE");
	return 0;
}

void mover(int n, int a,int b,int c)
{
	if (n > 0)
	{
		//mover(n-1, a, c, b,);
		mover(n-1, a, c, b);
		printf("%d -> %d \n",a,b);
		mover(n-1,c,b,a);
	}
}




