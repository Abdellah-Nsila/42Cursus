#include "get_next_line.h"

int main()
{
  printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
  int fd = open("./Test/test.txt", O_RDONLY);
  char *line;
  line = get_next_line(fd);
  while (line)
  {
    printf("===============================================================\n");
    if (line)
      printf("line:[%s]", line);
    else
      printf("END of read (Error)\n");
    printf("===============================================================\n");
    free(line);
    line = get_next_line(fd);
  }
  return 0;
}
