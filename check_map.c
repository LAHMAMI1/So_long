/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:05:13 by olahmami          #+#    #+#             */
/*   Updated: 2022/12/29 03:53:27 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//The map can be composed of only these 5 characters
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

//The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
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

//The map must be rectangular.
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

//The map must be closed/surrounded by walls.
static int ft_strchr_WM(char *split_map, int c)
{
	unsigned int i;

	i = 0;
	while (split_map[i] && (char)c == split_map[i])
		i++;
	if (i < ft_strlen(split_map))
		return (1);
	return (0);
}

static int count_line(char **str)
{
	int y;
	
	y = 0;
	while (str[y])
		y++;
	return (y);
}

int wall_map(char **split_map)
{
	int y;
	int x;

	y = 0;
	while (split_map[y])
	{
		if (ft_strchr_WM(split_map[0], '1') == 1 || ft_strchr_WM(split_map[count_line(split_map) - 1], '1') == 1)
			return (1);
		x = 0;
		while (split_map[y][x])
		{
			if (split_map[y][0] != '1' || split_map[y][ft_strlen(*split_map) - 1] != '1')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

//Valid path


//name of map file
int name_map(char *name)
{
	if (ft_strncmp(name + (ft_strlen(name) - 4), ".ber", 4))
		return (1);
	return (0);
}

//ALL checkers for map
void all_check(char **split_map)
{
	if (composed_map(split_map) == 1 || oneChar_map(split_map) == 1 || rectangular_map(split_map) == 1 || wall_map(split_map) == 1)
	{
		printf("False");
		exit(1);
	}
	else
		printf("True");
}