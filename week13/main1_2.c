#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct student{
	int ID;
	char name[10];
	double grade;
};

int main(void){

	struct student s1 = {0, "Sookmyung", 0};

	printf("enter ID: ");
	scanf("%d", &s1.ID);
	
	printf("enter name: ");
	scanf("%s", &s1.name);

	printf("enter grade: ");
	scanf("%lf", &s1.grade);	

	
	printf("ID: %d\n", s1.ID);
	printf("name: %s\n", s1.name);
	printf("grade: %f\n", s1.grade);
	
}