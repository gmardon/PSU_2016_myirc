#include "server.h"

void handle_command()
{

}

void watch_sockets(int *i, int *max, fd_set *set, t_server *server)
{
  /*if (FD_ISSET(*i, catch))
    {
      if (*i == serv->sock)
	      handle_new_connection(max, serv);
      else
      	handle_io_connection(serv->user_index[*i], serv);
    }*/
}

void handle_server(t_server *server)
{
  fd_set set;
  int max;
  int index;

  max = server->sock;
  FD_ZERO(&set);
  while (TRUE)
    {
      set = server->master;
      if (select(max + 1, &set, NULL, NULL, NULL) == -1)
        my_error("select", 0);
      for (index = 0; index <= max; index++)
	    watch_sockets(&index, &max, &set, server);
    }
}

