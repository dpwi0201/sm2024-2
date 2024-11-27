#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//week12_7_1
/*char *proverb = "All that glisters is not gold.";

void setPointer(char **q)
{
	**q = *proverb;
}

int main(void) {
	char *p = 'zzz';
	setPointer(p);
	printf("%s\n", p);
}*/



//week12_7_2

char *proverb = "All that glisters is not gold.";

int main(void) {
	char **p = &proverb;
	printf("%s\n", *p);
}

