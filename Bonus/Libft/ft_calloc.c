/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:11:09 by olahmami          #+#    #+#             */
/*   Updated: 2022/12/25 18:35:42 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	if (size && count >= SIZE_MAX / size)
		return (0);
	pointer = malloc(count * size);
	if (!pointer)
		return (0);
	ft_bzero(pointer, count * size);
	return (pointer);
}
