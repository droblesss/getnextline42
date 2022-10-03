/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:10:26 by drobles           #+#    #+#             */
/*   Updated: 2022/09/28 15:59:25 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			i;
	size_t			j;
	unsigned int	slen;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (len > slen)
		len = slen;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (j < len)
	{
		sub[j] = s[start];
			j++;
			start++;
	}
	sub[j] = '\0';
	return (sub);
}

size_t	ft_strlen(const char *str)
{
	size_t c;

	c = 0;
	while (*str != '\0')
	{
		str++;
		c++;
	}
	return (c);
}
char	*ft_strdup(const char	*s1)
{
	char	*aux;
	size_t	i;

	i = 0;
	aux = ft_calloc (sizeof(char) * ft_strlen(s1) + 1, 1);
	if (aux == NULL)
		return (NULL);
	while (s1[i])
	{
		aux[i] = s1[i];
		i++;
	}
	return (aux);
}
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}
void	ft_bzero(void *s, size_t n)
{
	unsigned char		*c;
	size_t				i;
	int					j;

	j = '\0';
	c = s;
	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
		c[i] = j;
		i++;
		}
	}
}
size_t	ft_strcpy(char *dst, char *src)
{
	size_t	i;
	
	i = 0;
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (!s[i])
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != 0)
	{
		i++;
	}
	while (src[j] != 0)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest [i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux1;
	char	*aux2;
	char	*con;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) + ft_strlen(s2);
	aux1 = (char *)s1;
	aux2 = (char *)s2;
	con = ft_calloc((sizeof(char) * j + 1), 1);
	if (!con)
		return (NULL);
	while (aux1[i])
	{
		con[i] = aux1[i];
		i++;
	}
	ft_strcat(con, aux2);
	return (con);
}