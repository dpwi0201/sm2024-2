#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct point{
	int x;
	int y;
};

int getArea(struct point *pPtr1, struct point *pPtr2){
	int result;
	
	result = (pPtr2->x-pPtr1->x)*(pPtr2->y-pPtr1->y);
	
	return result;
}

int main(int argc, char *argv[]) {
	int area;
	struct point p1, p2;
	struct point *pPtr1, *pPtr2;
	
	pPtr1 = &p1;
	pPtr2 = &p2;
	
	printf("Input the coordinate p1 (x y):");
	scanf("%d %d", &pPtr1->x, &pPtr1->y);
	
	printf("Input the coordinate p2 (x y):");
	scanf("%d %d", &pPtr2->x, &pPtr2->y);	
	
	area = getArea(pPtr1, pPtr2);
	
	printf("Area: %d", area);
	
	return 0;
}