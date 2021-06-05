/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:04:41 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/05 17:39:14 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int		fd;
	char	*line;

	fd = open("3balls.rt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	return (0);
}
