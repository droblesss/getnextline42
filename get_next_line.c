/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:34:02 by marvin            #+#    #+#             */
/*   Updated: 2022/08/09 11:51:24 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char *get_next_line(int fd)

	char 	*linea;
	int	i;
	char buf[10];
	
	(size_t)fd = read("/Users/drobles/getnextline42/mifichero", buf, 5 )

	linea = (char *)malloc(sizeof(char *) * (tamaño buffer + 1));
	
	if (fd == -1)
	return (NULL);
	else
	linea = ft_substr(linea, buf, 5);
	return (linea)




	


 