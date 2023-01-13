/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 05:34:28 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/12 23:48:21 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	wall_map(t_map *map)
{
	int	y;

	y = 0;
	while (map->split_map[y])
	{
		if (ft_strchr_wm(map->split_map[0], '1') == 1
			|| ft_strchr_wm(map->split_map[count_line(map) - 1], '1') == 1)
			return (1);
		map->x = 0;
		while (map->split_map[y][map->x])
		{
			if (map->split_map[y][0] != '1'
				|| map->split_map[y][ft_strlen(map->split_map[y]) - 1] != '1')
				return (1);
			map->x++;
		}
		y++;
	}
	return (0);
}
