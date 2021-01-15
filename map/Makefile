SRCS = read_map.c ../getnextline/get_next_line.c ../getnextline/get_next_line_utils.c error_messages.c ./colors/get_colors.c ./colors/rgb_errors.c ./textures/parse_textures.c ./resolution/parse_resolution.c
OBJS = $(SRCS:.c=.o)
NAME = cub3D
CC = gcc -Wall -Werror -Wextra -fsanitize=address
all: $(NAME)

$(NAME):	$(OBJS)
	make -C ../libft
	$(CC) $(OBJS) -o $(NAME) -L ../libft -lft
re: fclean all
clean:
	rm -f $(OBJS)
	make clean -C ../libft
fclean: clean
	rm -f $(NAME)
	make fclean -C ../libft