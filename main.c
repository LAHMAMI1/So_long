/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:57:25 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/07 17:38:52 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void check_arg(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr_fd("Error:\nInvalid number of arguments\nTry ./so_long 'map.ber'", 2);
		exit(1);
	}
	else if (name_map(argv[1]) == 1)
	{
		ft_putstr_fd("Error:\nInvalid file name\nTry ./so_long 'map.ber'", 2);
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	check_arg(argc, argv);
	int fd = open(argv[1], O_RDONLY);
	t_map map;
	t_player player;
	t_show show;
	map.show = &show;
	map.player = &player;
	map.split_map = read_map(fd, &map);
	all_check(&map, &player);
	map.show->mlx_ptr = mlx_init();
	map.len = ft_strlen(map.split_map[0]);
	map.show->win_ptr = mlx_new_window(map.show->mlx_ptr, 80 * map.len, 80 * map.lines, "So_long");
	map.keycode = 2;
	showmap(&map);
	map.check_c = 0;
	map.mov = 0;
	mlx_hook(map.show->win_ptr, 2, 0, move_map, &map);
	mlx_hook(map.show->win_ptr, 17, 0, (void *)exit, &map);

	mlx_loop(map.show->mlx_ptr);

	return (0);
}
