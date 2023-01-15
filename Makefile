# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 02:11:24 by olahmami          #+#    #+#              #
#    Updated: 2023/01/14 23:37:52 by olahmami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
NAME		=	so_long
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	maps/map_checker/utils.c \
				maps/map_checker/name_map.c \
				maps/map_checker/composed_map.c \
				maps/map_checker/onechar_map.c \
				maps/map_checker/rect_map.c \
				maps/map_checker/walls_map.c \
				maps/map_checker/path_map.c \
				maps/map_checker/check_all.c \
				maps/game/read_map.c \
				maps/game/show_map.c \
				maps/game/move_map.c \
				maps/game/button.c \
				so_long.c

LIBS		=	libft.a

BONUS		=	so_long_bonus

INCLUDES	=	$(LIBS:%=maps/Libft/libft.a)

MLX_macos	=	-lmlx -framework OpenGL -framework AppKit

OBJ = ${SRCS:.c=.o}

all: $(LIBS) $(NAME)

$(NAME): $(OBJ)
	$(CC) -I includes $(CFLAGS) $(OBJ) $(INCLUDES) $(MLX_macos) -o $(NAME)

libs: $(LIBS)

$(LIBS):
	@make -C maps/Libft

bonus: $(BONUS)

$(BONUS):
	@make -C Bonus

clean:
	@rm -f ${OBJ}
	@make -C maps/Libft clean
	@make -C Bonus clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(INCLUDES)
	@make -C maps/Libft fclean
	@make -C Bonus fclean

re: fclean all

.PHONY: all