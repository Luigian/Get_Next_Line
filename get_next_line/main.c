/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:22:41 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/08 20:35:39 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		fd;
	char	**ptr;
	int		count;
	char	c;	

	count = 0;
	fd = open("../Quixote.txt", O_RDONLY, 0);
	while (read(fd, &c, 1) > 0)
		if (c == '\n')
			++count;
	printf("%d\n", count);

	ptr = ft_stranew(count);
	close(fd);
	
	fd = open("../Quixote.txt", O_RDONLY, 0);
	get_next_line(fd, ptr);
	printf("%s\n", *ptr);
	return (0);
}
