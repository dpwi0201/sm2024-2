#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i1;
	
	printf("Input the second: ");
	scanf("%i", &i1);
	
	printf("The time is %i : %i", i1/60, i1%60);
	return 0;
}