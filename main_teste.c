#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd = open("Astrologia.txt",  O_RDONLY);
	char *ret;
	int i = 0;
	while (i <= 300)
	{
		ret = get_next_line(fd);
		printf("%s", ret);
		free(ret);
		i++;
	}
	close(fd);
}
