/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:22:01 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/14 13:53:16 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


int		get_next_line(const int fd, char **line)
{	
	static char	*store;
	char		*buf;
	char		*temp;
	char		*nl;
	
	printf("-------------------------------------------------------------------\n");
	
	if (!store)
		store = ft_strnew(0);
	printf("[STORE]:%s\n", store);/////////////////////////////
	while (!(nl = ft_strchr(store, '\n')))
	{
			buf = ft_strnew(BUFF_SIZE);
			read(fd, buf, BUFF_SIZE);
			temp = ft_strdup(store);
			ft_strdel(&store);
			store = ft_strjoin(temp, buf);
			ft_strdel(&buf);
			ft_strdel(&temp);
	}
	*nl = '\0';
	if (*line)
		ft_strdel(line);
	*line = ft_strdup(store);
	++nl;
	temp = ft_strdup(nl);
	ft_strdel(&store);
	store = ft_strdup(temp);
	ft_strdel(&temp);
	ft_strclr(nl);
	printf("[STORE]:%s\n", store);///////////////////////////
	printf("[LEN]:%zu\n", ft_strlen(store));///////////////// 
	return (0);
}

/*	else
		while ((buf = ft_strnew(BUFF_SIZE)) && (read(fd, buf, BUFF_SIZE) > 0)\
		   && !(nl = ft_strchr(buf, '\n')))
		{
			printf("LIN: %s\n", lin);
			join = ft_strjoin(temp, lin);
			printf("JOIN: %s\n", join);
			ft_strdel(&temp);
			temp = ft_strdup(join);
			printf("TEMP: %s\n", temp);
			ft_strdel(&join);
			
			join = temp;
			printf("JOIN: %s\n", join);
			ft_strdel(&lin);
		}
	printf("[BUF]:%s\n", buf);//
	*nl = '\0';
	printf("[BUF]:%s\n", buf);//
	*line = ft_strdup(buf);
	++nl;
	printf("[NL]:%s\n", nl);//
	temp = ft_strdup(nl);
	printf("[TEMP]:%s\n", temp);//
	ft_strdel(&buf);
	printf("[BUF]:%s\n", buf);//
*/
/*	printf("TEMP: %s\n", temp);
	nl_to_zero(temp);
	printf("TEMP: %s\n", temp);
	*line = ft_strdup(join);
	printf("LINE: %s\n", *line);
	temp += ft_strlen(temp);
	join = ft_strjoin(temp, lin);
	printf("JOIN: %s\n", join);
	++line;
	*line = ft_strdup(join);
	ft_strdel(&join);
	ft_strdel(&temp);
	ft_strdel(&lin);
	--line;

	if (*line)
		ft_strdel(*line);
	*/
//	return (0);
//}


/*
int		str_nl(char *s)
{
	int		i;
	int		count;
	
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			++count;
		++i;
	}
	return (count);
}

int		len_nl(char *s)
{
	int		i;
	
	i = 0;
	while (s[i] != '\n')
		++i;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	char	*s;
	char	*temp;
	char	*join;
	int		len;

	
	while (!str_nl(s))
	{
		s = ft_strnew(BUFF_SIZE);
		read(fd, s, BUFF_SIZE);
		ft_strclr(s);
		
		
		
		
		temp = ft_strnew(BUFF_SIZE);
		join = ft_strjoin(temp, s);
		
		
		
		
		ft_strcpy(temp, s);
		free(s);
	}




	
		ft_strclr(join2);
		join2 = ft_strjoin(join, s);
		ft_strclr(join);
		join = ft_strjoin(temp, s);
		ft_strclr(temp);
		temp = ft_strcpy(temp, s);
	
	
	len = len_nl(temp);
	*line = ft_strnew(len);
	ft_strncpy(*line, temp, len);



	printf("%s\n", s);
	printf("%s\n", temp);
	printf("%s\n", *line);
	


	return (0);
}
	

	
*/	
	
	
	
	
	
