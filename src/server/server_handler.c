#include "server.h"

void handle_command()
{

}

void refuse_new_connection(t_user *user, t_server *server)
{
  //ssend(user->sock, "400 : Too much users connected\r\n");
  FD_CLR(user->sock, &server->master);
  //user_destroy(user);
}

void handle_new_connection(int *max, t_server *server)
{
    printf("handle new connection\n");
  struct sockaddr_storage sockaddr_storage;
  socklen_t len;
  t_user *user;
  char ip[INET6_ADDRSTRLEN];

  user = my_malloc(sizeof(t_user));
  len = sizeof(sockaddr_storage);
  if ((user->sock = accept(server->sock, (struct sockaddr *)&sockaddr_storage, &len)) == -1)
    my_error("accept", 0);
  FD_SET(user->sock, &server->master);
  if (user->sock > *max)
    *max = user->sock;
  user->buffer = buffer_init();
  user->nickname = NULL;
 // user->real = NULL;
 // user->auth = 0;
 // user->chan = 0;
 // serv->user_index[user->socket] = user;
  //if (serv->users[MAX_CONN - 1])
  //  refuse_new_connection(user, serv);
  //else
  //  user_push(user, &serv->users_alone);
}

void		handle_io_connection(t_user *user, t_server *serv)
{
  char tmp[RB_SIZE];
  int rc;

  memset(tmp, 0, RB_SIZE);
  if ((rc = recv(user->sock, tmp, buffer_available(user->buffer), 0)) > 0)
    {
        printf("recv\n");
     // rb_write(user->rb, tmp);
     // if (rb_at(user->rb, -1) == '\n' && rb_at(user->rb, -2) == '\r')
	//input_interpret(user, serv);
    }
  else
    {
      if (rc == 0)
//	printf("%s Disconnected\n", (user->nick)
//	       ? user->nick : user->ip);
        printf("Disconnected");
      else
      	perror("recv");
      FD_CLR(user->sock, &serv->master);
      //remove_connection(user, serv);
    }
}


void watch_sockets(int *i, int *max, fd_set *set, t_server *server)
{
  if (FD_ISSET(*i, set))
    {
      if (*i == server->sock)
	      handle_new_connection(max, server);
      else
      	handle_io_connection(server->users[*i], server);
    }
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

