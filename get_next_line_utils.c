#include "get_next_line.h"

int	ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
	i++;
    return (i);
}

char	*ft_strchr(char *s, char c)
{
    while (*s)
    {
	if (*s == c)
	    return (s);
	s++;
    }
    return (NULL);
}

char	*ft_strdup(char *s)
{
    char    *dup;
    int	    i;

    i = 0;
    dup = malloc(sizeof(*dup) * (ft_strlen(s) + 1));
    while (s[i])
    {
	dup[i] = s[i];
	i++;
    }
    dup[i] = 0;
    return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
    int	    i;
    char    *join;

    join = malloc(sizeof(*join) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    i = 0;
    while (*s1)
    {
	join[i] = *s1;
	i++;
	s1++;
    }
    while (*s2)
    {
	join[i] = *s2;
	i++;
	s2++;
    }
    join[i] = 0;
    return (join);
}

char	*ft_substr(char *s, int start, int len)
{
    int	    i;
    char    *sub;

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
