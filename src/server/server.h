#ifndef _SERVER_H_
#define	_SERVER_H_
#include "myirc.h"
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define MAX_CONNECTION 256

typedef int SOCKET;

typedef struct	s_user
{
  struct pollfd poll;
}		t_user;

typedef struct s_channel
{
  char				*name;
  t_user			*users;
}           t_channel;

typedef struct s_server
{
  int port;
  SOCKET	sock;
  t_channel	*channels;
  t_user *users[MAX_CONNECTION];
  fd_set master;
}             t_server;

typedef struct s_command
{
  char				*cmd;
  char				*(*handler)(char *parameters, t_server *server);
}				t_command;

void handle_server(t_server *server);
t_server *init_server();
#endif