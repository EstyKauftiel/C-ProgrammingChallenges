#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char** argv)
{
	int sum = 0;
	for (int i = 0; i < argc; i++)
		sum += atoi(argv[i]);
	printf("%d",sum);
}