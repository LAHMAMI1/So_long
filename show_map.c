/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 00:46:26 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/03 02:46:08 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void put_img(map *map, show *show, char *path_img, char c)
{
	show->img = mlx_xpm_file_to_image(show->mlx_ptr, path_img, &show->width, &show->height);
	if (map->split_map[map->y][map->x] == c)
		mlx_put_image_to_window(show->mlx_ptr, show->win_ptr, show->img, map->x *  show->width, map->y * show->height);
}

void showmap(map *map, show *show)
{
	map->len = ft_strlen(map->split_map[0]);
	show->mlx_ptr = mlx_init();
	show->win_ptr = mlx_new_window(show->mlx_ptr, 80 * map->len, 80 * map->lines, "So_long");
	map->y = 0;
	while (map->split_map[map->y])
	{
		map->x = 0;
		while (map->split_map[map->y][map->x])
		{
			put_img(map, show, "./img/0.xpm", '0');
			put_img(map, show, "./img/1.xpm", '1');
			put_img(map, show, "./img/P.xpm", 'P');
			put_img(map, show, "./img/C.xpm", 'C');
			put_img(map, show, "./img/E0.xpm", 'E');
			map->x++;
		}
		map->y++;
	}
	mlx_loop(show->mlx_ptr);
}