/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:44:43 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/14 20:45:27 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static void	animation_min1(t_map *map)
{
	if (map->split_map[map->y][map->x] == 'C' && map->j == 0)
		put_img(map, "./textures/C1.xpm", 'C');
	else if (map->split_map[map->y][map->x] == 'C' && map->j == 1)
		put_img(map, "./textures/C2.xpm", 'C');
	else if (map->split_map[map->y][map->x] == 'C' && map->j == 2)
		put_img(map, "./textures/C3.xpm", 'C');
	else if (map->split_map[map->y][map->x] == 'C' && map->j == 3)
		put_img(map, "./textures/C4.xpm", 'C');
	else if (map->split_map[map->y][map->x] == 'C' && map->j == 4)
		put_img(map, "./textures/C5.xpm", 'C');
	else if (map->split_map[map->y][map->x] == 'C' && map->j == 5)
		put_img(map, "./textures/C6.xpm", 'C');
	else if (map->split_map[map->y][map->x] == 'C' && map->j == 6)
		put_img(map, "./textures/C7.xpm", 'C');
	else if (map->split_map[map->y][map->x] == 'C' && map->j == 7)
		put_img(map, "./textures/C8.xpm", 'C');
}

static void	animation_min2(t_map *map)
{
	if (map->split_map[map->y][map->x] == 'C' && map->j == 0)
		map->j = 1;
	else if (map->split_map[map->y][map->x] == 'C' && map->j == 1)
		map->j = 2;
	else if (map->split_map[map->y][map->x] == 'C' && map->j == 2)
		map->j = 3;
	else if (map->split_map[map->y][map->x] == 'C' && map->j == 3)
		map->j = 4;
	else if (map->split_map[map->y][map->x] == 'C' && map->j == 4)
		map->j = 5;
	else if (map->split_map[map->y][map->x] == 'C' && map->j == 5)
		map->j = 6;
	else if (map->split_map[map->y][map->x] == 'C' && map->j == 6)
		map->j = 7;
	else if (map->split_map[map->y][map->x] == 'C' && map->j == 7)
		map->j = 0;
}

int	animation(t_map *map)
{
	static int	i;

	move_m(map);
	if (i == 4000)
	{
		map->y = 0;
		while (map->split_map[map->y])
		{
			map->x = 0;
			while (map->split_map[map->y][map->x])
			{
				animation_min1(map);
				animation_min2(map);
				map->x++;
			}
			map->y++;
		}
		i = 0;
	}
	i++;
	return (0);
}
