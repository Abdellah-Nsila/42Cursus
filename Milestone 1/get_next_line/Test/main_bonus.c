#include "get_next_line_bonus.h"


int main(int ac, char **av)
{
    // read from all files that are passed as arguments
    //int fd;
    char *line; 
    int i = 1;
    
    // if (ac == 1)
    // {
    //   while ((line = get_next_line(0)))
    //   {
    //       printf("%s\n", line);
    //       free(line);
    //   }
    //   printf("Done from stdin\n");
    // }
    /*else
    {
      while (av[i])
      {
          fd = open(av[i], O_RDONLY);
          if (fd == -1)
              printf("Error opning file %s\n", av[i]);
          while ((line = get_next_line(fd)))
          {
              printf("%s\n", line);
              free(line);
          }
          printf("Done from file %s\n", av[i]);
          close(fd);
          i++;
      }
    }*/
    // other check for check from file1.txt and file2.txt
    int fd1 = open(av[i], O_RDONLY);
    // read one line from file1.txt
    line = get_next_line(fd1);
    printf("%s", line);
    free(line);
    i++;
    int fd2 = open(av[i], O_RDONLY);
    line = get_next_line(fd2);
    printf("%s", line);
    free(line);
    // reade other lines from av[i] av[i + 1]
    i--;
    while ((line = get_next_line(fd1)))
    {
      printf("%s", line);
      free(line);
    }
    close(fd1);
    i++;
    while ((line = get_next_line(fd2)))
    {
      printf("%s", line);
      free(line);
    }
    close(fd2);
    return (ac * 0);
}