#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
	
	int a = 2, b = 3, c = 1;
	float delta,x1,x2;
	
	delta = b*b - 4*a*c;
	printf("A equação %s\n",
	(delta >=0)?
	"possui raizes reais" :
	"não possui raizes reais");
	
	if (delta >= 0 )
	{
		printf("As raizes são %s\n",
		(delta > 0)? "diferentes" : "iguais");
		x1 = (-b + sqrt(delta))/(2*a);
		x2 = (-b - sqrt(delta))/(2*a);
		printf("Raiz x1 = %f\n",x1);
		printf("Raiz x2 = %f\n",x2);
	}
	system("PAUSE");
	return 0;
}
