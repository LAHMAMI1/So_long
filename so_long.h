/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:54:09 by olahmami          #+#    #+#             */
/*   Updated: 2022/12/26 04:32:13 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "Libft/libft.h"

/*So_long*/
char **read_map(int fd);
int composed_map(char **split_map);
int oneChar_map(char **split_map);

#endif