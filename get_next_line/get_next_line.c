/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:22:01 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/15 22:33:41 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


int		get_next_line(const int fd, char **line)
{	
	static char	**store;
	char		*buf;
	char		*temp;
	char		*nl;
	int			n;

//	ft_putendl("--------------------------------------");
	if (BUFF_SIZE < 0)
		return (-1);
	if (!store)
		store = ft_stranew(5);
	n = 0;
//											printf("[STORE]%s\n", store);
	if (!store[fd])
		store[fd] = ft_strnew(0);
//											printf("[STORE]%s\n", store);
	while (!(nl = ft_strchr(store[fd], '\n')))
	{
		buf = ft_strnew(BUFF_SIZE);
//											printf("[BUF]%s\n", buf);
		n = read(fd, buf, BUFF_SIZE);
//											printf("[N]%d\n", n);
//											printf("[BUF]%s\n", buf);
		
		if (!n && *store[fd] == '\0')
		{	
			*line = ft_strdup(store[fd]);
			ft_strdel(&store[fd]);
			return (0);
		}
		
		temp = ft_strdup(store[fd]);
//											printf("[TEMP]%s\n", temp);
		ft_strdel(&store[fd]);
//											printf("[STORE]%s\n", store);
		store[fd] = ft_strjoin(temp, buf);
//											printf("[STORE]%s\n", store);
		ft_strdel(&buf);
//											printf("[BUF]%s\n", buf);
		ft_strdel(&temp);
//											printf("[TEMP]%s\n", temp);
	}
//											printf("[STORE]%s\n", store);
	*nl = '\0';
	*line = ft_strdup(store[fd]);
//											printf("[*LINE]%s\n", *line);
	++nl;
//											printf("[NL]%s\n", nl);
	temp = ft_strdup(nl);
//											printf("[TEMP]%s\n", temp);
	ft_strdel(&store[fd]);
//											printf("[STORE]%s\n", store);
	store[fd] = ft_strdup(temp);
//											printf("[STORE]%s\n", store);
	ft_strdel(&temp);
//											printf("[TEMP]%s\n", temp);
	return (1);
}
