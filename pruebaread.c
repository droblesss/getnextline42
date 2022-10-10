

#include "get_next_line.h"

// char	*getstatic(int fd, char *box)
// {
// 	int nr_bytes;
// 	char *buffer
	
// 	if (!box)
// 		box = ft_calloc(sizeof(char), 1)
// 	buf = malloc(BUFFER_SIZE + 1);
// 	if (!buf)
// 		return (NULL);

// }

char *get_next_line(int fd)
{
	char *linea;
	char *buf;
	static char *box;
	int nr_bytes;
	size_t i;
	
	i = 0;
	linea = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	nr_bytes = read(fd, buf, BUFFER_SIZE);
	if (box)
		buf = ft_strjoin(box, buf);
		free (box);
	if (nr_bytes > 0 || box)
	{
		while (buf)
		{
			if (ft_strchr(buf,'\n'))
			{
				while (buf[i] != '\n')
					i++;
				linea = ft_substr(buf, 0, i);
				box = ft_substr(buf, i +1 , ft_strlen(buf) - i);
				return (linea);
			}
			else
			{
				nr_bytes = read(fd, buf, BUFFER_SIZE);
				if (nr_bytes < 1)
					return (buf);
			}
		}
	}
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
	ptr = get_next_line(fd);
	printf("Output -->%s\n", ptr);
	free(ptr);
	close(fd);
	return(0);
}