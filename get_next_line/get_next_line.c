/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:22:01 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/22 17:04:58 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	line_ret(char *nl, char **s, int f, char **l)
{
	char	*t;

	if (!(nl = ft_strchr(s[f], '\n')))
	{
		*l = ft_strdup(s[f]);
		ft_strdel(&s[f]);
	}
	else
	{
		*nl++ = '\0';
		*l = ft_strdup(s[f]);
		t = ft_strdup(nl);
		ft_strdel(&s[f]);
		s[f] = t;
	}
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		*store[65535];
	char			*temp;
	char			*nl;
	int				n;

	while (line && fd >= 0 && ((n = read(fd, buf, BUFF_SIZE)) > 0))
	{
		!store[fd] ? store[fd] = ft_strnew(1) : 0;
		buf[n] = '\0';
		temp = ft_strjoin(store[fd], buf);
		ft_strdel(&store[fd]);
		store[fd] = temp;
		if ((nl = ft_strchr(store[fd], '\n')))
			break ;
	}
	if (n < 0 || fd < 0 || line == NULL)
		return (-1);
	if (!n && (store[fd] == NULL || *store[fd] == '\0'))
	{
		ft_strdel(&store[fd]);
		return (0);
	}
	line_ret(nl, store, fd, line);
	return (1);
}
