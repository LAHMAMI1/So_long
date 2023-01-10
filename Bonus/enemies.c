/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:57:22 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/10 22:53:19 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_patrol(int m_x, int m_y, t_map *map)
{
	map->split_map[map->player->m_y][map->player->m_x] = '0';
	map->split_map[m_y][m_x] = 'M';
	map->player->m_y = m_y;
	map->player->m_x = m_x;
	showmap(map);
}

int move_m(t_map *map)
{
	static int r = 0;
	if(map->split_map[map->player->m_y][map->player->m_x - 1] == '0' && r == 0)
		move_patrol(map->player->m_x - 1, map->player->m_y, map); 
	else if(map->split_map[map->player->m_y][map->player->m_x + 1] == '0' && r == 1)
		move_patrol(map->player->m_x + 1, map->player->m_y, map);
	if(map->split_map[map->player->m_y][map->player->m_x - 1] != '0')
		r=1;
	else if (map->split_map[map->player->m_y][map->player->m_x + 1] != '0')
		r=0;
	if (map->split_map[map->player->m_y][map->player->m_x + 1] == 'P' || map->split_map[map->player->m_y][map->player->m_x - 1] == 'P')
	{
		ft_putstr_fd("YOU LOSE", 2);
		exit(0);
	}
	return (0);
}