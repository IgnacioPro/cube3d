SRCS		= 	raycaster.c \
				./movement/move_camera.c \
				./movement/move_player.c \
				./raycaster/painters.c \
				./getnextline/get_next_line_bonus.c \
				./getnextline/get_next_line_utils_bonus.c \
				./map/reader/open_file.c \
				./map/reader/validators.c \
				./map/textures/parse_textures.c \
				./map/resolution/parse_resolution.c \
				./map/error_messages.c \
				./map/colors/get_colors.c \
				./map/colors/rgb_errors.c \
				./map/parser/map_parser.c \
				./map/read_map.c \
				./movement/key_events.c \
				./sprites/coordinates.c \
				./sprites/size_distance.c \
				./textures/load_textures.c \
				./raycaster/calculations.c \
				./raycaster/render.c \
				./screenshot/save.c
				
OBJS		= ${SRCS:.c=.o}
NAME		= cub3D
CC = gcc -Wall -Werror -Wextra
RM			= rm -f
CFLAGS		= -g3 -g
FRAMEWORK	= -lz -L . -lmlx  -framework OpenGL -framework AppKit

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${MAKE} -C ./minilibx
			echo "\x1b[32m[Minilib compiled]\n\x1b[0m"
			${MAKE} -C ./libft
			echo "\x1b[32m[Libft compiled]\n\x1b[0m"
			mv ./minilibx/libmlx.dylib .
			mv ./libft/libft.a .
			$(CC) $(OBJS) -o $(NAME) -L ../libft -lft ${FRAMEWORK}
			
all:		${NAME}

clean:
			${RM} ${OBJS}
			${MAKE} clean -C ./minilibx
			${MAKE} clean -C ./libft


fclean : 	clean
			${RM} ${NAME} libmlx.dylib libft.a


re:			fclean all
			@echo "Mae re DONE"

.PHONY:		re all clean fclean
			
