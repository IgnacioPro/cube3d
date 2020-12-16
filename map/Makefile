SRCS = read_map.c ../getnextline/get_next_line.c ../getnextline/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
NAME = cub3D
CC = gcc 
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