SRCS		= raycaster.c move_camera.c move_player.c painters.c ./getnextline/get_next_line_bonus.c ./getnextline/get_next_line_utils_bonus.c
OBJS		= ${SRCS:.c=.o}
NAME		= cub3D
CC			= cc
RM			= rm -f
CFLAGS		= -g3
FRAMEWORK	= -lz -L . -lmlx  -framework OpenGL -framework AppKit -fsanitize=address 

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${MAKE} -C ./minilibx
			mv ./minilibx/libmlx.a .
			${CC} -o ${NAME} ${OBJS} ${FRAMEWORK}

all:		${NAME}

clean:
			${RM} ${OBJS}
			${MAKE} clean -C ./minilibx

fclean : 	clean
			${RM} ${NAME} libmlx.a

re:			fclean all

.PHONY:		re all clean fclean
