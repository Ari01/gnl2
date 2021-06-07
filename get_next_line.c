/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:37:09 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/07 14:58:03 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_from_file(int fd, char **buffer)
{
	int		readvalue;
	char	tmp[BUFFER_SIZE + 1];
	char	*freeptr;

	while ((readvalue = read(fd, tmp, BUFFER_SIZE)) >= 0)
	{
		tmp[readvalue] = 0;
		if (!*buffer)
			*buffer = ft_strdup(tmp);
		else if (*tmp)
		{
			freeptr = *buffer;
			*buffer = ft_strjoin(*buffer, tmp);
			free(freeptr);
		}
		if (!*tmp)
			return (0);
		if (ft_strchr(tmp, '\n'))
			return (1);
	}
	return (-1);
}

int		read_from_buffer(char **buffer, char **line)
{
	char	*end;
	char	*freeptr;
	int		len;
	int		ret;

	end = ft_strchr(*buffer, '\n');
	freeptr = *buffer;
	ret = 1;
	if (end == NULL)
	{
		*line = ft_strdup(*buffer);
		*buffer = ft_strdup("");
		ret = 0;
	}
	else
	{
		len = end - *buffer;
		*line = ft_substr(*buffer, 0, len);
		len++;
		*buffer = ft_substr(*buffer, len, ft_strlen(*buffer) - len);
	}
	if (!*line || !*buffer)
		ret = -1;
	free(freeptr);
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char	*buffer;
	int			ret;

	if (fd == -1)
		return (-1);
	ret = read_from_file(fd, &buffer);
	if (ret != -1)
		ret = read_from_buffer(&buffer, line);
	if (ret == -1 || (!*buffer && !ret))
	{
		free(buffer);
		buffer = NULL;
	}
	return (ret);
}
