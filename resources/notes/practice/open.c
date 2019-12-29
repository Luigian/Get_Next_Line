/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:11:33 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/05 18:07:23 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>	// open
#include <unistd.h> // read, write
# define BUFSIZE 4096

// OPEN a file, READ its content, and WRITE it on screen.

int		main(void)
{
	int		fd;
	int		n;
	char	buf[BUFSIZE];
	 
	fd = open("file.txt", O_RDONLY, 0);
	n = read(fd, buf, BUFSIZE);
	write(1, buf, n);
	return (0);
}

// OPEN a file and WRITE something new on it.

int		main(void)
{
	int		fd;
		 
	fd = open("file.txt", O_RDWR, 0);
	write(fd, "hello LJ", 8);
	return (0);
}
