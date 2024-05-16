/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:24:15 by isilva-t          #+#    #+#             */
/*   Updated: 2024/05/16 11:38:03 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char**av)
{
	int		i;
	int		fd1;
	char	*str;

	i = 0;
	str = "";
	fd1 = open(av[1], O_RDONLY);
	printf("+=+=+=+=+=+=+=FILE DESCRIPTOR: [ %d ]+=+=+=+=+=+=+=+=+=+= \n", fd1);
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
	while (str)
	{
		printf("1_FT_get_next_line: [ %d ] \n", i);
		str = get_next_line(fd1);
		printf ("======================= LINE_[%d]: ====================\
		\n%s===================================================================\n", ++i, str);
		free (str);
	}
	close(fd1);
}
