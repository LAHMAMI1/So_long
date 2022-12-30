/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:54:09 by olahmami          #+#    #+#             */
/*   Updated: 2022/12/30 04:12:30 by olahmami         ###   ########.fr       */
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
}map;
typedef struct PLAYER
{
	int pos_x;
	int pos_y;
}player;
/*So_long*/
char **read_map(int fd, map *map);
int composed_map(map *map);
int oneChar_map(map *map, player *player);
int rectangular_map(map *map);
int wall_map(map *map);
void all_check(map *map, player *player);
int name_map(char *name);

#endif