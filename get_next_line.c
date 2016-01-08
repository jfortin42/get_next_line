/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:16:10 by jfortin           #+#    #+#             */
/*   Updated: 2016/01/06 17:52:27 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int const fd, char **line)
{
	int				i;
	char			buff[BUFF_SIZE + 1];
	int				ret;
	static t_lst	*beginlist = NULL;
	t_lst			*tmp;
	t_fd			*data;

	tmp = beginlist;
	if (beginlist)
	{
		while (tmp->next && (data = (t_fd *)tmp->data) && data->fd != fd)
			tmp = tmp->next;
	}
	if (!beginlist || fd != data->fd)
	{
		if (!(data = (t_fd *)malloc(sizeof(t_fd))))
			return (-1);
		data->str = "";
		data->fd = fd;
		if (!beginlist)
			beginlist = ft_create_elem((void *)data);
		else
			tmp->next = ft_create_elem((void *)data);
		data = (t_fd *)beginlist->data;
		tmp = data->fd != fd ? tmp->next : beginlist;
	}

//  si (fin du fichier = return (0))
//  	Suprimer maillon actuel;

	i = 0;
	if (fd >= 0 && line )
	{
		data = (t_fd *)tmp->data;
		while (!ft_strchr(data->str, '\n') && (ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			data->str = ft_strjoin(data->str, buff);
		}
		while (data->str[i] != '\n' && data->str[i])
			i++;
		*line = ft_strndup(data->str, i);
		if (data->str[i] == '\n')
			i++;
		data->str = data->str + i;
		if (ret < 0)
			return (-1);
		return (ret > 0 ? 1 : 0);
	}
	return (-1);
}
