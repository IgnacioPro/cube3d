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
CC			= gcc
RM			= rm -rf
CFLAGS		= -g3 -Wall -Werror -Wextra
FRAMEWORK	= -I . -L libft libft.a -L minilibx libmlx.a -lm -lbsd -lX11 -lXext

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${MAKE} -C ./minilibx
			${MAKE} -C ./libft
			mv ./minilibx/libmlx.a .
			mv ./libft/libft.a .
			$(CC) $(OBJS) -o $(NAME)  ${FRAMEWORK}
			
all:		${NAME}

clean:
			${RM} ${OBJS}
			${MAKE} clean -C ./libft 
			${MAKE} clean -C ./minilibx

fclean :
		${RM} ${NAME} libmlx.a libft.a screenshot.bmp
		

re:			fclean all

.PHONY:		re all clean fclean
