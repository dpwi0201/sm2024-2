#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int sumTwo(int a, int b)
{
	
	return (a + b);
}

int square(int n)
{
	return (n*n);
}

int get_max(int x, int y)
{

	if(x > y)
		return(x);
	else
		return(y);
	
}



int main(int argc, char *argv[]) {
	int input1, input2;
	int Sum, Square, Max;
	
	printf("Enter the integers: ");
	scanf("%i %i", &input1, &input2);
	
	Sum = sumTwo(input1, input2);
	Square = square(input1);
	Max = get_max(input1, input2);
	
	
	printf("Result - Sum: %i, Square: %i, Max: %i", Sum, Square, Max);
	return 0;
}