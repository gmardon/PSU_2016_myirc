#include "myirc.h"

t_buffer *buffer_init()
{
  t_buffer *buffer;

  buffer = my_malloc(sizeof(t_buffer));
  memset(buffer->buffer, 0, BUFFER_SIZE);
  buffer->write_buffer = buffer->buffer;
  buffer->write_buffer = buffer->buffer;
  buffer->available = BUFFER_SIZE;
  return (buffer);
}

void buffer_free(t_buffer *buffer)
{
  if (buffer)
    free(buffer);
}

int buffer_available(t_buffer *buffer)
{
  return ((buffer->write_buffer >= buffer->read_buffer)
	  ? (BUFFER_SIZE - (int)(buffer->write_buffer - buffer->read_buffer))
	  : (int)(buffer->read_buffer - buffer->write_buffer));
}

void buffer_write(t_buffer *buffer, char *str)
{
  int index;

  buffer->write_buffer = (buffer->write_buffer) ? buffer->write_buffer : buffer->buffer;
  for (index = 0; str[index]; index++)
    {
      *buffer->write_buffer = str[index];
      buffer->write_buffer = &buffer->buffer[(((size_t)buffer->write_buffer + 1)
			     - (size_t)buffer->buffer) % BUFFER_SIZE];
    }
}

char *buffer_read(t_buffer *buffer)
{
  char *str;
  int size;
  int index;

  size = ((buffer->write_buffer >= buffer->read_buffer)
	  ? (int)(buffer->write_buffer - buffer->read_buffer)
	  : (BUFFER_SIZE - (int)(buffer->read_buffer - buffer->write_buffer)));
  str = my_malloc(size + 1);
  memset(str, 0, size + 1);
  for (index = 0; index < size; index++)
    {
      str[index] = *buffer->read_buffer;
      buffer->read_buffer = &buffer->buffer[(((size_t)buffer->read_buffer + 1)
			     - (size_t)buffer->buffer) % BUFFER_SIZE];
    }
  return (str);
}