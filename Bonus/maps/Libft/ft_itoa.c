/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:42:44 by olahmami          #+#    #+#             */
/*   Updated: 2022/11/03 03:35:46 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(int n)
{
	int		digit;
	long	nb;

	nb = n;
	digit = 0;
	if (nb == 0)
		return (digit + 1);
	if (nb < 0)
	{
		nb *= -1;
		digit++;
	}
	while (nb != 0)
	{
		digit++;
		nb /= 10;
	}
	return (digit);
}

static char	*ft_min_itoa(char *p, long nb, int end)
{
	int		i;

	i = end - 1;
	if (nb == 0)
		p[0] = '0';
	if (nb < 0)
	{
		p[0] = '-';
		nb *= -1;
	}
	while (nb != 0)
	{
		p[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	p[end] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	char	*p;
	long	nb;
	int		end;

	nb = n;
	end = ft_count_digit(nb);
	p = (char *)malloc(end + 1);
	if (!p)
		return (0);
	return (ft_min_itoa(p, nb, end));
}
