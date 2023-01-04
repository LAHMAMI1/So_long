/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:28:12 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/04 01:20:47 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **read_map(int fd, t_map *map)
{
	char *str;
	char *line;

	str = ft_calloc(1, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == '\0')
			break;
		str = ft_strjoin(str, line);
	}
	map->split_map = ft_split(str, '\n');
	return (map->split_map);
}
