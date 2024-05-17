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

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h> 

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*file1 = "./btx1";
	char	*file2 = "./btx2";
	char	*str;

	fd1 = open(file1, O_RDONLY);
	fd2 = open(file2, O_RDONLY);
	str = "";
	while (str)
	{
		str = get_next_line(fd1);
		printf ("FD [ %d ]\n%s==\n", fd1, str);
		free(str);
		str = get_next_line(fd2);
		printf ("FD [ %d ]\n%s==\n", fd2, str);
		free(str);
	}
	close(fd1);
	return (0);
}
