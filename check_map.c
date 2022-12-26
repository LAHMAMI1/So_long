/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:05:13 by olahmami          #+#    #+#             */
/*   Updated: 2022/12/26 18:31:33 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int composed_map(char **split_map)
{
	int y;
	int x;

	y = 0;
	while (split_map[y])
	{
		x = 0;
		while (split_map[y][x])
		{
			if (split_map[y][x] != '0' && split_map[y][x] != '1' && split_map[y][x] != 'C' && split_map[y][x] != 'E' && split_map[y][x] != 'P')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int oneChar_map(char **split_map)
{
	int y;
	int x;
	int count[3];

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	y = 0;
	while (split_map[y])
	{
		x = 0;
		while (split_map[y][x])
		{
			if (split_map[y][x] == 'P')
				count[0]++;
			if (split_map[y][x] == 'C')
				count[1]++;
			if (split_map[y][x] == 'E')
				count[2]++;
			x++;
		}
		y++;
	}
	if (count[0] != 1 || count[1] == 0 || count[2] != 1)
		return (1);
	return (0);
} 