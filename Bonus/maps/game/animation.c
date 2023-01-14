/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:44:43 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/14 05:05:17 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	animation(t_map *map)
{
	static int i;
	static int j;
	move_m(map);
	if (i == 4000)
	{
		map->y = 0;
		while (map->split_map[map->y])
		{
			map->x = 0;
			while (map->split_map[map->y][map->x])
			{
				if (map->split_map[map->y][map->x])
				{
					if (map->split_map[map->y][map->x] == 'C' && j == 0)
					{
						put_img(map, "./textures/C1.xpm", 'C');
						// mlx_clear_window(map->show->mlx_ptr, map->show->win_ptr);
						j = 1;
					}
					else if (map->split_map[map->y][map->x] == 'C' && j == 1)
					{
						put_img(map, "./textures/C2.xpm", 'C');
						// mlx_clear_window(map->show->mlx_ptr, map->show->win_ptr);
						j = 2;
					}
					else if (map->split_map[map->y][map->x] == 'C' && j == 2)
					{
						put_img(map, "./textures/C3.xpm", 'C');
						// mlx_clear_window(map->show->mlx_ptr, map->show->win_ptr);
						j = 3;
					}
					else if (map->split_map[map->y][map->x] == 'C' && j == 3)
					{
						put_img(map, "./textures/C4.xpm", 'C');
						// mlx_clear_window(map->show->mlx_ptr, map->show->win_ptr);
						j = 4;
					}
					else if (map->split_map[map->y][map->x] == 'C' && j == 4)
					{
						put_img(map, "./textures/C5.xpm", 'C');
						// mlx_clear_window(map->show->mlx_ptr, map->show->win_ptr);
						j = 5;
					}
					else if (map->split_map[map->y][map->x] == 'C' && j == 5)
					{
						put_img(map, "./textures/C6.xpm", 'C');
						// mlx_clear_window(map->show->mlx_ptr, map->show->win_ptr);
						j = 6;
					}
					else if (map->split_map[map->y][map->x] == 'C' && j == 6)
					{
						put_img(map, "./textures/C7.xpm", 'C');
						// mlx_clear_window(map->show->mlx_ptr, map->show->win_ptr);
						j = 7;
					}
					else if (map->split_map[map->y][map->x] == 'C' && j == 7)
					{
						put_img(map, "./textures/C8.xpm", 'C');
						// mlx_clear_window(map->show->mlx_ptr, map->show->win_ptr);
						j = 0;
					}
				}
				map->x++;
			}
			map->y++;
		}
		i = 0;
	}
	i++;
	
	return (0);
}