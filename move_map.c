/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 04:46:56 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/07 02:37:04 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void move(t_map *map, int pos_y, int pos_x)
{
	if (map->split_map[pos_y][pos_x] == '0')
	{
		map->mov += 1;
		map->split_map[map->player->pos_y][map->player->pos_x] = '0';
		map->split_map[pos_y][pos_x] = 'P';
		map->player->pos_y = pos_y;
		map->player->pos_x = pos_x;
		showmap(map);
	}
	else if (map->split_map[pos_y][pos_x] == 'C')
	{
		map->mov += 1;
		map->check_c++;
		map->split_map[map->player->pos_y][map->player->pos_x] = '0';
		map->split_map[pos_y][pos_x] = 'P';
		map->player->pos_y = pos_y;
		map->player->pos_x = pos_x;
		showmap(map);
	}
	else if (map->split_map[pos_y][pos_x] == 'E' && map->check_c == map->count[1])
		exit(0);
}

int move_map(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
	{
		map->keycode = keycode;
		move(map, map->player->pos_y - 1, map->player->pos_x);
	}
	if (keycode == 0)
	{
		map->keycode = keycode;
		move(map, map->player->pos_y, map->player->pos_x - 1);
	}
	if (keycode == 1)
	{
		map->keycode = keycode;
		move(map, map->player->pos_y + 1, map->player->pos_x);
	}
	if (keycode == 2)
	{
		map->keycode = keycode;
		move(map, map->player->pos_y, map->player->pos_x + 1);
	}
	return (0);
}
