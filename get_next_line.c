#include "get_next_line.h"

int	readline(int fd, char **buff)
{
    int	    ret;
    char    tmp[BUFFER_SIZE + 1];
    char    *freeptr;

    while ((ret = read(fd, tmp, BUFFER_SIZE)) >= 0)
    {
	tmp[ret] = 0;
	if (ret)
	{
	    freeptr = *buff;
	    *buff = ft_strjoin(*buff, tmp);
	    free(freeptr);
	}
	else
	    return (0);
	if (ft_strchr(tmp, '\n'))
	    return (1);
    }
    return (-1);
}

int	readbuff(char **buff, char **line)
{
    char    *freeptr;
    char    *tmp;
    int	    ret;
    int	    len;

    freeptr = *buff;
    tmp = ft_strchr(*buff, '\n');
    if (!tmp)
    {
	*line = ft_strdup(*buff);
	*buff = 0;
	ret = 0;
    }
    else
    {
	len = tmp - *buff;
	*line = ft_substr(*buff, 0, len);
	len++;
	*buff = ft_substr(*buff, len, ft_strlen(*buff) - len);
	ret = 1;
    }
    free(freeptr);
    return (ret);
}

int	get_next_line(int fd, char **line)
{
    int		ret;
    static char	*buff;

    if (!buff)
	buff = ft_strdup("");
    ret = readline(fd, &buff);
    if (fd == -1 || ret == -1)
    {
	free(buff);
	buff = NULL;
	return (-1);
    }
    return (readbuff(&buff, line));
}
