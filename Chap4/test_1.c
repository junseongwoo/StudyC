#include <stdio.h>

int main(void)
{
	int res;

	int a = sizeof(short);
	int b = sizeof(long);

	res = (a > b) ? 1 : 0;

	res = (char)(res == 1) ? "short" : "long";

	printf("%s", res);

	
	return 0;
}