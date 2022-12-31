/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:57:25 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/01 00:29:35 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr_fd("Error:\n", 2);
		perror("");
		exit(1);
	}
	if (name_map(argv[1]) == 1)
	{
		ft_putstr_fd("Error:\n", 2);
		perror("");
		exit(1);
	}

	int fd = open(argv[1], O_RDONLY);
	map map;

	int i;
	map.split_map = read_map(fd, &map);
	count_line(&map);
	map.dup_map = map_dup(&map);
	// i = 0;
	// while (map.dup_map[i])
	// {
	// 	printf("%s\n",map.dup_map[i]);
	// 	i++;
	// }
	player player;
	// printf("before\nx:%d y:%d\n",player.pos_x, player.pos_y);
	onechar_map(&map, &player);
	// printf("after\nx:%d y:%d",player.pos_x, player.pos_y);
	flood_fill_p(player.pos_x, player.pos_y, map.dup_map);
	printf("Flood p\n");
	i = 0;
	while (map.dup_map[i])
	{
		printf("%s\n", map.dup_map[i]);
		i++;
	}
	printf("\nFlood e\n");

	flood_fill_e(player.pos_x, player.pos_y, map.dup_map);
	i = 0;
	while (map.dup_map[i])
	{
		printf("%s\n", map.dup_map[i]);
		i++;
	}
	return (0);
}
