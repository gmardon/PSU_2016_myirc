#include "myirc.h"

void my_error(char *content, int errno)
{
  fprintf(stderr, "[Error] %s", content);
  if (errno)
    fprintf(stderr, " : %s", strerror(errno));
  fprintf(stderr, "\n");
  exit(1);
}