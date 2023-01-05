/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 04:46:56 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/05 12:01:56 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void move(t_map *map, int pos_y, int pos_x)
{
	if (map->split_map[pos_y][pos_x] == '0')
	{
		map->split_map[map->player->pos_y][map->player->pos_x] = '0';
		map->split_map[pos_y][pos_x] = 'P';
		map->player->pos_y = pos_y;
		map->player->pos_x = pos_x;
		showmap(map);
	}
	else if (map->split_map[pos_y][pos_x] == 'C')
	{
		map->split_map[map->player->pos_y][map->player->pos_x] = '0';
		map->split_map[pos_y][pos_x] = 'P';
		map->player->pos_y = pos_y;
		map->player->pos_x = pos_x;
		showmap(map);
	}
}

int move_map(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
		move(map, map->player->pos_y - 1, map->player->pos_x);
	if (keycode == 0)
		move(map,  map->player->pos_y, map->player->pos_x - 1);
	if (keycode == 1)
		move(map, map->player->pos_y + 1, map->player->pos_x);
	if (keycode == 2)
		move(map, map->player->pos_y, map->player->pos_x + 1);
	return (0);
}
