/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 00:46:26 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/02 08:00:25 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void showmap(map *map)
{
	void *mlx_ptr;
	void *win_ptr;
	void *img;
	void *img1;
	void *img2;
	void *img3;
	void *img4;
	int width;
	int height;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2720, 480, "So_long");
	img = mlx_xpm_file_to_image(mlx_ptr, "./img/0.xpm", &width, &height);
	img1 = mlx_xpm_file_to_image(mlx_ptr, "./img/1.xpm", &width, &height);
	img2 = mlx_xpm_file_to_image(mlx_ptr, "./img/P.xpm", &width, &height);
	img3 = mlx_xpm_file_to_image(mlx_ptr, "./img/C.xpm", &width, &height);
	img4 = mlx_xpm_file_to_image(mlx_ptr, "./img/E0.xpm", &width, &height);

	map->y = 0;
	while (map->split_map[map->y])
	{
		map->x = 0;
		while (map->split_map[map->y][map->x])
		{
			if (map->split_map[map->y][map->x] == '0')
			{
				mlx_put_image_to_window(mlx_ptr, win_ptr, img, map->x * width, map->y * height);
			}
			if (map->split_map[map->y][map->x] == '1')
			{
				mlx_put_image_to_window(mlx_ptr, win_ptr, img1, map->x * width, map->y * height);
			}
			if (map->split_map[map->y][map->x] == 'P')
			{
				mlx_put_image_to_window(mlx_ptr, win_ptr, img2, map->x * width, map->y * height);
			}
			if (map->split_map[map->y][map->x] == 'C')
			{
				mlx_put_image_to_window(mlx_ptr, win_ptr, img3, map->x * width, map->y * height);
			}
			if (map->split_map[map->y][map->x] == 'E')
			{
				mlx_put_image_to_window(mlx_ptr, win_ptr, img4, map->x * width, map->y * height);
			}
			map->x++;
		}
		map->y++;
	}
	
	mlx_loop(mlx_ptr);
}