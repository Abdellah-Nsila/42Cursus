#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;

	


}

int main()
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("Error...");
	printf("%s", get_next_line(fd));
}