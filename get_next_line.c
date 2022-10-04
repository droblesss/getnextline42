/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:34:02 by marvin            #+#    #+#             */
/*   Updated: 2022/10/04 15:23:55 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)	
{
	char *linea;
	char *buf;
	char *auxiliar;
	static char *box;
	int nr_bytes;
	size_t i;
	
	i = 0;
	linea = NULL;
	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE + 1] = '\0';
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	nr_bytes = read(fd, buf, BUFFER_SIZE);
	if (box)
		auxiliar = ft_strjoin(box, buf);
	else
		auxiliar = ft_strdup(buf);
	


 
