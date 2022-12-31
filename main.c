/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:57:25 by olahmami          #+#    #+#             */
/*   Updated: 2022/12/31 08:40:59 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
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

	int fd = open(argv[1], O_RDONLY);
	map map;
	player player;
	map.split_map = read_map(fd, &map);
	map.dup_map = map_dup(&map);
	onechar_map(&map, &player);
	flood_fill_p(player.pos_x, player.pos_y, map.dup_map);
	int i;
	i = 0;
	while (map.dup_map[i])
	{
		printf("%s\n",map.dup_map[i]);
		i++;
	}
	
	return (0);
}
