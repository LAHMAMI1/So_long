/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:28:12 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/07 20:20:55 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **read_map(int fd, t_map *map)
{
	char *line;

	map->str = ft_calloc(1, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == '\0')
			break;
		map->str = ft_strjoin(map->str, line);
	}
	free(line);
	map->split_map = ft_split(map->str, '\n');
	return (map->split_map);
}
