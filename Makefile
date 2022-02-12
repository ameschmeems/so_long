NAME		:=	so_long

SRCS		:=	srcs/main.c \
				srcs/error.c \
				srcs/key_handling.c \
				srcs/images.c \
				srcs/maps.c \
				srcs/maps2.c \
				srcs/collisions.c

OBJS		:=	srcs/main.o \
				srcs/error.o \
				srcs/key_handling.o \
				srcs/images.o \
				srcs/maps.o \
				srcs/collisions.o

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror

INCLUDES	:= ./includes

all:	${NAME}

${NAME}: ${SRCS}
	@make -C ./libft bonus
	${CC} -Wall -Wextra -Werror -O3 ${SRCS} -Llibft -lft -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o bin/release/${NAME}

debug:	${SRCS}
	@make -C ./libft bonus
	${CC} -Wall -Wextra -Werror -g ${SRCS} -Llibft -lft -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o bin/debug/${NAME}
	valgrind --leak-check=full ./bin/debug/${NAME} maps/map.ber

clean:
	@make -C ./libft clean
	rm -f ${OBJS}

fclean:	clean
	@make -C ./libft fclean
	rm -f bin/debug/${NAME} bin/release/${NAME}

re:	fclean all

.PHONY: all debug clean fclean re