/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:41:23 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/08 10:49:51 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	j;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (j);
}

static char	**ft_free(char **p, size_t i)
{
	while (i >= 0)
	{
		free(p[i]);
		i--;
	}
	free(p);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;
	int		ii;
	int		jj;

	p = ft_calloc((ft_count(s, c) + 1), (sizeof(char *)));
	if (!p)
		return (0);
	i = 0;
	ii = 0;
	jj = 0;
	while (i < ft_count(s, c))
	{
		while (s[ii] == c)
			ii++;
		jj = ii;
		while (s[jj] && s[jj] != c)
			jj++;
		p[i] = ft_substr(s, ii, (jj - ii));
		if (!p[i])
			return (ft_free(p, i - 1));
		ii = jj;
		i++;
	}
	return (p);
}
