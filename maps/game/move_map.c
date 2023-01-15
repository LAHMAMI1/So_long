/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 04:46:56 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/14 23:21:37 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	put_di(t_map *map, int x, int y)
{
	if (map->keycode == 0)
		a(map, x, y);
	else if (map->keycode == 2)
		d(map, x, y);
	else if (map->keycode == 1)
		s(map, x, y);
	else
		w(map, x, y);
}

static void	put_p(t_map *map, int y, int x)
{
	if (map->split_map[y][x] == '0')
	{
		map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr,
				"./textures/0.xpm", &map->show->w, &map->show->h);
		put_er_img(map);
		mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr,
			map->show->img, x * map->show->w, y * map->show->h);
		mlx_destroy_image(map->show->mlx_ptr, map->show->img);
	}
	else if (map->split_map[y][x] == 'P')
		put_di(map, x, y);
}

static void	mis_p(t_map *map, int pos_x, int pos_y)
{
	map->split_map[map->player->pos_y][map->player->pos_x] = '0';
	map->split_map[pos_y][pos_x] = 'P';
	put_p(map, map->player->pos_y, map->player->pos_x);
	put_p(map, pos_y, pos_x);
	map->player->pos_y = pos_y;
	map->player->pos_x = pos_x;
}

static void	move(t_map *map, int pos_y, int pos_x)
{
	if (map->split_map[pos_y][pos_x] == '0')
	{
		map->mov += 1;
		print_m(map);
		mis_p(map, pos_x, pos_y);
	}
	else if (map->split_map[pos_y][pos_x] == 'C')
	{
		map->mov += 1;
		print_m(map);
		map->check_c++;
		mis_p(map, pos_x, pos_y);
	}
	else if (map->split_map[pos_y][pos_x] == 'E'
			&& map->check_c == map->count[1])
	{
		ft_putstr_fd("YOU WIN", 2);
		exit(0);
	}
	move_sup(map);
}

int	move_map(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
	{
		map->keycode = keycode;
		move(map, map->player->pos_y - 1, map->player->pos_x);
	}
	if (keycode == 0)
	{
		map->keycode = keycode;
		move(map, map->player->pos_y, map->player->pos_x - 1);
	}
	if (keycode == 1)
	{
		map->keycode = keycode;
		move(map, map->player->pos_y + 1, map->player->pos_x);
	}
	if (keycode == 2)
	{
		map->keycode = keycode;
		move(map, map->player->pos_y, map->player->pos_x + 1);
	}
	return (0);
}
