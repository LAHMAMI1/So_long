# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 02:11:24 by olahmami          #+#    #+#              #
#    Updated: 2023/01/02 06:33:17 by olahmami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
NAME		=	so_long
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address

SRCS		=	read_map.c \
				map_checker/name_map.c \
				map_checker/composed_map.c \
				map_checker/onechar_map.c \
				map_checker/rect_map.c \
				map_checker/walls_map.c \
				map_checker/path_map.c \
				map_checker/check_all.c \
				show_map.c \
				main.c

LIBS		=	libft.a

INCLUDES	=	$(LIBS:%=Libft/libft.a)

MLX_macos	=	-lmlx -framework OpenGL -framework AppKit

OBJ = ${SRCS:.c=.o}

all: $(LIBS) $(NAME)

$(NAME): $(OBJ)
	$(CC) -I includes $(CFLAGS) $(OBJ) $(INCLUDES) $(MLX_macos) -o $(NAME)

libs: $(LIBS)

$(LIBS):
	@make -C Libft

clean:
	@rm -f ${OBJ}
	@make -C Libft clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(INCLUDES)
	@make -C Libft fclean

re: fclean all

.PHONY: all