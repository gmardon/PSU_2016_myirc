#ifndef _MY_IRC_H_
#define _MY_IRC_H_
#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 2048
#define TRUE 1

typedef struct s_buffer t_buffer;

struct s_buffer
{
  char buffer[BUFFER_SIZE];
  char *read_buffer;
  char *write_buffer;
  int	available;
};

// Circular buffer \\ 
t_buffer *buffer_init();
void buffer_free(t_buffer *);
int	buffer_available(t_buffer *);
void buffer_write(t_buffer *, char *);
void buffer_write_c(t_buffer *, char);
char *buffer_read(t_buffer *);
char buffer_at(t_buffer *, int);
void buffer_set_at(t_buffer *, int, char);
void buffer_delete_last(t_buffer *);


void my_error(char *content, int opt);
/*
typedef struct			s_socket
{
  int				fd;
  stor				addr;
  socklen_t			len;
}				t_socket;
*/
#endif