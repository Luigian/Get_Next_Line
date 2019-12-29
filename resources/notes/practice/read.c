/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 21:29:44 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/05 18:07:27 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// read, write
# define SIZE 4096

// READ from keyboard and WRITE it on screen.

int		main(void)
{
	char	str[SIZE];
	int		n;

	n = read(0, str, SIZE);
	write(1, str, n);
	return (0);
}

// READ from keyboard and WRITE it on screen (many times).
 
int		main(void)
{
	char	str[SIZE];
	int		n;

	while ((n = read(0, str, SIZE)) > 0)
		write(1, str, n);
	return (0);
}
