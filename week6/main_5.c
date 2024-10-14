#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a;
	int b;
	char c;
	
	printf("Enter the calculation: ");
	scanf("%i %c %i", &a, &c, &b);
	
	
	if (c == 43) // +
		printf("= %i", a+b);
		
	else if (c == 45) // -
		printf("= %i", a-b);
	
	else if (c == 47) // /
		printf("= %i", a/b);
	
	else if (c == 42) // *
		printf("= %i", a*b);
		
	return 0;
}