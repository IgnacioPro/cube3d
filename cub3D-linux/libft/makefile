# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 13:41:31 by ihorcada          #+#    #+#              #
#    Updated: 2020/01/31 13:25:13 by ihorcada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a

SRC = 	ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strlcpy.c \
		ft_atoi.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_memccpy.c \
		ft_strrchr.c \
		ft_memchr.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_memcmp.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putendl_fd.c \
		ft_substr.c \
		ft_strmapi.c \
		ft_strjoin.c \
		ft_wordcount.c \
		ft_wordlen.c \
		ft_split.c \
		ft_itoa.c \
		ft_strnew.c \
		ft_memalloc.c \
		ft_strtrim.c \
	
OBJ    = $(SRC:.c=.o)
CC      = cc
RM      = rm
FLAG  = -Wall -Werror -Wextra
.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	ar rc  $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	${RM} ${OBJ}

fclean: clean
	$(RM) $(NAME)
	
re:	fclean all
