/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:21:28 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/08 20:38:37 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "./libft/libft.h"
# define BUFF_SIZE 50

int		get_next_line(const int fd, char **line);
/*int		get_next_line(const int fd, char *line);*/

#endif
