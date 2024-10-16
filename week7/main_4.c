#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int factorial(int n)
{
	int res = 1;
	int i;
	for(i=1;i<n+1;i++)
		res = res*i;
	return res;
}

int combination(int a, int b)
{
	int c;
	c = factorial(a)/(factorial(a-b)*factorial(b));
	return c;
}

int get_integer()
{	
	int input;
	printf("Enter the value: ");
	scanf("%i", &input);
	return input;
}


int main(int argc, char *argv[]) {
	int input1;
	int input2;
	int output;

	input1 = get_integer();
	input2 = get_integer();
	
	output = combination(input1, input2);
	
	printf("The result of C(%i, %i) is %i.", input1, input2, output);

	return 0;
}