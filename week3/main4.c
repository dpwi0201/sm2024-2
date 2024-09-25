#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float a;
	float b;
	float c;
	
	printf("enter two integers : ");
	scanf("%f, %f", &a, &b);
	
	c = a / b;
	printf("%f / %f = %f", a, b, c);
	return 0;
}