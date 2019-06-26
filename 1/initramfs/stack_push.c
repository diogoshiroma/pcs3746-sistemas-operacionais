#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "cfs.h"

int main()
{
	for(int i=0; i<10; i++) {
		int value = rand() % 100;	
		stack_push(value);
		sleep(rand() % 4 + 1);
	}
	printf("CFS após PUSH\n");
	cfs();
	return 0;
}
