/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:57:25 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/14 05:07:36 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_arg(int argc, char *argv[], t_map *map)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error:\nInvalid number of arg\nTry ./so_long 'map.ber'", 2);
		exit(1);
	}
	else if (name_map(argv[1]) == 1)
	{
		ft_putstr_fd("Error:\nInvalid file name\nTry ./so_long 'map.ber'", 2);
		exit(1);
	}
	map->fd = open(argv[1], O_RDONLY | O_DIRECTORY);
	if (map->fd > 0)
	{
		ft_putstr_fd("Error:\nIt's a directory", 2);
		exit(1);
	}
	map->fd = open(argv[1], O_RDONLY);
	if (map->fd < 0)
	{
		ft_putstr_fd("Error:\nMap file does not exist", 2);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_map		m;
	t_player	player;
	t_show		s;

	check_arg(argc, argv, &m);
	m.show = &s;
	m.player = &player;
	m.split_map = read_map(m.fd, &m);
	all_check(&m, &player);
	m.show->mlx_ptr = mlx_init();
	m.len = ft_strlen(m.split_map[0]);
	s.win_ptr = mlx_new_window(s.mlx_ptr, 70 * m.len, 70 * m.lines, "So_long");
	m.keycode = 2;
	showmap(&m);
	m.check_c = 0;
	m.mov = 0;
	mlx_loop_hook(m.show->mlx_ptr, animation, &m);
	mlx_hook(m.show->win_ptr, 2, 0, move_map, &m);
	mlx_hook(m.show->win_ptr, 17, 0, (void *)exit, &m);
	mlx_loop(m.show->mlx_ptr);
	return (0);
}
