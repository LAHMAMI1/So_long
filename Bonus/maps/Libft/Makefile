# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 02:23:02 by olahmami          #+#    #+#              #
#    Updated: 2023/01/14 17:38:52 by olahmami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_split.c \
		ft_strncmp.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		get_next_line_utils.c \
		get_next_line.c

OBJ = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	@ar rc ${NAME} ${OBJ}

clean :
	@rm -f ${OBJ}

fclean : clean
	@rm -f ${NAME}

re: fclean all
