#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*s;
	ssize_t		r;
	char 		buf[BUFFER_SIZE + 1];

	r = read(fd, buf, BUFFER_SIZE);
	if (r > 0)
		write(1, buf, BUFFER_SIZE);
	else
		return (NULL);
	return (NULL);

}

int main()
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("Error...");
	printf("%s", get_next_line(fd));
}