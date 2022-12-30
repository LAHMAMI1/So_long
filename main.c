/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:57:25 by olahmami          #+#    #+#             */
/*   Updated: 2022/12/30 04:23:06 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	// void *mlx_ptr;
	// void *win_ptr;
	// void *img;
	// int width, height;
	if (argc != 2)
	{
		ft_putstr_fd("Error:\n",2);
		perror("");
		exit(1);
	}
	if (name_map(argv[1]) == 1)
	{
		ft_putstr_fd("Error:\n",2);
		perror("");
		exit(1);
	}
	// int fd = open("map.ber", O_RDONLY);
	// int x;
	// int y;

	int fd = open(argv[1], O_RDONLY);
	map map;
	player player;
	// char **split_map;
	// int s;

	// if (fd == -1)
	// {
	// 	perror("Error opening file");
	// 	return (0);
	// }
	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "So_long");
	// img = mlx_xpm_file_to_image(mlx_ptr, "./ccc.xpm", &width, &height);

	map.split_map = read_map(fd, &map);
	all_check(&map, &player);
	// read_map(fd);

	// y = 0;
	// s = 0;
	// while (split_map[y])
	// {
	// 	x = 0;
	// 	while (split_map[y][x])
	// 	{
	// 		if (split_map[y][x] == '1')
	// 		{
	// 			mlx_put_image_to_window(mlx_ptr, win_ptr, img, x * width, y * height);
	// 		}
	// 		x++;
	// 	}
	// 	y++;
	// }

	// mlx_loop(mlx_ptr);

	// if (wall_map(split_map) == 1)
	// 	printf("False");
	// else
	// 	printf("True");
	return (0);
}
