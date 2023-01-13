/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composed_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 04:46:44 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/13 02:20:11 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	composed_map(t_map *map)
{
	map->y = 0;
	while (map->split_map[map->y])
	{
		map->x = 0;
		while (map->split_map[map->y][map->x])
		{
			if (map->split_map[map->y][map->x] != '0'
				|| map->split_map[map->y][map->x] != '1'
				|| map->split_map[map->y][map->x] != 'C'
				|| map->split_map[map->y][map->x] != 'E'
				|| map->split_map[map->y][map->x] != 'P'
				|| map->split_map[map->y][map->x] != 'M')
				return (0);
			map->x++;
		}
		map->y++;
	}
	return (1);
}
