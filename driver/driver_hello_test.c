#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
 
 
int main(int argc, char *argv[])
{
	int param1 = 1, param2 = 2;
	int fd;
	printf("enter driver test with param %d %d\n", param1, param2);
	char *hello = "/dev/hellohello";
 
	if((fd = open(hello, O_RDWR | O_NOCTTY | O_NDELAY)) < 0)
	{
		printf("open %s failed\n", hello);
	}
	else
	{
		printf("%s fd is %d \n", hello, fd);
		ioctl(fd, param1, param2);
	}
	close(fd);
	return 1;
}
