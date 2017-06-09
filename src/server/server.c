#include "server.h"

#  define closesocket(s) close(s)

typedef struct	sockaddr_in SOCKADDR_IN;

typedef struct	sockaddr SOCKADDR;

#define MAX_CHANNELS 3
/*
void			exec_nick_cmd(char *name, t_server *cur)
{
  cur->username = strdup(name);
}

int			is_in_channel(t_server cl, t_server cur)
{
  if (!strcmp(cl.channel, cur.channel))
    return (1);
  return (0);
}

void			exec_list_cmd(t_server cur, char *channels)
{
  write(cur.sock, channels, strlen(channels));
}

void			exec_join_cmd(char *channel, t_server *cur)
{
  cur->channel = strdup(channel);
}

void			exec_part_cmd(t_server *cur)
{
  cur->channel = NULL;
}

void			exec_users_cmd(t_server *cl, t_server cur)
{
  char			*user;
  int			i;

  i = -1;
  if (!(user = malloc(sizeof(char) * 1000)))
    return ;
  user = memset(user, 0, 1000);
  while (cl[++i].sock != -1)
    {
      user = strcat(user, cl[i].username);
      user = strcat(user, "\n");
    }
  write(cur.sock, user, strlen(user));
  free(user);
}

void			exec_names_cmd(char *channel, t_server *cl, t_server cur)
{
  char                  *user;
  char			*dup;
  int                   i;

  i = -1;
  dup = strdup(channel);
  strsep(&dup, "\n");
  if (!(user = malloc(sizeof(char) * 1000)))
    return ;
  user = memset(user, 0, 1000);
  while (cl[++i].sock != -1)
    {
      if (strcmp(cl[i].channel, dup))
	continue;
      user = strcat(user, cl[i].username);
      user = strcat(user, "\n");
    }
  write(cur.sock, user, strlen(user));
  free(user);
}

void			exec_send_cmd(char *msg, t_server *cl, t_server cur)
{
  int			i;

  i = -1;
  while (cl[++i].sock != -1)
    {
      if (cl[i].sock == cur.sock
	  || strcmp(cl[i].channel, cur.channel))
	continue;
      write(cl[i].sock, msg, strlen(msg));
    }
}

int			is_nickname(char *name, t_server *cl)
{
  int			i;

  i = -1;
  while (cl[++i].sock != -1)
    if (!strcmp(name, cl[i].username))
      return (1);
  return (0);
}

int			is_user_in_channel(char *channel, char *name, t_server *cl)
{
  int			i;

  i = -1;
  while (cl[++i].sock != -1)
    if (!strcmp(channel, cl[i].channel) && !strcmp(name, cl[i].username))
      return (1);
  return (0);
}

void			exec_send_specify_cmd(char *msg, char *name, t_server *cl)
{
  int			i;

  i = -1;
  while (strcmp(cl[++i].username, name) && cl[i].sock != -1);
  write(cl[i].sock, msg, strlen(msg));
}

void			exec_send_file(char *name, char *file, t_server *cl)
{
  int                   i;

  i = -1;
  while (strcmp(cl[++i].username, name) && cl[i].sock != -1);
  write(cl[i].sock, file, strlen(file));
}

void			handle_command(char *query, t_server *server, t_server *cur, char *channels)
{
  char command;

  command = strsep(strdup(cmd), " ");
  while (commands[index].cmd) {
        if (strcmp(commands[index].cmd, *command) == 0) {
            (commands[index].handler)(command + 1, server);
            handled++;
        }
        index++;
    }
  /*

  
  char			*dup;

  dup = strdup(cmd);
  dup = 
  if (!strcmp(dup, "/nick"))
    exec_nick_cmd(strsep(&dup, " "), &*cur);
  else if (!strcmp(dup, "/list"))
    exec_list_cmd(*cur, channels);
  else if (!strcmp(dup, "/join"))
    exec_join_cmd(strsep(&dup, " "), &*cur);
  else if (!strcmp(dup, "/part"))
    exec_part_cmd(&*cur);
  else if (!strcmp(dup, "/users"))
    exec_users_cmd(cl, *cur);
  else if (!strcmp(dup, "/names"))
    exec_names_cmd(strsep(&dup, " "), cl, *cur);
  else if (!strcmp(dup, "/msg"))
    {
      dup = strsep(&dup, " ");
      if (is_nickname(dup, cl))
	exec_send_specify_cmd(strsep(&dup, " "), dup, cl);
      else if (is_user_in_channel(dup, strsep(&dup, " "), cl))
	exec_send_file(strsep(&dup, " "), strsep(&dup, " "), cl);
    }
  else
    exec_send_cmd(cmd, cl, *cur);
}
/*
int			strlen_t_server(t_server *cl)
{
  int			i;

  i = -1;
  while (cl[++i].sock != -1);
  return (i);
}

int			find_socket(t_server *cl, SOCKET sock)
{
  int			i;

  i = -1;
  while (cl[++i].sock != sock && cl[++i].sock != -1);
  return (i);
}

*/
/*
char			*set_channels()
{
  char			*tmp;
  char			*channels;
  int			i;

  i = -1;
  if (!(channels = malloc(sizeof(char) * MAX_CHANNELS * 3)))
    return (NULL);
  if (!(tmp = malloc(sizeof(char) * MAX_CHANNELS * 3)))
    return (NULL);
  channels = memset(channels, 0, MAX_CHANNELS * 3);
  while (++i <= MAX_CHANNELS)
    {
      tmp = memset(tmp, 0, 3);
      sprintf(tmp, "%d", i);
      strcat(tmp, "\n");
      channels = (!i) ? strdup(tmp) : strcat(channels, tmp);
    }
  free(tmp);
  return (channels);
}
*/
/*


void			server(int port)
{
  t_server		*server;
  SOCKADDR_IN           csin;
  SOCKADDR_IN           sin;
  SOCKET		nsock;
  socklen_t		recsize;
  int			i;
  //struct pollfd		pl[5];
  struct pollfd fd_queue[32];
  char query[1000];
  char *channels;

  //channels = set_channels();
  cl = init_server();
  recsize = sizeof(csin);
  memset((char *)query, 0, BUFFER_SIZE);
  server.sock = socket(AF_INET, SOCK_STREAM, 0);
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  bind(server.sock, (SOCKADDR*)&sin, sizeof(sin));
  listen(server.sock, 256);
  pl[0].fd = server.sock;
  pl[0].events = POLLIN;
  while (TRUE)
    {
      poll(pl, strlen_t_server(cl) + 1, -1);
      if (pl[0].revents & POLLIN)
      {
        if ((nsock = accept(server.sock, (SOCKADDR*)&csin, (socklen_t*)&recsize)) < 0)
          return;
        for (i = 0; i < 3; i++)
          {
            if (!cl[i].sock)
            {
              cl[i].sock = nsock;
              break;
            }
          }
        for (i = 1; server->users[i].sock != -1; i++)
          {
            if (pl[i].revents == 0)
              continue;
            read(cl[find_socket(cl, pl[i].fd)].sock, query, BUFFER_SIZE);
            handle_command(query, cl, &cl[find_socket(cl, pl[i].fd)], channels);
          }
       }
    }
}

*/

t_server		*init_server(int port)
{
  t_server *server;
  
  server = my_malloc(sizeof(t_server));
  server->sock = bind_port(port);
  FD_ZERO(&server->master);
  FD_SET(server->sock, &server->master);
  handle_server(server);
}
