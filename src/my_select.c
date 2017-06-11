#include "myirc.h"

int create_server(int port)
{
    struct addrinfo h;
    struct addrinfo *s;
    struct addrinfo *i;
    char* c_port[5];

    int sock;

    sprintf(c_port,"%d", port);
    memset(&h, 0, sizeof(struct addrinfo));
    h.ai_family = AF_UNSPEC;
    h.ai_socktype = SOCK_STREAM;
    h.ai_flags = AI_PASSIVE;
    if (getaddrinfo(NULL, c_port, &h, &s))
    my_error("getaddrinfo", 0);
    for (i = s; i != NULL; i = i->ai_next)
    {
        if (!local_bind(i, &sock))
        break ;
    }
    if (!i)
        error("bind");
    freeaddrinfo(s);
    if (listen(sock, 5))
        my_error("listen", 0);
  return (sock);
}

int	local_bind(struct addrinfo *i, int *sock)
{
  int			trigger;

  trigger = 1;
  if ((*sock = socket(i->ai_family, i->ai_socktype, i->ai_protocol)) == -1)
    return (1);
  if (setsockopt(*sock, SOL_SOCKET, SO_REUSEADDR, &trigger, sizeof(trigger)))
    return (1);
  if (bind(*sock, i->ai_addr, i->ai_addrlen) == -1)
    {
      close(*sock);
      return (1);
    }
  return (0);
}
