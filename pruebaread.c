
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
	char *auxiliar;
	static char *box;
	int nr_bytes;
	size_t i;
	
	i = 0;
	linea = NULL;
	buf = malloc(BUFFER_SIZE +1);
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	nr_bytes = read(fd, buf, BUFFER_SIZE);
	if (box)
		auxiliar = ft_strjoin(box, buf);
	else
		auxiliar = ft_strdup(buf);
	// printf("Buffer  1-->%s\n", buf);
	// printf("Auxiliar 1 -->%s\n", auxiliar);
	if (nr_bytes > 0 || box)
	{
		while (auxiliar)
		{
			if (ft_strchr(auxiliar,'\n'))
			{
				i = 0;
				while (auxiliar[i] != '\n')
					{
						i++;
					}
				linea = ft_substr(auxiliar, 0, i);
				// (printf("Linea --->%s\n", linea));
				box = ft_substr(auxiliar, i +1 , ft_strlen(auxiliar) - i);
				// (printf("Box --->%s\n", box));
				free (auxiliar);
				// (printf("Pre free --->%s\n", auxiliar));
				auxiliar = ft_strdup(box);
				// (printf("Copia box --->%s\n", auxiliar));
				return (linea);
			}
			else
			{
				nr_bytes = read(fd, buf, BUFFER_SIZE);
				if (nr_bytes > 0)
				{
					auxiliar = ft_strjoin(auxiliar, buf);
				}
				else
				{
					return (auxiliar);
				}
			}
			
		}
	}
	linea = ft_strdup(auxiliar);
	free (auxiliar);
	free (box);
	return (linea);
	
}

// int main()
// {
// 	int fd;
// 	/*char buffer [50];
// 	int szbytes;*/
// 	char *ptr;

// 	fd = open("/Users/drobles/getnextline42/gnlTester/files/empty", O_RDONLY);
// 	ptr = get_next_line(fd);
// 	printf("Output -->%s\n", ptr);
// 	free(ptr);
// 	ptr = get_next_line(fd);
// 	printf("Output -->%s\n", ptr);
// 	free(ptr);
// 	ptr = get_next_line(fd);
// 	printf("Output -->%s\n", ptr);
// 	ptr = get_next_line(fd);
// 	printf("Output -->%s\n", ptr);
// 	free(ptr);
// 	close(fd);
// 	return(0);
// }