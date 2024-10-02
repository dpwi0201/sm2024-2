#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int c1; 
	int c2;
	printf("Input the year: ");
	scanf("%i", &c1);
	
	c2 = (((c1%4)==0)&&(c1%100)!=0)||((c1%400)==0);
	printf("Is the year %i the leap year? %i", c1, c2);
	return 0;
}