/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 07:39:37 by olahmami          #+#    #+#             */
/*   Updated: 2022/12/31 07:40:21 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	name_map(char *name)
{
	if (ft_strncmp(name + (ft_strlen(name) - 4), ".ber", 4))
		return (1);
	return (0);
}