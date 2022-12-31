/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 07:33:55 by olahmami          #+#    #+#             */
/*   Updated: 2022/12/31 07:38:09 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**map_dup(map *map)
{
	int	i;

	i = 0;
	map->dup_map = ft_calloc(map->lines, (sizeof(char *)));
	while (map->split_map[i])
	{
		map->dup_map[i] = ft_strdup(map->split_map[i]);
		i++;
	}
	return (map->dup_map);
}

void	flood_fill_p(int pos_x, int pos_y, char **map)
{
	if (map[pos_y][pos_x] != '0' && map[pos_y][pos_x] != 'C'
		&& map[pos_y][pos_x] != 'P')
		return ;
	map[pos_y][pos_x] = 'F';
	flood_fill_p(pos_x + 1, pos_y, map);
	flood_fill_p(pos_x, pos_y + 1, map);
	flood_fill_p(pos_x, pos_y - 1, map);
	flood_fill_p(pos_x - 1, pos_y, map);
	return ;
}

void	flood_fill_e(int pos_x, int pos_y, char **map)
{
	if ((map[pos_y][pos_x] != '0' && map[pos_y][pos_x] != 'C'
		&& map[pos_y][pos_x] != 'E'))
		return ;
	map[pos_y][pos_x] = 'I';
	flood_fill_e(pos_x + 1, pos_y, map);
	flood_fill_e(pos_x, pos_y + 1, map);
	flood_fill_e(pos_x, pos_y - 1, map);
	flood_fill_e(pos_x - 1, pos_y, map);
	return ;
}
