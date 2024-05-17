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
		str = get_next_line(fd1);
		printf ("======================= LINE_[%d]: ====================\
		\n%s================================\
		===================================\n", ++i, str);
		free (str);
	}
	close(fd1);
}
/* FOR TESTING PROPOSES
ft_search new line______________________________________________________________
printf("read_check before \"read\": [ %d ]\n", read_check);
printf("read_check AFTER if \"read\" == [ 0 ]!!!!!!!!\n");

BEFORE RETURN
if (read_check > 0)
    printf("READ_CHECK:[ %d ]\n",  read_check);    
printf("LAST BUFFER:[ %zd ]\n",  ft_strlen(buf));
printf("********* STATIC_VARIABLE_CONTENT_IN_FT_SEARCH_LINE ********* \
\n%s\n********************************************************\n", backup_static);

FT_GET_NEXT_LINE____________________________________________________________
before return
printf("3_STATIC__AFTER__FT_REST:\n%s\n[END_STATIC]\n", backup_static);
*/
