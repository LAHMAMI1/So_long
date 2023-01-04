/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 05:34:28 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/04 01:20:47 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_strchr_wm(char *split_map, int c)
{
	unsigned int	i;

	i = 0;
	while (split_map[i] && (char)c == split_map[i])
		i++;
	if (i < ft_strlen(split_map))
		return (1);
	return (0);
}

int	count_line(t_map *map)
{
	map->lines = 0;
	while (map->split_map[map->lines])
		map->lines++;
	return (map->lines);
}

int	wall_map(t_map *map)
{
	map->y = 0;
	while (map->split_map[map->y])
	{
		if (ft_strchr_wm(map->split_map[0], '1') == 1
			|| ft_strchr_wm(map->split_map[count_line(map) - 1], '1') == 1)
			return (1);
		map->x = 0;
		while (map->split_map[map->y][map->x])
		{
			if (map->split_map[map->y][0] != '1'
				|| map->split_map[map->y][ft_strlen(map->split_map[map->y]) - 1] != '1')
				return (1);
			map->x++;
		}
		map->y++;
	}
	return (0);
}
