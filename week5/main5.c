#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int c1;
	int c2;
	
	printf("Input two integers: ");
	scanf("%i %i", &c1, &c2);
	
	printf("& result is %i\n", c1&c2);
	printf("| result is %i\n", c1|c2);
	printf("^ result is %i\n", c1^c2);
	printf("<<1 result is %i\n", c1<<1);
	printf(">>1 result is %i\n", c1>>1);
	
	return 0;
}