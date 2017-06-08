#include "server.h"

int	main(int ac, char **av)
{
  if (ac != 2)
    my_error("Usage : ./server [port]", 0);
  if (!(init_server(atoi(av[1]))))
    return (84);
  return (0);
}