/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:57:22 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/14 23:25:45 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static void	put_m(t_map *map, int m_x, int m_y)
{
	if (map->split_map[m_y][m_x] == '0')
	{
		map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr,
				"./textures/0.xpm", &map->show->w, &map->show->h);
		put_er_img(map);
		mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr,
			map->show->img, m_x * map->show->w, m_y * map->show->h);
		mlx_destroy_image(map->show->mlx_ptr, map->show->img);
	}
	else if (map->split_map[m_y][m_x] == 'M')
	{
		map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr,
				"./textures/M.xpm", &map->show->w, &map->show->h);
		put_er_img(map);
		mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr,
			map->show->img, m_x * map->show->w, m_y * map->show->h);
		mlx_destroy_image(map->show->mlx_ptr, map->show->img);
	}
}

void	move_patrol(int m_x, int m_y, t_map *map)
{
	map->split_map[map->player->m_y][map->player->m_x] = '0';
	map->split_map[m_y][m_x] = 'M';
	put_m(map, map->player->m_x, map->player->m_y);
	put_m(map, m_x, m_y);
	map->player->m_y = m_y;
	map->player->m_x = m_x;
}

int	move_m(t_map *map)
{
	static int	i;
	static int	r;

	if (i == 3000)
	{
		if (map->split_map[map->player->m_y][map->player->m_x + 1] == 'P'
			|| map->split_map[map->player->m_y][map->player->m_x - 1] == 'P')
		{
			ft_putstr_fd("YOU LOSE", 2);
			exit(0);
		}
		if (map->split_map[map->player->m_y][map->player->m_x - 1] == '0'
			&& r == 0)
			move_patrol(map->player->m_x - 1, map->player->m_y, map);
		else if (map->split_map[map->player->m_y][map->player->m_x + 1] == '0'
				&& r == 1)
			move_patrol(map->player->m_x + 1, map->player->m_y, map);
		if (map->split_map[map->player->m_y][map->player->m_x - 1] != '0')
			r = 1;
		else if (map->split_map[map->player->m_y][map->player->m_x + 1] != '0')
			r = 0;
		i = 0;
	}
	i++;
	return (0);
}
