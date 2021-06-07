/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:04:41 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/07 14:43:53 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int		fd;
	int		readline;
	char	*line;

	(void)ac;
	if (ac == 1)
		fd = STDIN_FILENO;
	else
		fd = open(av[1], O_RDONLY);
	while ((readline = get_next_line(fd, &line) > 0))
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
		printf("read = %d\n", readline);
	}
	printf("%s\n", line);
	free(line);
	line = NULL;
	printf("read = %d\n", readline);
	return (0);
}
