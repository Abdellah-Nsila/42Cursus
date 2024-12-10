#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*s;
	ssize_t		r;
	int			i;
	char 		buf[BUFFER_SIZE];

	while (1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r > 0)
		{
			// You must read the buff count stored until /n, 
			// return the line it save the remaining ...
			
		}
	}
	r = read(fd, buf, BUFFER_SIZE);
	if (r > 0)
		while (buf[i])
		{
			if (buf[i] == '\n')

			write(1, &buf[i], 1);
			i++;
		}
	else
		return (NULL);
	return (NULL);
}

int main()
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("Error...");
	
	get_next_line(fd);
}