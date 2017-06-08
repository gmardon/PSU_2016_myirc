#include "client.h"

t_socket	*init_client(t_client *this)
{
    t_socket *sock;
    static t_command cmd[] = {
        {"/server", &connect_server},
        /*{"/nick", &change_nickname},
        {"/list", &list_channels},
        {"/join", &join_channel},
        {"/part", &leave_channel},
        {"/users", &list_users},
        {"/msg", &send_msg_to_user},
        {"/send_file", &send_file_to_user},
        {"/accept_file", &accept_file_from_user},
        {"/quit", &quit_client},*/
        {NULL, NULL}
    };
    sock = my_malloc(sizeof(t_socket));
    this->connected = 0;
    this->channel = strdup("Lobby");
    this->nickname = getlogin();
    return (sock);
}

int main(int ac, char **av)
{
  struct protoent *pe;
  int sfd;
  struct sockaddr_in	my_addr;

  if (ac != 3)
      my_error("Usage : ./client [adress] [port]\n", 0);
  if (!(pe = getprotobyname("TCP")))
    my_error("Fail getprotobyname", 1);
  sfd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (sfd == - 1)
    my_error("Failed to create socket", 1);
  memset(&my_addr, '\0', sizeof(my_addr));
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(atoi(av[2]));
  my_addr.sin_addr.s_addr = inet_addr(av[1]);
  if (connect(sfd, (struct sockaddr *) &my_addr, sizeof(my_addr)) ==  - 1)
    my_error("Failed to connect", 1);
  return (0);
}