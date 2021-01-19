SRCS = 	read_map.c \
		../getnextline/get_next_line_bonus.c \
		../getnextline/get_next_line_utils_bonus.c \
		error_messages.c \
		./colors/get_colors.c \
		./colors/rgb_errors.c \
		./textures/parse_textures.c \
		./resolution/parse_resolution.c \
		./reader/open_file.c \
		./parser/map_parser.c \
		./reader/validators.c \
		../raycaster.c \
		../move_player.c \
		../move_camera.c \
		../painters.c


OBJS = $(SRCS:.c=.o)
NAME = cub3D
CC = gcc -Wall -Werror -Wextra -fsanitize=address
RM = rm -f
CFLAGS = -g3
FRAMEWORK = -lz -L . -lmlx  -framework OpenGL -framework AppKit

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME):	$(OBJS)
	${MAKE} -C ../libft
	${MAKE} -C ../minilibx

	mv ../minilibx/libmlx.a ../map/.
	mv ../libft/libft.a ../map/.
	$(CC) $(OBJS) -o $(NAME) -L ../libft -lft ${FRAMEWORK}
re: fclean all
clean:
	rm -f $(OBJS)
	${MAKE} clean -C ../libft
	${MAKE} clean -C ../libft
	make clean -C ../minilibx
fclean: clean
	rm -f $(NAME)
	make fclean -C ../libft

.PHONY:		re all clean fclean
