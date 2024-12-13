#include "get_next_line_bonus.h"

int main(int ac, char **av)
{
    // read from all files that are passed as arguments
    //int fd;
    char *line; 
    int fd1;
    int fd2;
    
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
    fd1 = open(av[1], O_RDONLY);
    fd2 = open(av[2], O_RDONLY);
    
    line = get_next_line(fd1);
    printf("%s", line);
    free(line);

    line = get_next_line(fd2);
    printf("%s", line);
    free(line);

    line = get_next_line(fd1);
    printf("%s", line);
    free(line);

    line = get_next_line(fd2);
    printf("%s", line);
    free(line);

    // Continue read fd1
    while ((line = get_next_line(fd1)))
    {
      printf("%s", line);
      free(line);
    }
    close(fd1);

    // Continue read fd2
    while ((line = get_next_line(fd2)))
    {
      printf("%s", line);
      free(line);
    }
    close(fd2);
    return (ac * 0);
}