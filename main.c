/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:57:25 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/02 07:01:33 by olahmami         ###   ########.fr       */
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
	map map;
	player player;
	map.split_map = read_map(fd, &map);
	all_check(&map, &player);
	showmap(&map);
	
	return (0);
}
