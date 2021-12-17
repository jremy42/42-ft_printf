/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:57:59 by jremy             #+#    #+#             */
/*   Updated: 2021/11/24 17:22:24 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int find)
{
	unsigned char	*s1;
	int				i;

	i = (int)ft_strlen(src);
	s1 = (unsigned char *)src;
	while (i >= 0)
	{
		if (s1[i] == (unsigned char)find)
			return ((char *)(s1 + i));
		i--;
	}
	return (NULL);
}
