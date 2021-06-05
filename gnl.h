/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 14:08:43 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/05 16:12:17 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, char c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
int		get_next_line(int fd, char **line);

#endif
