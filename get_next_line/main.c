/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:22:41 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/26 10:54:41 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*ptr;
	int		line;
	int		*lines;
	int		i;
	int		j;
	int 	*fds;
	int		n;
	int		f;

	if (argc == 1)
	{
		line = 0;
		while ((ret = get_next_line(0, &ptr)) > 0)
		{
			printf("[Stdin] [FD:0] [RetVal:%d] [Line#%d] $%s\n", ret, ++line, ptr);
			ft_strdel(&ptr);
		}
		printf("[Stdin] [FD:0] [RetVal:%d] [Line#%d] %s", ret, ++line, ptr);
		if (ret == -1)
			printf(" ERROR\n");
		else if (ret == 0)
			printf(" END OF STDIN\n");
		close(0);
	}
	else if (!strcmp(argv[argc - 1], "mix"))
	{
		 printf("[INFO] Enter mix number\n");
		return (-1);
	}
	else if (!strcmp(argv[argc - 2], "mix"))
	{
		fds = (int *)malloc(sizeof(int) * (argc - 3));
		i = 1;
		j = 0;
		n = argc - 3;
		while (n--)
		{
			fd = open(argv[i], O_RDONLY, 0);
			fds[j] = fd;
			++i; 
			++j;
		}
		j = 0;
		n = argc - 3;
		f = n;
		lines = (int *)malloc(sizeof(int) * n);
		while (n--)
			lines[j++] = 0;			
		while (f)
		{
			j = 0;
			while (j < argc - 3)
			{
				n = atoi(argv[argc - 1]);
				while (n-- && fds[j] != -2)
				{
					ret = get_next_line(fds[j], &ptr);
					if (ret == 0)
					{
						printf("[%s] [FD:%d] [RetVal:%d] [Line#%d] %s", \
						*(argv + j + 1), fds[j], ret, ++lines[j], ptr);
						printf(" EOF\n");
						close(fds[j]);
						fds[j] = -2;
						--f;
					}
					else if (ret == -1)
					{
						printf("[%s] [FD:%d] [RetVal:%d] [Line#%d] %s", \
						*(argv + j + 1), fds[j], ret, ++lines [j], ptr );
						printf(" ERROR\n");
						close(fds[j]);
						fds[j] = -2;
						--f;
					}
					else if (ret == 1)
					{
						printf("[%s] [FD:%d] [RetVal:%d] [Line#%d] $%s\n", \
							*(argv + j + 1), fds[j], ret, ++lines[j], ptr);
						ft_strdel(&ptr);
					}
				}
				++j;
			}
		}
		free (fds);
		free (lines);
	}
	else if (argc > 1)
	{
		while (--argc)
		{
			++argv;
			line = 0;
			fd = open(*argv, O_RDONLY, 0);
			while ((ret = get_next_line(fd, &ptr)) > 0)
			{
				printf("[%s] [FD:%d] [RetVal:%d] [Line#%d] $%s\n", *argv, fd, ret, ++line, ptr);
				ft_strdel(&ptr);
			}
			printf("[%s] [FD:%d] [RetVal:%d] [Line#%d] %s", *argv, fd, ret, ++line, ptr);
			if (ret == -1)
				printf(" ERROR\n");
			else if (ret == 0)
				printf(" EOF\n");
			close(fd);
			if (argc != 1)
				printf("\n");
		}
	}
	return (0);
}
