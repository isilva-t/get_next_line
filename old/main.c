#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*next_line;
	int		i;
	int		lines;
	
	lines = 1;
	i = 0;
	// include "fcntl.h" to use O_RDONLY right?
	fd = open("test.txt", O_RDONLY);
	
	//why this special case?
	if (fd == -1)
	{
		printf("error opening file");
		return (1);
	}

	while ((next_line = get_next_line(fd)))
		printf("[%d] %s", lines++, next_line);


	/*
	//WHILE 1 WHY?!?!?!?
	while (get_next_line(fd, &line ==1))
	{
		next_line = get_next_line(fd);
		if (!next_line)
			//free (next_line);
				break ;
		i++;
		printf("[%d]:%s\n", i, next_line);
		free (next_line);
		next_line = NULL;
	}*/
	close(fd);
	return (0);
}
