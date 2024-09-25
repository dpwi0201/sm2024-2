#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char c;
	int i1;
	int i2;
	
	printf("enter a character : ");
	scanf("%c", &c);
	
	i1 = c;
	i2 = i1 + 1;
	
	printf("the next character of %c (%d) is %c (%d)", i1, i1, i2, i2);
	
	
	return 0;
}