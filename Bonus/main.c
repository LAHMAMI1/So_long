/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:57:25 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/10 23:11:43 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_arg(int argc, char *argv[])
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
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_map		m;
	t_player	player;
	t_show		s;

	check_arg(argc, argv);
	fd = open(argv[1], O_RDONLY);
	m.show = &s;
	m.player = &player;
	m.split_map = read_map(fd, &m);
	all_check(&m, &player);
	m.show->mlx_ptr = mlx_init();
	m.len = ft_strlen(m.split_map[0]);
	s.win_ptr = mlx_new_window(s.mlx_ptr, 80 * m.len, 80 * m.lines, "So_long");
	m.keycode = 2;
	showmap(&m);
	m.check_c = 0;
	m.mov = 0;
	mlx_loop_hook(m.show->mlx_ptr, move_m, &m);
	mlx_hook(m.show->win_ptr, 2, 0, move_map, &m);
	mlx_hook(m.show->win_ptr, 17, 0, (void *)exit, &m);
	mlx_loop(m.show->mlx_ptr);
	return (0);
}
