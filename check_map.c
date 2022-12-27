/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:05:13 by olahmami          #+#    #+#             */
/*   Updated: 2022/12/27 04:47:37 by olahmami         ###   ########.fr       */
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

int rectangular_map(char **split_map)
{
	int y;
	int increment;

	y = 0;
	increment = y + 1;
	while (split_map[y])
	{
		if (ft_strlen(split_map[y]) == ft_strlen(split_map[increment]))
			y++;
		else
			return (1);
	}
	return (0);
}

static int ft_strchr_WM(char *split_map, int c)
{
	unsigned int i;
	
	i = 0;
	while (split_map[i] && (char)c == split_map[i])
		i++;
	if (i <= ft_strlen(split_map))
		return (1);
	return (0);
}

int wall_map(char **split_map)
{
	int y;
	int x;

	y = 0;
	while (split_map[y])
	{
		if (ft_strchr_WM(split_map[0], '1') == 1 || ft_strchr_WM(split_map[ft_strlen(*split_map) - 1], '1') == 1)
			return (1);
		x = 0;
		while (split_map[y][x])
		{
			if (split_map[y][x] != '1' || split_map[y][ft_strlen(split_map[y] - 1)] != '1')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}