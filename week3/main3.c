#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char c1;
	char c2;
	
	printf("enter a character : ");
	scanf("%c", &c1);
	
	c2 = c1 + 1;
	printf("next character of %c (%d) is %c (%d)", c1, c1, c2, c2);

	                                                   
	return 0;
}