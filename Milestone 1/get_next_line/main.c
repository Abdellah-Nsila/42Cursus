#include "get_next_line.h"

int main()
{
  printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
  int fd = open("./test.txt", O_RDONLY);
  char *line;
  free(NULL);
  line = get_next_line(fd);
  while (line)
  {
    printf("===============================================================\n");
    printf("line:[%s]", line);
    printf("===============================================================\n");
    free(line);
    line = get_next_line(fd);
  }
  return 0;
}