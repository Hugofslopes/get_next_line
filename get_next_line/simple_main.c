#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{
	int				fd;
	char			*line;
	unsigned int	i;

puts("\e[41mTEST ONE CHAR\e[0m");
	fd = open("tests.txt", O_RDONLY);
	i = 1;
	/* while (i <= 4)
	{
		line = get_next_line(fd);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
		line = get_next_line(fd);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
	} */
	line = get_next_line(fd);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
	close(fd);
	puts("\n");
	puts("\n");
}