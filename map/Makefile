SRCS		= read_map.c ../getnextline/get_next_line_bonus.c ../getnextline/get_next_line_utils_bonus.c
OBJS		= ${SRCS:.c=.o}
NAME		= cub3D
CC			= cc
RM			= rm -f 
CFLAGS		= -g3

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${MAKE} -C ../libft

		
			mv ../libft/libft.a .
			${CC} -o ${NAME} ${OBJS} ${FRAMEWORK}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean : 	clean
			${RM} ${NAME} libft.a

re:			fclean all

.PHONY:		re all clean fclean
