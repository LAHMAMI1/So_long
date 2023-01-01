/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:54:09 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/01 09:14:01 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "Libft/libft.h"

typedef struct MAP
{
	char **split_map;
	int y;
	int x;
	int lines;
	char **dup_map;
	int count[3];
}map;
typedef struct PLAYER
{
	int pos_x;
	int pos_y;
}player;
/*So_long*/
char **read_map(int fd, map *map);
int composed_map(map *map);
int onechar_map(map *map, player *player);
int rectangular_map(map *map);
int wall_map(map *map);
void all_check(map *map, player *player);
int name_map(char *name);
char **map_dup(map *map);
void	flood_fill_p(int pos_x, int pos_y, char **map);
void	flood_fill_e(int pos_x, int pos_y, char **map);
int	count_line(map *map);
int check_path(map *map, char c);

#endif