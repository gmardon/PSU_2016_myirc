NAME_SERVER			=		server

NAME_CLIENT			=		client

SRC_COMMON			= 		src/my_malloc.c			\
							src/my_error.c			\
							src/get_next_line.c

SRC_SERVER			=		src/server/server.c		\
							src/my_select.c			\
							$(SRC_COMMON)

SRC_CLIENT			=		src/client/client.c		\
							src/select.c			\
							$(SRC_COMMON)

OBJ_SERVER			=		$(SRC_SERVER:.c=.o)

OBJ_CLIENT			=		$(SRC_CLIENT:.c=.o)

CFLAGS			=		-W -Wall -Wextra -g -I./include/ 

all:			server client

server:			$(OBJ_SERVER)
				gcc -I./src/server/ -o $(NAME_SERVER) $(OBJ_SERVER) $(CFLAGS) -lm

client:			$(OBJ_CLIENT)
				gcc -I./src/client/ -o $(NAME_CLIENT) $(OBJ_CLIENT) $(CFLAGS) 

clean:
				rm -rf $(OBJ_SERVER)
				rm -rf $(OBJ_CLIENT)

fclean:			clean
				rm -rf $(NAME_SERVER)
				rm -rf $(NAME_CLIENT)

re:			fclean all