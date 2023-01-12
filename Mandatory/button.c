/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:40:58 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/12 18:11:00 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	a(t_map *map, int x, int y)
{
	static int	m;

	if (m)
	{
		m = 0;
		map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr,
				"./img/PL1.xpm", &map->show->w, &map->show->h);
		mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr,
			map->show->img, x * map->show->w, y * map->show->h);
		mlx_destroy_image(map->show->mlx_ptr, map->show->img);
	}
	else
	{
		m = 1;
		map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr,
				"./img/PL2.xpm", &map->show->w, &map->show->h);
		mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr,
			map->show->img, x * map->show->w, y * map->show->h);
		mlx_destroy_image(map->show->mlx_ptr, map->show->img);
	}
}

void	d(t_map *map, int x, int y)
{
	static int	m;

	if (m)
	{
		m = 0;
		map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr,
				"./img/PR1.xpm", &map->show->w, &map->show->h);
		mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr,
			map->show->img, x * map->show->w, y * map->show->h);
		mlx_destroy_image(map->show->mlx_ptr, map->show->img);
	}
	else
	{
		m = 1;
		map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr,
				"./img/PR2.xpm", &map->show->w, &map->show->h);
		mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr,
			map->show->img, x * map->show->w, y * map->show->h);
		mlx_destroy_image(map->show->mlx_ptr, map->show->img);
	}
}

void	w(t_map *map, int x, int y)
{
	static int	m;

	if (m)
	{
		m = 0;
		map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr,
				"./img/PU1.xpm", &map->show->w, &map->show->h);
		mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr,
			map->show->img, x * map->show->w, y * map->show->h);
		mlx_destroy_image(map->show->mlx_ptr, map->show->img);
	}
	else
	{
		m = 1;
		map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr,
				"./img/PU2.xpm", &map->show->w, &map->show->h);
		mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr,
			map->show->img, x * map->show->w, y * map->show->h);
		mlx_destroy_image(map->show->mlx_ptr, map->show->img);
	}
}

void	s(t_map *map, int x, int y)
{
	static int	m;

	if (m)
	{
		m = 0;
		map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr,
				"./img/PD1.xpm", &map->show->w, &map->show->h);
		mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr,
			map->show->img, x * map->show->w, y * map->show->h);
		mlx_destroy_image(map->show->mlx_ptr, map->show->img);
	}
	else
	{
		m = 1;
		map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr,
				"./img/PD2.xpm", &map->show->w, &map->show->h);
		mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr,
			map->show->img, x * map->show->w, y * map->show->h);
		mlx_destroy_image(map->show->mlx_ptr, map->show->img);
	}
}
