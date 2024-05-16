/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:38:54 by isilva-t          #+#    #+#             */
/*   Updated: 2024/05/14 15:13:33 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *buf, char *backup_static)
{
	int		read_check;
	char	*temp;

	read_check = 1;
	while (read_check)
	{
		read_check = read(fd, buf, BUFFER_SIZE);
		if (read_check == -1)
			return (0);
		else if (read_check == 0)
			break ;
		/*********************************************************/	
		buf[read_ok] = '\0';
		/*********************************************************/	
		if (!backup_static)
			backup_static = ft_strdup("");
		/*********************************************************/		
		temp = backup_static;
		backup_static = (ft_strjoin(temp, buf));
		if (!backup_static)
			return (NULL);
		/*********************************************************/		
		free (temp);
		temp = NULL;
		/*********************************************************/	
		if (ft_strchr(buf, '\n'))
			break ;
	}
	/*********************************************************/
	return (backup_static);
}

static char	*ft_rest(char *line)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	/*********************************************************/
	temp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!temp)
		return (NULL);
	if (temp[0] == '\0')
	{
		free (temp);
		temp = NULL;
		return (NULL);
	}
	/*********************************************************/
	line[i + 1] = '\0';
	/*********************************************************/
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*backup_static;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	/*********************************************************/	
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	/*********************************************************/	
	line = ft_read_line(fd, buf, backup_static);
	free(buf);
	/*********************************************************/
	if (!line)
		return (NULL);
	/*********************************************************/	
	backup = ft_rest(line);
	/*********************************************************/
	return (line);
}
