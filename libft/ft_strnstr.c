/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:48:19 by jremy             #+#    #+#             */
/*   Updated: 2021/11/25 10:29:24 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t		find_len;
	size_t		i;
	const char	*p;

	i = 0;
	p = str;
	find_len = ft_strlen(find);
	if (*find == '\0')
		return ((char *)p);
	if (*p == '\0' || len == 0 || ft_strlen(str) < find_len)
		return (NULL);
	if (*find == '\0')
		return ((char *)p);
	while (*p != '\0' && i <= (len - find_len))
	{
		if (*p == *find)
		{
			if (ft_strncmp((char *)p, (char *)find, find_len) == 0)
				return ((char *)p);
		}
		p++;
		i++;
	}
	return (NULL);
}