/*
	
	


int		get_next_line(const int fd, char **line)
{
	char	*s;
	int		len;
	int		i;
	int		n;
	char	*temp;

	n = 0;
	s = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	s[BUFF_SIZE] = '\0';
	while (read(fd, s, BUFF_SIZE) > 0)
	{
		ft_putstr(s);
		ft_strcat(temp, 
		while (str_nl(s) && s);
		{
			len = len_nl(s);
			*line = (char *)malloc(sizeof(char) * len + 1);
			*line[len] = '\0';
			
			
			
			ft_strncpy(*line, s, len);
			s + len + 1;
			++line;
		}
		while (temp)
			++temp;
		ft_strcpy(temp, s);
		while (s)
			++s;
		s - BUF_SIZE;
		ft_strclr(s);
		
		
		
		
		ft_strcpy(s, temp);
		while (s)
			++s;
		
		
		while (**line  
		ft_strclr(s);
		ft_strcpy(s, temp);
			
			i = 0;
			while (s[i])
			{
				while (s[i] != '\n' && s[i])
				{	
					(*line)[i] = s[i];
					++i;
				}
				++line;
				++i;
		

			ft_strncpy(*line, s, len); 
		n += str_nl(s);
		++s;
	}
	ft_putnbr(n);
	ft_putchar('\n');
	return (0);
}
*/
/*

ft_strchr(s, '\n');
int		str_nl(char *s)
{
	int		i;
	
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		++i;
	if (s[i] == '\n')
		return (1);
	else
		return (0);
}

int		len_nl(char *s)
{
	int		i;
	
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		++i;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	char	*buf[2];
	int		i;
	int		size;
	
	buf[0] = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	read(fd, buf[0], BUFF_SIZE);
	buf[0][BUFF_SIZE] = '\0';
	while (!str_nl(buf[0]))
	{
		buf[1] = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		read(fd, buf[1], BUFF_SIZE);
		buf[1][BUFF_SIZE] = '\0';
		ft_strcat(buf[0], buf[1]);
	 	if (!str_nl(buf[0]))
			ft_memdel((void **)buf + 1);
	}
	size = len_nl(buf[0]);
	*line = (char *)malloc(sizeof(char) * size + 1);
	i = 0;
	while (size--)
	{
		(*line)[i] = buf[0][i];	
		++i;
	}
	(*line)[i] = '\0';
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	t_list	*buf;
	
	
	buf[0] = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	read(fd, buf[0], BUFF_SIZE);
	buf[0][BUFF_SIZE] = '\0';
	while (!str_nl(buf[0]))
	{
		buf[1] = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		read(fd, buf[1], BUFF_SIZE);
		buf[1][BUFF_SIZE] = '\0';
		ft_strcat(buf[0], buf[1]);
	 	if (!str_nl(buf[0]))
			ft_memdel((void **)buf + 1);
	}
	size = len_nl(buf[0]);
	*line = (char *)malloc(sizeof(char) * size + 1);
	i = 0;
	while (size--)
	{
		(*line)[i] = buf[0][i];	
		++i;
	}
	(*line)[i] = '\0';
	return (0);
}


int		get_next_line(const int fd, char **line)
{
	
	read(fd, buf[0], BUFF_SIZE);
	buf[0][BUFF_SIZE] = '\0';
	while (!str_nl(buf[0]))
	{
		buf[1] = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		read(fd, buf[1], BUFF_SIZE);
		buf[1][BUFF_SIZE] = '\0';
		ft_strcat(buf[0], buf[1]);
	 	if (!str_nl(buf[0]))
			ft_memdel((void **)buf + 1);
	}
	size = len_nl(buf[0]);
	*line = (char *)malloc(sizeof(char) * size + 1);
	i = 0;
	while (size--)
	{
		(*line)[i] = buf[0][i];	
		++i;
	}
	(*line)[i] = '\0';
	return (0);
}*/
