/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:11:07 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/05 18:07:20 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>	// creat, open
#include <unistd.h>	// close, unlink
#include <stdio.h>	// printf

// CREATe a new file.

int		main(void)
{
	creat("file33.txt", 0644);
	return (0);
}

// CREATe a new file, OPEN it, display it fd, and CLOSE the file.

int		main(void)
{
	int		fd;
	
	creat("file34.txt", 0644);
	fd = open("file34.txt", O_RDONLY, 0);
	printf("%d\n", fd);
	close(fd);
	return (0);
}

// UNLINK (remove) an existing file.

int		main(void)
{
	unlink("file33.txt");
	return (0);
}
