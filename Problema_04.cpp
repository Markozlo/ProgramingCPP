#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
	
	int b,c,d;
	float a,e,f;
	float v1,v2,v3,v4;
	
	a = 1.5;
	b = 4;
	c = 2;
	d = 3;
	e = 1.2;
	f = 4.3;
	
	//Determinar o valor das equassões
	v1 = (a*(c+d))/(b*(e+f));
	v2 = pow(a,(b+c))/(e+f)+d;
	v3 = (a + ((c+d)*(c+d))/(b*b)*d)*(1.0/c);
	v4 = (-b + sqrt(b*b - 4*a*c))/(2*a);
	printf("v1 = %8.3f\n",v1);
	printf("v2 = %8.3f\n",v2);
	printf("v3 = %8.3f\n",v3);
	printf("v4 = %8.3f\n",v4);
	
	system("PAUSE");
	return 0;	
}
