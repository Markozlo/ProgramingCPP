#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>

#define MAXIMO 50
#define ENTRAR "Entre com N e a base B: "
#define EXIBIR "Representacao de %d na base %d = "

int main (int args, char* arg[])
{
	int N,B;
	int i,quoc,resto;
	int digito[MAXIMO];
	
	printf(ENTRAR);
	scanf("%d %d" , &N,&B);
	for (quoc = N,i = 0; quoc >= B; i++)
	{
		resto = quoc % B;
		quoc = quoc / B;
		digito[i] = resto;
	}
	digito[i] = quoc;
	printf(EXIBIR, N,B);
	for (; i >= 0; i--)
		printf("%d", digito[i]);
	printf("\n");
	system("PAUSE");
	return 0;
}
