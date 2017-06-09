#include "myirc.h"

char  buffer_at(t_buffer *buffer, int index)
{
  return ((index >= 0)
	  ? (buffer->buffer[(((size_t)buffer->read_buffer + index)
				 - (size_t)buffer->buffer) % BUFFER_SIZE])
	  : (buffer->buffer[(((size_t)buffer->write_buffer + index)
		       - (size_t)buffer->buffer) % BUFFER_SIZE]));
}

void buffer_set_at(t_buffer *buffer, int index, char c)
{
  ((index >= 0)
   ? (buffer->buffer[(((size_t)buffer->read_buffer + index)
		- (size_t)buffer->buffer) % BUFFER_SIZE] = c)
   : (buffer->buffer[(((size_t)buffer->write_buffer + index)
		- (size_t)buffer->buffer) % BUFFER_SIZE] = c));
}

void buffer_delete_last(t_buffer *buffer)
{
  buffer->write_buffer = (buffer->write_buffer == buffer->read_buffer)
    ? buffer->write_buffer
    : &buffer->buffer[(((size_t)buffer->write_buffer - 1)
		 - (size_t)buffer->buffer) % BUFFER_SIZE];
}

void buffer_write_c(t_buffer *buffer, char c)
{
  buffer->write_buffer = (buffer->write_buffer) ? buffer->write_buffer : buffer->buffer;
  *buffer->write_buffer = c;
  buffer->write_buffer = &buffer->read_buffer[(((size_t)buffer->write_buffer + 1)
			 - (size_t)buffer->buffer) % BUFFER_SIZE];
}