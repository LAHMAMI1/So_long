# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 02:11:24 by olahmami          #+#    #+#              #
#    Updated: 2023/01/14 17:04:03 by olahmami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
NAME		=	so_long_bonus
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	maps/map_checker/utils_bonus.c \
				maps/map_checker/name_map_bonus.c \
				maps/map_checker/composed_map_bonus.c \
				maps/map_checker/onechar_map_bonus.c \
				maps/map_checker/rect_map_bonus.c \
				maps/map_checker/walls_map_bonus.c \
				maps/map_checker/path_map_bonus.c \
				maps/map_checker/check_all_bonus.c \
				maps/game/read_map_bonus.c \
				maps/game/show_map_bonus.c \
				maps/game/move_map_bonus.c \
				maps/game/button_bonus.c \
				maps/game/enemies_bonus.c \
				maps/game/animation.c \
				so_long_bonus.c

LIBS		=	libft.a

INCLUDES	=	$(LIBS:%=maps/Libft/libft.a)

MLX_macos	=	-lmlx -framework OpenGL -framework AppKit

OBJ = ${SRCS:.c=.o}

all: $(LIBS) $(NAME)

$(NAME): $(OBJ)
	$(CC) -I includes $(CFLAGS) $(OBJ) $(INCLUDES) $(MLX_macos) -o $(NAME)

libs: $(LIBS)

$(LIBS):
	@make -C maps/Libft

clean:
	@rm -f ${OBJ}
	@make -C maps/Libft clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(INCLUDES)
	@make -C maps/Libft fclean

re: fclean all

.PHONY: all