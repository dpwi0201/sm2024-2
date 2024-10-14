#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int answer;
	int input;
	int trial;
	
	answer = 50;
	trial = 0;
		
	do 
	{
		printf("Guess a number: ");
		scanf("%i", &input);
		
		if (input < answer)
		{
			printf("Low!\n");
			trial = trial + 1;
		}
		else if (input > answer)
		{
			printf("high!\n");
			trial = trial + 1;
		}

	} while (input != answer);

		trial = trial + 1;
		printf("Congratulation! Trials: %i", trial);


	return 0;
}