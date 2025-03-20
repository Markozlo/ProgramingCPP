#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>

int main(int args, char * arg[])
{
	char optei;
	int erro;
	
	do
	{
		system("CLS");
		printf("A. Exibir o conteudo da pasta\n");
		printf("B. Modificar a hora do sistema\n");
		printf("C. Modificar a data do sistema\n");
		printf("X. Terminar execusao\n");
		printf("Escolha: ");
		do
		{
			erro = 0;
			optei = toupper(getche());
			if (optei == 'A')
				system("\nDIR");
			else if (optei == 'B')
				system("\nTIME");
			else if (optei == 'C')
				system("\nDATE");
			else if (optei == 'X')
				;
			else			
			{
				putch('\a');
				putch('\b');
				erro = 1;
			}			
		}
		while (erro ==1);
		printf("\n");
		system("PAUSE");
	}
	while (optei != 'X');
	//system("PAUSE");
	return 0;
}
