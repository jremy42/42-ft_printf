/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:59:53 by jremy             #+#    #+#             */
/*   Updated: 2021/12/03 11:35:52 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pt, int value, size_t count)
{
	size_t		i;

	i = 0;
	while (i < count)
	{
		((unsigned char *)pt)[i] = value;
		i++;
	}
	return (pt);
}
