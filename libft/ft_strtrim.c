/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:42:42 by jremy             #+#    #+#             */
/*   Updated: 2021/11/24 18:07:51 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(unsigned char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		start;
	int		size;

	if (!s1 || !set)
		return (NULL);
	size = (int)ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_isinset(s1[start], set))
		start++;
	while ((size > start) && ft_isinset(s1[size - 1], set))
		size--;
	dst = ft_calloc(size - start + 1, sizeof(char));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, &s1[start], size - start);
	return (dst);
}
