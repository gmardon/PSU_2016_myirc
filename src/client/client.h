#ifndef _CLIENT_H_
#define _CLIENT_H_
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include "myirc.h"

typedef struct			s_command
{
  char				*cmd;
  char				*(*op)(void *, void *);
}				t_command;

typedef struct			s_client
{
  char				connected;
  char				*channel;
  char				*nickname;
  t_socket			*sock;
}				t_client;
#endif