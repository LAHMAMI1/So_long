/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 07:42:49 by olahmami          #+#    #+#             */
/*   Updated: 2022/12/31 08:12:13 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void all_check(map *map, player *player)
{
	if (composed_map(map) == 1 || onechar_map(map, player) == 1 || rectangular_map(map) == 1 || wall_map(map) == 1)
	{
		printf("False");
		exit(1);
	}
	else
		printf("True");
}
