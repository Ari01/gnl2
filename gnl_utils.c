/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:37:10 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/05 17:28:33 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(*dup) * (ft_strlen(s) + 1));
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (c == *s)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*sub;
	int		i;

	sub = malloc(sizeof(*sub) * (len + 1));
	i = 0;
	while (i < len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = 0;
	return (sub);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		s1len;
	int		s2len;
	int		i;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	join = malloc(sizeof(*join) * (s1len + s2len + 1));
	i = 0;
	while (*s1)
	{
		join[i] = *s1;
		s1 += 1;
		i++;
	}
	while (*s2)
	{
		join[i] = *s2;
		s2 += 1;
		i++;
	}
	join[i] = 0;
	return (join);
}
