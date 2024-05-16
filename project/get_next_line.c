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

static char	*ft_search_line(int fd, char *buf, char *backup_static)
{
	int		read_check;
	char	*temp_to_free;

	//read_check comeca por ter valor 1, para que o primeiro while
	//{pelo menos} funcione, uma vez que se for menos que zero
	read_check = 1;
	//enquanto eu tenho read_check
printf("1_FT_SEARCH_LINE: \n");
	while (read_check)
	{
printf("read_check before \"read\": [ %d ]\n", read_check);
		//read_check recebe o nr de caracteres lidos
		read_check = read(fd, buf, BUFFER_SIZE);

		//se o read der erro, retorna NULL pointer, nao ha linha.
		if (read_check == -1)
			return (NULL);
		// se o meu read_check for zero, nao ha mais nada a ler
		//para o while
		else if (read_check == 0)
		{
printf("read_check AFTER \"read\" == [ 0 ]!!!!!!!!\n");
			break ;
		}
		buf[read_check] = '\0';
	
		if (!backup_static)
			backup_static = ft_strdup("");
	
		temp_to_free = backup_static;
		backup_static = (ft_strjoin(temp_to_free, buf));
		if (!backup_static)
			return (NULL);
		
		free (temp_to_free);
		temp_to_free = NULL;

		if (ft_strchr(buf, '\n'))
			break ;
	}

if (read_check > 0)
	printf("READ_CHECK:[ %d ]\n",  read_check);	
printf("LAST BUFFER:[ %zd ]\n",  ft_strlen(buf));
printf("********* STATIC_VARIABLE_CONTENT_IN_FT_SEARCH_LINE ********* \
\n%s\n********************************************************\n", backup_static);

	return (backup_static);
}

static char	*ft_rest(char *line)
{
	int		i;
	char	*rest;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);

	rest = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!rest)
		return (NULL);
	//- preciso prevencao para se o array criado esta' vazio
	// se sim, dar free, array a NULL, e return NULL
	if (!rest[0])
	{
		free (rest);
		rest = NULL;
		return (NULL);
	}
	// preencher ultimo caractere do resto com \0 terminator
	line[i + 1] = '\0';

	return (rest);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*backup_static;

	//se o fd for menor que zero(erro) 
	//ou 
	//o buffer_size menor ou igual a zero
	//retorna NULL
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	//aloca memoria para o buffer, com tamanho do buffer size mais \0 terminator
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);

	//linha a retornar recebe read_line, com parametros: valor fd, buffer, e backup_static
	line = ft_search_line(fd, buf, backup_static);
	free(buf);
	if (!line)
		return (NULL);

	//depois de ter a linha a retornar, vamos buscar os restantes caracteres ao buffer
	//(se existirem) no nosso ponteiro static
	backup_static = ft_rest(line);
printf("3_STATIC__AFTER__FT_REST:\n%s\n[END_STATIC]\n", backup_static);

	//retorna a linha lida (ou ficheiro se chegar a EOF)
	return (line);
}
