#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
	float C,F;
	printf("Digite a temperatura em graus C :");
	scanf("%f", &C);
	F = (9 * C + 160) / 5;
	printf("Esta temperatura correponde a %.1f graus F\n", F);
	system("PAUSE");
	return 0;
}
