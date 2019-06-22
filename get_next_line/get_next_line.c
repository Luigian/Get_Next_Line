/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:22:01 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/21 17:48:34 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		if_no_read(int n, char **s, const int f, char **l)
{
	if (n < 0)
		return (-1);
	if (!n && (*s[f] == '\0' || s[f] == NULL))
	{
		*l = ft_strdup(s[f]);
		ft_strdel(l);
		ft_strdel(&s[f]);
		return (0);
	}
	else if (!n)
	{
		*l = ft_strdup(s[f]);
		ft_strdel(&s[f]);
		return (1);
	}
	return (2);
}

int		build_until_nl(const int f, char **s, char **l, char *t)
{
	char		*buf;
	int			n;
	int			e;

	buf = ft_strnew(BUFF_SIZE);
	n = read(f, buf, BUFF_SIZE);
	if ((e = if_no_read(n, s, f, l)) != 2)
		return (e);
	t = ft_strdup(s[f]);
	ft_strdel(&s[f]);
	s[f] = ft_strjoin(t, buf);
	ft_strdel(&buf);
	ft_strdel(&t);
	return (2);
}

int		get_next_line(const int fd, char **line)
{
	char		*temp;
	static char	**store;
	char		*nl;
	int			r;

	if (fd < 0 || line == NULL)
		return (-1);
	!store ? store = ft_stranew(65535) : 0;
	!store[fd] ? store[fd] = ft_strnew(1) : 0;
	while (!(nl = ft_strchr(store[fd], '\n')))
		if ((r = build_until_nl(fd, store, line, temp)) != 2)
			return (r);
	*nl++ = '\0';
	*line = ft_strdup(store[fd]);
	temp = ft_strdup(nl);
	ft_strdel(&store[fd]);
	store[fd] = ft_strdup(temp);
	ft_strdel(&temp);
	return (1);
}
