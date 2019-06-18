/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:22:01 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/16 22:39:11 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{	
	static char	**store;
	char		*buf;
	char		*temp;
	char		*nl;
	int			n;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!store)
		store = ft_stranew(65535);
	n = 0;
	if (!store[fd])
		store[fd] = ft_strnew(1);
	while (!(nl = ft_strchr(store[fd], '\n')))
	{
		buf = ft_strnew(BUFF_SIZE);
		n = read(fd, buf, BUFF_SIZE);
		if (n < 0)
			return (-1);
		if (!n && (*store[fd] == '\0' || store[fd] == NULL))
		{	
			*line = ft_strdup(store[fd]);
			ft_strdel(line);
			ft_strdel(&store[fd]);
			return (0);
		}
		temp = ft_strdup(store[fd]);
		ft_strdel(&store[fd]);
		store[fd] = ft_strjoin(temp, buf);
		ft_strdel(&buf);
		ft_strdel(&temp);
	}
	*nl = '\0';
	*line = ft_strdup(store[fd]);
	++nl;
	temp = ft_strdup(nl);
	ft_strdel(&store[fd]);
	store[fd] = ft_strdup(temp);
	ft_strdel(&temp);
	return (1);
}
