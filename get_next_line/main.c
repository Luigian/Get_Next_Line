/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:22:41 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/16 22:36:28 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		fd1;
	int		fd2;
	char	*ptr;
	int		ret1;
	int		ret2;

	ret1 = 1;
	ret2 = 1;
	fd1 = open("../Quixote.txt", O_RDONLY, 0);
	fd2 = open("../Iliad.txt", O_RDONLY, 0);
	while (ret1 > 0 || ret2 > 0)
	{
		if (ret1)
		{
			ret1 = get_next_line(fd1, &ptr);
			printf("[Q]");
			printf("%s\n", ptr);
			free(ptr);
		}
		if (ret2)
		{
			ret2 = get_next_line(fd2, &ptr);
			printf("[I]");
			printf("%s\n", ptr);
			free(ptr);
		}
	}
	return (0);
}

/*
#include "get_next_line.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*ptr;
	
	while (--ac)
	{
		av++;
		if ((fd = open(*av, O_RDONLY)) < 0)
			fd = 0;
		while ((ret = (get_next_line(fd, &ptr))) == 1)
		{
			ft_putendl(ptr);
			free(ptr);
//			ft_putnbr(ret);
		}
		free(ptr);
//		ft_putnbr(ret);
//		ft_putchar('\n');
	}
//	while (1);
	return (0);
}*/
