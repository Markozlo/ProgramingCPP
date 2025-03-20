#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>

int MDC(int A, int B)
{
	int r;
	
	while (B != 0)
	{
		r = A % B;
		A = B;
		B = r;
	}
	return A;
}

int main(int args, char * arg[])
{
	int A,B,m;
	char c;
	
	do
	{
		printf("Digite os valores de A e B: ");
		scanf("%d %d", &A, &B);
		m = MDC(A,B);
		printf("MDC(%d, %d) = %d\n", A, B, m);
		printf("Continua? (S/N)");
		c = getche();
		printf("\n");
	}
	while ((c == 'S') || (c == 's'));
	system("PAUSE");
	return 0;
}
