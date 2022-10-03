
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char *get_next_line(int fd)	
{
	char *linea;

	char *buf;
	static char *auxiliar;
	int nr_bytes;
	size_t i;
	int j;
	
	i = 0;
	j = 0;
	linea = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE + 1] = '\0';
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	nr_bytes = read(fd, buf, BUFFER_SIZE);
	if (auxiliar)
		auxiliar = ft_strjoin(auxiliar, buf);
	else
		auxiliar = ft_strdup(buf);
	printf("Buffer  1-->%s\n", buf);
	printf("Auxiliar 1 -->%s\n", auxiliar);
	if (nr_bytes > 0)
	{
		while (nr_bytes == BUFFER_SIZE && !linea)
		{
			if (ft_strchr(auxiliar,'\n'))
			{
				while (auxiliar[i] != '\n')
					{
						i++;
					}
				linea = ft_substr(auxiliar, 0, i);
				auxiliar = ft_substr(auxiliar, i + 1, ft_strlen(auxiliar + i +1));
				return (linea);
			}
			else
			{	
				if (auxiliar && nr_bytes > 0)
				{
					nr_bytes = read(fd, buf, BUFFER_SIZE);
					auxiliar = ft_strjoin(auxiliar, buf);
				}
				else if (auxiliar)
				{
					linea = ft_strdup(auxiliar);
					auxiliar = NULL;
					return (linea);
				}
				else
					auxiliar = buf;
			}
			printf("Auxiliar -->%s\n", auxiliar);
		}
	}
	linea = ft_strdup(auxiliar);
	return (linea);
	
}

int main()
{
	int fd;
	/*char buffer [50];
	int szbytes;*/
	char *ptr;

	fd = open("/Users/drobles/getnextline42/mifichero", O_RDONLY);
	ptr = get_next_line(fd);
	printf("Output -->%s\n", ptr);
	free(ptr);
	ptr = get_next_line(fd);
	printf("Output -->%s\n", ptr);
	free(ptr);
	ptr = get_next_line(fd);
	printf("Output -->%s\n", ptr);
	close(fd);
	return(0);
}