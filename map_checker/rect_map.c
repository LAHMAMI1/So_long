/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 05:19:58 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/04 01:20:47 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	rectangular_map(t_map *map)
{
	int	increment;

	map->y = 0;
	increment = map->y + 1;
	while (map->split_map[map->y])
	{
		if (ft_strlen(map->split_map[map->y])
			== ft_strlen(map->split_map[increment]))
			map->y++;
		else
			return (1);
	}
	return (0);
}
