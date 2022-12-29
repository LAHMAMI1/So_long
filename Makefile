# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 02:11:24 by olahmami          #+#    #+#              #
#    Updated: 2022/12/28 20:42:29 by olahmami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
NAME		=	so_long
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	read_map.c \
				check_map.c \
				main.c

LIBS		=	libft.a

INCLUDES	=	$(LIBS:%=Libft/libft.a)

MLX_macos	=	-lmlx -framework OpenGL -framework AppKit

all: $(LIBS) $(NAME)

$(NAME): $(SRCS)
	@$(CC) -I includes $(CFLAGS) $(SRCS) $(INCLUDES) $(MLX_macos) -o $(NAME)

libs: $(LIBS)

$(LIBS):
	@make -C Libft

clean:
	@make -C Libft clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(INCLUDES)
	@make -C Libft fclean

re: fclean all

.PHONY: all