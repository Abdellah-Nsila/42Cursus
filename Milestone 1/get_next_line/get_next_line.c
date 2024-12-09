#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*s;
	ssize_t		r;
	char 		buf[BUFFER_SIZE];

	r = read(fd, buf, BUFFER_SIZE);
	if (r > 0)
		
		write(1, buf, r);
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