# Nombre del ejecutable
NAME = fractol

SRCS		= src/main.c src/hooks.c src/fractal.c src/utils.c

OBJS		= ${SRCS:.c=.o}

CC			= cc

CFLAGS = -Wall -Wextra -Werror -fPIE
LIBS = ./lib/mlx42/build/libmlx42.a -lglfw -lm -ldl -pthread -pie


RM			= rm -f

all: ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@${CC} ${OBJS} ${LIBS} -o ${NAME}
	@echo "fract-ol compiled"

clean:
	@${RM} ${OBJS}

fclean:	clean
	@${RM} ${NAME}

re: fclean all

val: 
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
  ./fractol 1 2>&1 | grep -A 10 "definitely lost"

.PHONY: all clean fclean re
