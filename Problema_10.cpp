#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(int argc, char *argv[])
{
	int A,B;
	int q,r;
	
	printf("Digite o valor de A e B: ");
	scanf("%d %d", &A,&B);
	q = 0;
	while (B <= A)
	{
		q++;
		A = A - B;
	}
	r = A;
	printf("Quociente = %d e Resto = %d\n", q,r);
	system("PAUSE");
	return 0;
}
