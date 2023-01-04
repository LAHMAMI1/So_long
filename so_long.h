/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:54:09 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/04 03:25:23 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "Libft/libft.h"

typedef struct s_show
{
	void *mlx_ptr;
	void *win_ptr;
	void *img;
	int width;
	int height;
} t_show;

typedef struct s_player
{
	int pos_x;
	int pos_y;
} t_player;

typedef struct s_map
{
	char **split_map;
	int y;
	int x;
	int lines;
	int len;
	char **dup_map;
	int count[3];
	t_show *show;
	t_player *player;
} t_map;

/*So_long*/
char **read_map(int fd, t_map *map);
int composed_map(t_map *map);
int onechar_map(t_map *map, t_player *player);
int rectangular_map(t_map *map);
int wall_map(t_map *map);
void all_check(t_map *map, t_player *player);
int name_map(char *name);
char **map_dup(t_map *map);
void flood_fill_p(int pos_x, int pos_y, char **map);
void flood_fill_e(int pos_x, int pos_y, char **map);
int count_line(t_map *map);
int check_path(t_map *map, char c);
void showmap(t_map *map);
int move_map(int keycode, t_map *map);

#endif