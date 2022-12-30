/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:05:13 by olahmami          #+#    #+#             */
/*   Updated: 2022/12/30 04:12:03 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//The map can be composed of only these 5 characters
int composed_map(map *map)
{
	// int y;
	// int x;
	

	map->y = 0;
	while (map->split_map[map->y])
	{
		map->x = 0;
		while (map->split_map[map->y][map->x])
		{
			if (map->split_map[map->y][map->x] != '0' && map->split_map[map->y][map->x] != '1' && map->split_map[map->y][map->x] != 'C' && map->split_map[map->y][map->x] != 'E' && map->split_map[map->y][map->x] != 'P')
				return (1);
			map->x++;
		}
		map->y++;
	}
	return (0);
}

//The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
int oneChar_map(map *map, player *player)
{
	// int y;
	// int x;
	int count[3];

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	map->y = 0;
	while (map->split_map[map->y])
	{
		map->x = 0;
		while (map->split_map[map->y][map->x])
		{
			if (map->split_map[map->y][map->x] == 'P')
			{
				player->pos_x = map->x;
				player->pos_y = map->y;
				count[0]++;
			}
			if (map->split_map[map->y][map->x] == 'C')
				count[1]++;
			if (map->split_map[map->y][map->x] == 'E')
				count[2]++;
			map->x++;
		}
		map->y++;
	}
	if (count[0] != 1 || count[1] == 0 || count[2] != 1)
		return (1);
	return (0);
}

//The map must be rectangular.
int rectangular_map(map *map)
{
	// int y;
	int increment;

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

int wall_map(map *map)
{
	// int y;
	// int x;

	map->y = 0;
	while (map->split_map[map->y])
	{
		if (ft_strchr_WM(map->split_map[0], '1') == 1 || ft_strchr_WM(map->split_map[count_line(map->split_map) - 1], '1') == 1)
			return (1);
		map->x = 0;
		while (map->split_map[map->y][map->x])
		{
			if (map->split_map[map->y][0] != '1' || map->split_map[map->y][ft_strlen(map->split_map[map->y]) - 1] != '1')
				return (1);
			map->x++;
		}
		map->y++;
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
void all_check(map *map, player *player)
{
	if (composed_map(map) == 1 || oneChar_map(map, player) == 1 || rectangular_map(map) == 1 || wall_map(map) == 1)
	{
		printf("False");
		exit(1);
	}
	else
		printf("True");
}