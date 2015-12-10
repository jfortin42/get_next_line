#include "get_next_line.h"

int	get_next_line(int const fd, char **line)
{
	int		i;
	char	*buf;
	size_t	ret;
	static char *str = "";

	i = 1;
	if (!(buf = (char *)malloc(sizeof(char) * BUF_SIZE + 1)))
		return (NULL);
	if (fd >= 0 && line)
	{
		while (!ft_strchr(str, '\n') && (ret = read(fd, buf, BUF_SIZE)) > 0)
		{
			buf[ret] = '\0';
			str = ft_strjoin(str, buf);
		}
		while (str[0] && str[i] && str[i - 1] != '\n')
			i++;
		*line = ft_strndup(str, i);
		str = str + i;
		free(buf);
		return (i > 1 ? 1 : 0);
	}
	return (-1);
}
