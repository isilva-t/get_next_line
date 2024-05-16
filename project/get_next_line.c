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
	//(pelo menos) funcione, uma vez que se for menos que zero
	//nao vai funcionar
	read_check = 1;
	//enquanto eu tenho read_check

	while (read_check)
	{
printf("read_check before \"read\": [ %d ]\n", read_check);
		//read_check recebe o nr de caracteres lidos
		read_check = read(fd, buf, BUFFER_SIZE);

		//se o read der erro -1, retorna NULL, nao ha linha.
		if (read_check == -1)
			return (NULL);
		// se o meu read_check for zero, nao ha mais nada a ler
		//break while
		else if (read_check == 0)
		{
printf("read_check AFTER \"read\" == [ 0 ]!!!!!!!!\n");
			break ;
		}
		//o final do meu buffer, leva um \0 terminator
		buf[read_check] = '\0';
		
		// se nao tenho a backup_static
		// a backup static e'um strdup vazio
		if (!backup_static)
			backup_static = ft_strdup("");
		
		// o meu pointer temporario, recebe o pointer de backup static
		// para poder dar free mais tarde, tendo em conta que vou usar
		// malloc a seguir
		temp_to_free = backup_static;
		
		// a backup_static, recebe o join
		// da temp to free, e do buffer
		backup_static = (ft_strjoin(temp_to_free, buf));
		if (!backup_static)
			return (NULL);
			
		// libertamos a memoria alocada em temp to free
		// uma vez que já temos a backup_static com o buffer
		// e definimos o pointer como NULL
		free (temp_to_free);
		temp_to_free = NULL;

		// se, no meu buffer eu encontrar quebra de linha
		// break while
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
	// enquanto houver, e nao for quebra de linha, i++
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	// se caractere atual for \0 terminattor, retorna NULL
	// pois nao ha quebra de linha
	if (line[i] == '\0')
		return (NULL);
	
	// o meu resto, atraves da substr,
	// vai buscar dados desde a quebra de linha, ate ao final
	// dos dados existentes
	rest = ft_substr(line, i + 1, ft_strlen(line) - i);
	// uma vez alocada memoria, proteger a alocacao
	if (!rest)
		return (NULL);
	// caso o array criado esteja vazio
	// dar free, recebe NULL, e return NULL
	if (!rest[0])
	{
		free (rest);
		rest = NULL;
		return (NULL);
	}
	// feito ultimo caractere do resto com \0 terminator
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
