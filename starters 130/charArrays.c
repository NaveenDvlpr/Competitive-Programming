#include<stdio.h>
#include<string.h>

int main() {
	char c[3] = "JO";
	c[10] = 'a';
	printf("%c\n", c[10]);
	printf("%d\n", sizeof(c));
	int len = strlen(c);
	
	printf("Length = %d\n", len);
	
	printf("%s", c);
	
	return 0;
}
