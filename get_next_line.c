/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:16:10 by jfortin           #+#    #+#             */
/*   Updated: 2015/12/11 17:46:35 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int const fd, char **line)
{
	int			i;
	char		buff[BUFF_SIZE + 1];
	int			ret;
	static char	*str = "";

	i = 0;
	if (fd >= 0 && line )
	{
		while (!ft_strchr(str, '\n') && (ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			str = ft_strjoin(str, buff);
		}
		while (str[i] != '\n' && str[i])
			i++;
		*line = ft_strndup(str, i);
		if (str[i] == '\n')
			i++;
		str = str + i;
		if (ret < 0)
			return (-1);
		return (ret > 0 ? 1 : 0);
	}
	return (-1);
}
