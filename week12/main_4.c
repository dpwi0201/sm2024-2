#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void){
	int i;
	int grade[5];
	
	for (i=0;i<5;i++)
	{
		printf("Input value - grade[%i] = ", i);
		scanf("%d", &grade[i]);
	}
	
	int *a = grade;
	int b = 0;
	
	for (i=0;i<5;i++)
	{
		printf("grade[%i] = %i\n", i, a[i]);
		b = b + a[i];
	}
	
	int c;
	c = b/5;
	printf("average : %i", c);
}