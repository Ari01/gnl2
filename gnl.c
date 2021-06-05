/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 14:08:35 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/05 17:43:19 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int		read_from_file(int fd, char **buffer)
{
	int		readvalue;
	char	tmp[BUFFER_SIZE + 1];
	char	*freeptr;

	while ((readvalue = read(fd, tmp, BUFFER_SIZE)) >= 0)
	{
		tmp[BUFFER_SIZE] = 0;
		if (*tmp)
		{
			freeptr = *buffer;
			if (!*buffer)
				*buffer = ft_strdup(tmp);
			else
				*buffer = ft_strjoin(*buffer, tmp);
			free(freeptr);
			if (ft_strchr(tmp, '\n'))
				return (1);
		}
	}
	return (readvalue);
}

int		read_from_buffer(char **buffer, char **line)
{
	char	*end;
	char	*freeptr;
	int		len;

	end = ft_strchr(*buffer, '\n');
	freeptr = *buffer;
	if (end == NULL)
	{
		*line = ft_strdup(*buffer);
		*buffer = ft_strdup("");
		if (!*line || !*buffer)
			return (-1);
	}
	else
	{
		len = end - *buffer;
		*line = ft_substr(*buffer, 0, len);
		len++;
		*buffer = ft_substr(*buffer, len, ft_strlen(*buffer) - len);
		if (!*line || !*buffer)
			return (-1);
	}
	free(freeptr);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*buffer;
	int			readline;

	if (fd == -1)
		return (-1);
	readline = read_from_file(fd, &buffer);
	//printf("buffer = %s", buffer);
	if (*buffer && readline != -1)
	{
		//printf("reading from buffer\n");
		readline = read_from_buffer(&buffer, line);
		//printf("end read\n");
	}
	if (readline == -1 || (!*buffer && !readline))
	{
		printf("end read = %d\n", readline);
		free(buffer);
	}
	printf("read = %d\n", readline);
	return (readline);
}
