/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:05:10 by jfortin           #+#    #+#             */
/*   Updated: 2016/01/26 16:56:54 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		ret;

	ret = 0;
	(void)ac;
//	fd = 0;
	fd = open(av[1], O_RDONLY);
	//fd1 = open("main.c", O_RDONLY);
	if ((ret =get_next_line(fd, &line) == 1))
		printf("%s\n", line);
	printf("%d\n", ret);
	if ((ret =get_next_line(fd, &line) == 1))
		printf("%s\n", line);
	printf("%d\n", ret);
	while(1);


	close(fd);
	return (0);
}
