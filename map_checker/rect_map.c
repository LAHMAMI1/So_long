/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 05:19:58 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/07 20:13:54 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int no_line(t_map *map)
{
	int i = 0;
	while (map->str[i])
	{
		if (map->str[0] == '\n' || map->str[ft_strlen(map->str) - 1] == '\n' || (map->str[i] == '\n' && map->str[i + 1] == '\n'))
		{
			free(map->str);
			return (1);
		}
		i++;
	}
	free(map->str);
	return (0);
}

int	rectangular_map(t_map *map)
{
	int	increment;

	map->y = 0;
	increment = map->y + 1;
	while (map->split_map[map->y])
	{
		if (ft_strlen(map->split_map[map->y]) == ft_strlen(map->split_map[increment]))
			map->y++;
		else
			return (1);
	}
	return (0);
}
