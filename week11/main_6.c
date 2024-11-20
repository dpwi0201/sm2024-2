#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


/*void main(void) {
	FILE *fp =NULL;
	char c;
	fp = fopen("sample.txt", "r");
	
	if(fp == NULL)
		printf("Unable to open the file\n");
		
	while(c != EOF)
	{
		c = fgetc(fp);
		putchar(c);
	}	

	fclose(fp);
} */



void main(void) {
	FILE *fp =NULL;
	char* str[50];
	int n = 50;
	fp = fopen("sample.txt", "r");
	
	if(fp == NULL)
		printf("Unable to open the file\n");
	

	fgets(str, n, fp);
	printf("%s", str);
	fgets(str, n, fp);
	printf("%s", str);
	fgets(str, n, fp);
	printf("%s", str);	
	
	fclose(fp);
}