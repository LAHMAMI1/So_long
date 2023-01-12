/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 04:46:56 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/12 00:31:25 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void put_pi(t_map *map, char *path, int x, int y)
{
	map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr, path,
			&map->show->w, &map->show->h);
	mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr,
			map->show->img, x * map->show->w, y * map->show->h);
	mlx_destroy_image(map->show->mlx_ptr, map->show->img);
}

static void put_p(t_map *map, int y, int x)
{
	if (map->split_map[y][x] == '0')
	{
		map->show->img = mlx_xpm_file_to_image(map->show->mlx_ptr, "./img/0.xpm",
			&map->show->w, &map->show->h);
		mlx_put_image_to_window(map->show->mlx_ptr, map->show->win_ptr,
			map->show->img, x * map->show->w, y * map->show->h);
		mlx_destroy_image(map->show->mlx_ptr, map->show->img);
	}
	else if (map->split_map[y][x] == 'P')
	{
		if (map->keycode == 0)
			put_pi(map, "./img/PL.xpm", x, y);
		else if (map->keycode == 1)
			put_pi(map, "./img/PD.xpm", x, y);
		else if (map->keycode == 13)
			put_pi(map, "./img/PU.xpm", x, y);
		else
			put_pi(map, "./img/PR.xpm", x, y);
	}
}

static void move_sup(t_map *map)
{
	map->y = 0;
	while (map->split_map[map->y])
	{
		map->x = 0;
		while (map->split_map[map->y][map->x])
		{
			if (map->check_c == map->count[1])
				put_img(map, "./img/E1.xpm", 'E');
			map->x++;
		}
		map->y++;
	}
}

static void	move(t_map *map, int pos_y, int pos_x)
{
	if (map->split_map[pos_y][pos_x] == '0')
	{
		map->mov += 1;
		print_m(map);
		map->split_map[map->player->pos_y][map->player->pos_x] = '0';
		map->split_map[pos_y][pos_x] = 'P';
		put_p(map, map->player->pos_y, map->player->pos_x);
		put_p(map, pos_y, pos_x);
		map->player->pos_y = pos_y;
		map->player->pos_x = pos_x;
	}
	else if (map->split_map[pos_y][pos_x] == 'C')
	{
		map->mov += 1;
		print_m(map);
		map->check_c++;
		map->split_map[map->player->pos_y][map->player->pos_x] = '0';
		map->split_map[pos_y][pos_x] = 'P';
		put_p(map, map->player->pos_y, map->player->pos_x);
		put_p(map, pos_y, pos_x);
		map->player->pos_y = pos_y;
		map->player->pos_x = pos_x;
	}
	else if (map->split_map[pos_y][pos_x]
			== 'E' && map->check_c == map->count[1])
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
