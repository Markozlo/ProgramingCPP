#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>

int main(int args, char* arg[])
{
	int i, n;
	char optei;
	char texto [100];
	
	do{
		system("CLS");
		printf("Entre com o texto codificado:\n");
		for (i = 0; i < 100; i++)
		{
			scanf("%c", &texto[i]);
			if (texto[i] == '.')
				break;
		}
		n = i;
		printf("Texto com %d caractere. \n", n);
		for (i = 0; i < n; i++)
			texto[i] = (5* texto[i] + 100) %256;
		printf("Texto codificado :\n");
		for (i = 0; i < n; i++)
			printf("%c", texto[i]);	
		printf("\n");
		printf("Continua? (S/N): ");
		optei = toupper(getche());
	}
	while (optei == 'S');
	printf("\n");
	system("PAUSE");
	return 0;
}
