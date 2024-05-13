/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <username@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:07:40 by username          #+#    #+#             */
/*   Updated: 2024/05/10 19:26:59 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_ultra_calloc(size_t mem, size_t size)
{
	char	*ptr;
	int		i;
	
	i = 0;
	ptr = malloc(sizeof(mem * size));
	if (!ptr)
		return (NULL);
	while (i < mem * size)
		ptr[i++] = '\0';
	return ((void *)ptr);
}



void	ft_print_newline_helper(char *buffer)
{
	while (*buffer)
	{
		if (*buffer == '\n')
			*buffer = '\\';
		printf("%c", *buffer);
		buffer++;
	}
}

static char	*ft_read_from_file(int fd)
{
	int		rd_bytes;
	char	*str;
	static int	count = 1;

	printf("MalLOC[%d]---", count++);
	str = (char *)ft_ultra_calloc((BUFFER_SIZE + 1), 1);
	if (!str)
		return (NULL);
	rd_bytes = read(fd, str, BUFFER_SIZE);
	ft_print_newline_helper(str);
	if (rd_bytes <= 0)
		return (free(str), NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = ft_read_from_file(fd);
	return (buffer);

}
int	main(void)
{
	int		fd;
	char	*next_line;
	int		i;
	
	i = 0;
	// include "fcntl.h" to use O_RDONLY right?
	fd = open("test.txt", O_RDONLY);
	
	//why this special case?
	if (fd == -1)
	{
		printf("error opening file");
		return (1);
	}
	//WHILE 1 WHY?!?!?!?
	while (1)
	{
		next_line = get_next_line(fd);
		if (!next_line)
			//free (next_line);
				break ;
		i++;
		printf("[%d]:%s\n", i, next_line);
		free (next_line);
		next_line = NULL;
	}
	close(fd);
	return (0);
}
