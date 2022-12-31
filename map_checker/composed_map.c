/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composed_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 04:46:44 by olahmami          #+#    #+#             */
/*   Updated: 2022/12/31 05:01:04 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	composed_map(map *map)
{
	map->y = 0;
	while (map->split_map[map->y])
	{
		map->x = 0;
		while (map->split_map[map->y][map->x])
		{
			if (map->split_map[map->y][map->x] != '0'
				&& map->split_map[map->y][map->x] != '1'
				&& map->split_map[map->y][map->x] != 'C'
				&& map->split_map[map->y][map->x] != 'E'
				&& map->split_map[map->y][map->x] != 'P')
				return (1);
			map->x++;
		}
		map->y++;
	}
	return (0);
}
