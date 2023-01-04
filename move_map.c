/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 04:46:56 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/04 08:21:38 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int move_map(int keycode, t_map *map)
{
	if (keycode == 13)
	{
		if (map->split_map[map->player->pos_y - 1][map->player->pos_x] == '0')
		{
			map->split_map[map->player->pos_y][map->player->pos_x] = '0';
			map->split_map[map->player->pos_y - 1][map->player->pos_x] = 'P';
			map->player->pos_y -= 1;
			showmap(map);
		}
		else if (map->split_map[map->player->pos_y - 1][map->player->pos_x] == 'C')
		{
			map->split_map[map->player->pos_y][map->player->pos_x] = '0';
			map->split_map[map->player->pos_y - 1][map->player->pos_x] = 'P';
			map->player->pos_y -= 1;
			showmap(map);
		}
	}
	else if (keycode == 0)
	{
		if (map->split_map[map->player->pos_y][map->player->pos_x - 1] == '0')
		{
			map->split_map[map->player->pos_y][map->player->pos_x] = '0';
			map->split_map[map->player->pos_y][map->player->pos_x - 1] = 'P';
			map->player->pos_x -= 1;
			showmap(map);
		}
		else if (map->split_map[map->player->pos_y][map->player->pos_x - 1] == 'C')
		{
			map->split_map[map->player->pos_y][map->player->pos_x] = '0';
			map->split_map[map->player->pos_y][map->player->pos_x - 1] = 'P';
			map->player->pos_x -= 1;
			showmap(map);
		}
	}
	else if (keycode == 1)
	{
		if (map->split_map[map->player->pos_y + 1][map->player->pos_x] == '0')
		{
			map->split_map[map->player->pos_y][map->player->pos_x] = '0';
			map->split_map[map->player->pos_y + 1][map->player->pos_x] = 'P';
			map->player->pos_y += 1;
			showmap(map);
		}
		else if (map->split_map[map->player->pos_y + 1][map->player->pos_x] == 'C')
		{
			map->split_map[map->player->pos_y][map->player->pos_x] = '0';
			map->split_map[map->player->pos_y + 1][map->player->pos_x] = 'P';
			map->player->pos_y += 1;
			showmap(map);
		}
	}
	else if (keycode == 2)
	{
		if (map->split_map[map->player->pos_y][map->player->pos_x + 1] == '0')
		{
			map->split_map[map->player->pos_y][map->player->pos_x] = '0';
			map->split_map[map->player->pos_y][map->player->pos_x + 1] = 'P';
			map->player->pos_x += 1;
			showmap(map);
		}
		else if (map->split_map[map->player->pos_y][map->player->pos_x + 1] == 'C')
		{
			map->split_map[map->player->pos_y][map->player->pos_x] = '0';
			map->split_map[map->player->pos_y][map->player->pos_x + 1] = 'P';
			map->player->pos_x += 1;
			showmap(map);
		}
	}
	return (0);
}
