/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:28:12 by olahmami          #+#    #+#             */
/*   Updated: 2022/12/27 17:55:34 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **read_map(int fd)
{
	char *map;
	char *line;
	char **split_map;

	map = ft_calloc(1, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == '\0')
			break;
		map = ft_strjoin(map, line);
	}
	split_map = ft_split(map, '\n');
	return (split_map);
}
