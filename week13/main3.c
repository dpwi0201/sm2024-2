#include <stdio.h>
#include <stdlib.h>

#define STUDENTNUM 4
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct student{
	int ID;
	int score;
};

int main(void) {
	struct student s[STUDENTNUM];
	int i;
	double sum = 0;
	double average;
	
	for (i=0;i<STUDENTNUM;i++)
	{
		printf("Input the ID: ");
		scanf("%d", &s[i].ID);
		printf("Input the score: ");
		scanf("%d", &s[i].score);
		sum = sum + s[i].score;
	
	}
	
	average = sum/4;
	printf("The average of the score: %f\n", average);

	if(s[0].score>s[1].score&&s[0].score>s[2].score&&s[0].score>s[3].score)	
	printf("The highest score - ID: %d, score: %d", s[0].ID, s[0].score);
	
	if(s[1].score>s[0].score&&s[1].score>s[2].score&&s[1].score>s[3].score)	
	printf("The highest score - ID: %d, score: %d", s[1].ID, s[1].score);

	if(s[2].score>s[1].score&&s[2].score>s[0].score&&s[2].score>s[3].score)	
	printf("The highest score - ID: %d, score: %d", s[2].ID, s[2].score);

	if(s[3].score>s[1].score&&s[3].score>s[2].score&&s[3].score>s[0].score)	
	printf("The highest score - ID: %d, score: %d", s[3].ID, s[3].score);
	
	
		
	return 0;
}