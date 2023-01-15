/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 07:42:49 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/15 00:19:56 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	flood_test(t_map *map, t_player *player)
{
	map->dup_map = map_dup(map);
	flood_fill_p(player->pos_x, player->pos_y, map->dup_map);
	if (check_path(map, 'C') == 1)
	{
		ft_putstr_fd("Error:\nThere still a collectible in the map", 2);
		exit(1);
	}
	flood_fill_e(player->pos_x, player->pos_y, map->dup_map);
	if (check_path(map, 'E') == 1)
	{
		ft_putstr_fd("Error:\nThe player is unable to exit", 2);
		exit(1);
	}
}

void	all_check(t_map *map, t_player *player)
{
	if (composed_map(map) == 1)
	{
		ft_putstr_fd("Error:\nShould be composed with 0,1,P,C,E", 2);
		exit(1);
	}
	else if (onechar_map(map, player) == 1)
	{
		ft_putstr_fd("Error:\none of the character is missing", 2);
		ft_putstr_fd(" or there's a double 'E' or 'P'", 2);
		exit(1);
	}
	else if (rectangular_map(map) == 1 || no_line(map) == 1)
	{
		ft_putstr_fd("Error:\nIt must be rectangular", 2);
		ft_putstr_fd("or there's a new line", 2);
		exit(1);
	}
	else if (wall_map(map) == 1)
	{
		ft_putstr_fd("Error:\nIt must be surrounded by walls", 2);
		exit(1);
	}
	flood_test(map, player);
}
