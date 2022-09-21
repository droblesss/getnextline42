/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:36:13 by marvin            #+#    #+#             */
/*   Updated: 2022/09/21 11:42:33 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE.H
#   define GET_NEXT_LINE.H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

size_t  read(int fd, void *buf, size_t inicio);
char *get_next_line(int fd);

#endif

