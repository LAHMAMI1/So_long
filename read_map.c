/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:28:12 by olahmami          #+#    #+#             */
/*   Updated: 2022/12/23 04:59:51 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *read_map(int fd)
{
	char *map;
	char *line;

	map = ft_calloc(1, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == '\0')
			break;
		map = ft_strjoin(map, line);
	}
	return (map);
}