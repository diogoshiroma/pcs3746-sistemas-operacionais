#include "stack.h"
#include "cfs.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd = open("/sys/kernel/sys_stack/count", O_RDONLY);
	char stack_count[5];
	
	for(int i=0; i<10; i++) {
		if (lseek(fd, 0, SEEK_SET)) {
			perror("lseek");
		} else {
			int size = read(fd, stack_count, 4);
			if (size < 0) {
				perror("read");
			} else {
				stack_count[size] = 0;
			}
		}
		stack_pop();
		sleep(rand() % 5 + 1);
	}
	printf("CFS após POP\n");
	cfs();
	return 0;
}
